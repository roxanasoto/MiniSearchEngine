#include <iostream>
#include <dirent.h>
#include <cstring>
#include <memory>
// #include "include/parser.h"
// #include "../PreProcessing/include/parser.h"
#include "include/Tree.h"

using namespace std;

void printWordList(WordList *wl)
{
	cout<<"Doc Id: "<<wl->docId<<endl;
	cout<<"Words: ";
	map<string,int>::iterator it;
	for (it=wl->wordList.begin(); it!=wl->wordList.end(); ++it){
    	cout << it->first << " => " << it->second << '\n';
	}
	cout<<endl;
}
void masive_search(Tree* trie){
	vector<string> ws;
	ws.push_back("14");
	ws.push_back("abril" );
	ws.push_back("actos");
	ws.push_back("alumbrara" );
	ws.push_back("americano" );
	ws.push_back("americas");
	ws.push_back("amistad" );
	ws.push_back("argentina" );
	ws.push_back("ason" );
	ws.push_back("bolivia" );
	ws.push_back("brasil" );
	ws.push_back("canada" );
	ws.push_back("cancion" );
	ws.push_back("cantado" );
	ws.push_back("canto" );
	ws.push_back("ceremonias" );
	ws.push_back("chile" );
	ws.push_back("colombia" );
	ws.push_back("colonial" );
	ws.push_back("conmemoracion"); 
	ws.push_back("continente" );
	ws.push_back("costa" );
	ws.push_back("domingo" );
	ws.push_back("dominicana"); 
	ws.push_back("ecuador" );
	ws.push_back("enlaces" );
	ws.push_back("eternamente"); 
	ws.push_back("externos" );
	ws.push_back("fuerza" );
	ws.push_back("gloriosamente" );
	ws.push_back("guatemala"); 
	ws.push_back("haiti" );
	ws.push_back("hermandad" );
	ws.push_back("hermanos"); 
	ws.push_back("himno" );
	ws.push_back("honduras" );
	ws.push_back("incluyen" );
	ws.push_back("lealtad" );
	ws.push_back("letra" );
	ws.push_back("libertad");
	ws.push_back("mexico" );
	ws.push_back("musica" );
	ws.push_back("nicaragua"); 
	ws.push_back("nombre" );
	ws.push_back("norteamerica"); 
	ws.push_back("oficiales" );
	ws.push_back("optimismo"); 
	ws.push_back("panama" );
	ws.push_back("paraguay" );
	ws.push_back("paz" );
	ws.push_back("peru" );
	ws.push_back("republica"); 
	ws.push_back("rica" );
	ws.push_back("rodolfo" );
	ws.push_back("salvador"); 
	ws.push_back("santo" );
	ws.push_back("sciamarella"); 
	ws.push_back("simbolo" );
	ws.push_back("soberanos"); 
	ws.push_back("tendra" );
	ws.push_back("unidos" );
	ws.push_back("uruguay" );
	ws.push_back("vecindad" );
	ws.push_back("venezuela" );
	ws.push_back("versiones");
	ws.push_back("vivir");
	ws.push_back("youtube");
	for(int i=0;i<ws.size();i++){
		cout<<"buscando: "<<ws[i]<<" = "; trie->search(ws[i]);
	}
	// trie->search(ws[1]);
}

vector<string> GetDirectoryFiles(const string& dir) 
{
  	vector<string> files;
  	shared_ptr<DIR> directory_ptr(opendir(dir.c_str()), [](DIR* dir){ dir && closedir(dir); });
  	struct dirent *dirent_ptr;
  	if (!directory_ptr) {
	    cout << "- Error opening : " << strerror(errno) << dir << endl;
    	return files;
  	}
 
  	while ((dirent_ptr = readdir(directory_ptr.get())) != nullptr) {
    	files.push_back(string(dirent_ptr->d_name));
  	}
  	return files;
}

vector<WordList*> wordsListVector;

void LoadWordListFile()
{
    cout<<"LoadWordListFile"<<endl;
    
    ifstream ifs;
    int count = 0;
    map<string, int> wordsList;
    ifs.open("../../../../WordList.txt");    
    if (ifs.is_open()){
        string docId, word, frecuency, line_content;				
        istringstream iss;

            while (!ifs.eof()){
                docId = "";  
                line_content = "";          
                map<string, int>::iterator it_ins = wordsList.begin();
                WordList* wordListObj = new WordList();
                getline(ifs, docId);
                if(docId.compare(" ") != 0 && docId.compare("") != 0){
                    getline(ifs, line_content, '/');            
                    iss.str(line_content);
                    while(iss >> word){                    
                        iss >> frecuency;
                        //cout<<"word: " <<word <<" frecuency: "<<frecuency<<endl;
                        wordsList.insert(it_ins, pair<string,int>(word,stoi(frecuency)));
                        it_ins++;                                                                
                    }
                    iss>>word;
                    wordListObj->docId = stoi(docId);
                    wordListObj->wordList = wordsList;
                    wordsListVector.push_back(wordListObj);
                    
                    //cout<<"Doc Id: "<<wordListObj->docId<<endl;
                    //cout<<"Amount of Words: "<<wordListObj->wordList.size()<<endl;
                    iss.clear();
                    wordsList = {};                    
                    // cout<<++count<<endl;
                }
            }        
	}
    else{
        cout<<"ERROR opening the file" <<endl;        
    }

    cout<<"N: "<<wordsListVector.size()<<endl;
}

void buscar_palbra(string palabra, Tree* trie){
	Node* n = trie->Find(palabra);
	if(n!=0){
		cout<<"id_word: "<<n->idx<<" frequencia ahora id: "<<n->GetCounter()<<endl;
		cout<<"numero de docs: "<<trie->cloud->getRow(n->GetCounter()-1).docs.size()<<endl;
		cout<<"documentos: "<<trie->cloud->string_ids_of_row(n->GetCounter()-1)<<endl;
	}
}
void buscar_oracion(vector<string> oracion, Tree* trie){
	vector<int> documents = trie->search_sentence(oracion);

	// Node* n = trie->Find(palabra);
	// if(n!=0){
	// 	cout<<"id_word: "<<n->idx<<" frequencia ahora id: "<<n->GetCounter()<<endl;
	// 	cout<<"numero de docs: "<<trie->cloud->getRow(n->GetCounter()-1).docs.size()<<endl;
	// 	cout<<"documentos: "<<trie->cloud->string_ids_of_row(n->GetCounter()-1)<<endl;
	// }
}
void comprobar(Tree* trie, string str, int n_docs){
	 map<string,int>::iterator it;
	 int count=0;
	for(int i=0;i< n_docs;i++){
		it = wordsListVector[i]->wordList.find(str);
		if(it!=wordsListVector[i]->wordList.end()){
			count++;
			cout<<"docs de "<<str<<": " <<wordsListVector[i]->docId<<endl;
		}
	}
		cout<<"count: "<<count<<endl;
}
int main()
{
// 	Tree* trie = new Tree();
// 	LoadWordListFile();
// 	clock_t start,end;
// 	int n_docs = wordsListVector.size();

// 	// comprobar(trie,"nacimientos",n_docs);
// 	start = clock();
// 	for(int i=0;i< n_docs;i++){
// 		trie->indexDocument(wordsListVector[i]);
// 		cout<<"doc "<<i+1<<" de "<<n_docs<<endl;
// 	}
// 	end = clock();
// 	cout<<"Total Time Processing (loading): "<<(end - start)/(double)CLOCKS_PER_SEC <<" seconds."<< endl;

	string persistence_tree = "persistence_tree.txt";
	string persistence_cloud = "persistence_cloud.txt";
// // //----------------------------------- asignar id a cada palabra
// trie->setIds(); //verifica si el contador es >0 y guarda el id en el campo idx del nodo;

// cout<<"-------------persistiendo--------------"<<endl;
// clock_t start_save,end_save;
// start_save = clock();
// 	trie->Save(persistence_tree);
// end_save = clock();
// cout<<"Total Time Saving: "<<(end_save - start_save)/(double)CLOCKS_PER_SEC <<" seconds."<< endl;

// cout<<"-------------buscando--------------"<<endl;
// buscar_palbra("nacimientos",trie);


cout<<"----test load---------"<<endl;
	Tree* trie2 = new Tree();
	clock_t start_l,end_l;
	start_l = clock();
	trie2->Load(persistence_tree); //se cargara el id en counter-???
	end_l = clock();
	cout<<"Total Time Processing (loading): "<<(end_l - start_l)/(double)CLOCKS_PER_SEC <<" seconds."<< endl;


// // 	cout<<"total de palabras indexadas: "<<trie2->contador<<endl;

	//-------------------------Cloud cargar palbras de documentos
// 	LoadWordListFile();
// // // 	//---------------buscar palabras en arbol para asociar documentos a palabras
// 	 clock_t start,end;
// 	int n_docs = wordsListVector.size();
// 	int n_words = trie2->countWords(); //1367397
// 	cout<<"no tottal words: "<<n_words<<endl;
// 	trie2->cloud->resizeCloud(trie2->contador);
// 	cout<<"contador del trie: "<<trie2->contador<<endl;
// 	start = clock();
// 	for(int i=0;i< n_docs;i++){
// 		trie2->buildCloud(wordsListVector[i]);
// 		cout<<" Cloud->doc "<<i+1<<" de "<<n_docs<<endl;
// 	}
// 	end = clock();
// 	cout<<"Total Time Cloud (building): "<<(end - start)/(double)CLOCKS_PER_SEC <<" seconds."<< endl;
// // // // ----------------------------------ordenar los docs por frecuencia;
// cout<<"sorting Cloud"<<endl;
// trie2->cloud->sort_by_frequency();
	
// // // ----------------------------------persistir cloud;	
// 	cout<<"persistiendo Cloud"<<endl;
// start = clock();
// 	trie2->SaveCloud(persistence_cloud);
// end = clock();
// cout<<"Total Time Cloud (saving): "<<(end - start)/(double)CLOCKS_PER_SEC <<" seconds."<< endl;
	
	cout<<"-----------------------------------------probando load cloud---------"<<endl;
	trie2->LoadCloud(persistence_cloud);
	
	buscar_palbra("nacimiintos",trie2);
	// vector<string>
	// buscar_osracion();
	
	
	
	
	// trie2->printTree();
// cout<<"total de palabras indexadas: "<<trie2->contador<<endl;

	// cout<<"----test busqueda(1 palabras)---------"<<endl;
	// Node* res =trie2->Find("nacimientos");	
	// cout<<"se encontro: "<<res->GetCounter()<<" resultados de: "<<res->GetKey()<<endl;

	// Node* res2 =trie2->Find("nacimiento");	
	// cout<<"se encontro: "<<res2->GetCounter()<<" resultados de: "<<res2->GetKey()<<endl;


	//---------------------------------------------------------------------------------------------
	// Tree* trie = new Tree();
	// Parser *parser = new Parser();
	// WordList *wordlist = new WordList();


	// string directory_path = string("../../../DocsTest");
	// string directory_path = string("/Docs-mini");
// 	// vector<string> files = GetDirectoryFiles(directory_path);
  		  
	// parser->LoadStopWords("../stopWords.txt");	
	// wordlist->docId = 0;
	// wordlist->wordList = {};
	// wordlist->wordList = parser->ParseFile("../Docs-mini/d2.txt");
	// printWordList(wordlist);
	// trie->indexDocument(wordlist);
	
	// trie->printTree();

	
// 	int i=1;
// 	bool newDoc = true;	
// 	clock_t start,end;


	
// 	// delete trie;


	
// // 	// cout<<"----printing trie2---------"<<endl;
// // 	// trie2->printTree();


	
// 	// trie2->printCloud();

// // 	cout<<"----test busqueda(n palabras)---------"<<endl;
// // 	vector<string> oracion; oracion.push_back("historia"); oracion.push_back("computacion");
// // 	trie2->search_sentence(oracion);


// 	cout<<"----test busqueda(1 palabras)---------"<<endl;
// 	trie2->Find("nacimientos");
//-------------------------------------------------------------------------------------------------------------------------------------------



// clock_t start_search,end_search;
// start_search = clock();
// 	trie2->search("califato");
// end_search = clock();

// cout<<"Total Time Searching: "<<(end_search - start_search)/(double)CLOCKS_PER_SEC <<" seconds."<< endl;


// start_search = clock();
// 	trie2->search("nacimientos");
// end_search = clock();

// cout<<"Total Time Searching: "<<(end_search - start_search)/(double)CLOCKS_PER_SEC <<" seconds."<< endl;

	

	

// 	wordlist->docId = i;	

	
// cout<<"---------------------------------"<<endl;
	// wordlist->docId = 0;
	// wordlist->wordList = {};
	// wordlist->wordList = parser->ParseFile("../Docs-mini/d2.txt");
	// // printWordList(wordlist);
	// // trie->indexDocument(wordlist);
	
	// // trie->printTree();

	// // trie.Insert("himno",1,2,1);
	// // trie.printTree();

	// trie.Insert("himno",1,9,2);
	// trie.printTree();
	// trie.Insert("hermano",1,7,3);
	// trie.printTree();
	// trie.Insert("h",1,6,3);
	// trie.printTree();
	// trie.Insert("himno",1,1,4);
	// trie.printTree();
	// trie.Insert("honesto",1,1);
	// trie.printTree();
	// trie.Insert("himno",1,1);
	// trie.printTree();


	// trie.setIdLastDocument(1);
	// trie.restarCounters();
	// trie.Insert("himno",1,2);
	// trie.printTree();
	// trie.Insert("himno",1,2);
	// trie.printTree();
	

	return 0;
}