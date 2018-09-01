#include <iostream>
#include <dirent.h>
#include <cstring>
#include <memory>
#include "include/parser.h"
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

int main()
{
	Tree* trie = new Tree();
	Parser *parser = new Parser();
	WordList *wordlist = new WordList();
	// string directory_path = string("../../../DocsTest");
	// string directory_path = string("/Docs-mini");
	// vector<string> files = GetDirectoryFiles(directory_path);
  		  
	parser->LoadStopWords("../stopWords.txt");	
	
	int i=1;
	bool newDoc = true;	
	clock_t start,end;

	string persistence_tree = "persistence_tree.txt";
	string persistence_cloud = "persistence_cloud.txt";
	
	// delete trie;

cout<<"----test load---------"<<endl;
	Tree* trie2 = new Tree();
	clock_t start_l,end_l;
	start_l = clock();
	trie2->Load(persistence_tree);
	end_l = clock();
	cout<<"Total Time Processing (loading): "<<(end_l - start_l)/(double)CLOCKS_PER_SEC <<" seconds."<< endl;
	
// 	// cout<<"----printing trie2---------"<<endl;
// 	// trie2->printTree();

	cout<<"----probando load cloud---------"<<endl;
	trie2->LoadCloud(persistence_cloud);
	
	// trie2->printCloud();

// 	cout<<"----test busqueda(n palabras)---------"<<endl;
// 	vector<string> oracion; oracion.push_back("historia"); oracion.push_back("computacion");
// 	trie2->search_sentence(oracion);


	cout<<"----test busqueda(1 palabras)---------"<<endl;
	trie2->Find("nacimientos");




// clock_t start_search,end_search;
// start_search = clock();
// 	trie2->search("califato");
// end_search = clock();

// cout<<"Total Time Searching: "<<(end_search - start_search)/(double)CLOCKS_PER_SEC <<" seconds."<< endl;


// start_search = clock();
// 	trie2->search("nacimientos");
// end_search = clock();

// cout<<"Total Time Searching: "<<(end_search - start_search)/(double)CLOCKS_PER_SEC <<" seconds."<< endl;
	

	// trie.Insert("opera",1,8,5);
	// trie.printTree();

	// trie.Insert("ope",1,14,6);
	// trie.printTree();

	// trie.Insert("o",1,1,7);
	// trie.printTree();

	// trie.Insert("ombligo",1,5,3);
	// trie.Insert("ombligo",1,6,4);
	// trie.printTree();
	
	// trie.Insert("ombligos",1,1,7);
	// trie.printTree();
	
	// cout<<"----test busqueda(1 palabra)---------"<<endl;
	// trie.search("historia");
	// trie.search("cana");
	// trie.search("africa");
	// trie.search("david");
	// trie.search("himno");
	// trie.search("test");
	// 	cout<<"----test busqueda(n palabras)---------"<<endl;
	// 	vector<string> oracion; oracion.push_back("historia"); oracion.push_back("computacion");
	// trie.search(oracion);
	
	// trie.search("historia");
	
	// cout<<"----test busqueda(n palabras)---------"<<endl;
	// masive_search(&trie);

	// string entrada;
	// cin>>entrada;
	// cout<<"escribiste esto?: "<<entrada<<endl;

	

// 	wordlist->docId = i;	

	
// cout<<"---------------------------------"<<endl;
	// wordlist->docId = 0;
	// wordlist->wordList = {};
	// wordlist->wordList = parser->ParseFile("../Docs-mini/d2.txt");
	// printWordList(wordlist);
	// trie->indexDocument(wordlist);
	

	// trie.Insert("hermandad",1,3,1);
	// trie->printTree();

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