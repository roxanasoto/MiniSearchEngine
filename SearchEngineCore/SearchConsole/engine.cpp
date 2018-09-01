#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <vector>
#include <dirent.h>
#include <memory>
#include <limits>

#include "../PreProcessing/include/parser.h"
using namespace std;

vector<int> listIds;            //** listIds >> List contains all Documents Ids where query matching 
int page = 0;                   //** page >> pagination 
map<int,string> optionsList;    //** optionsList >> lista de Coincidencias map<index, idDoc>
string searchQuery = "";        //** stores last query made
string sumaryResult = "";       //** stores last result gotten
Parser* parser = new Parser();  //** helper

///*** WARNING!! directory_path is important to exist!
const string directory_path = string("../../../../Docs");

void LoadIndex();
vector<int> GetDirectoryFiles(const string& dir);
void MakeSearch(vector<string>& queryWords);
void Search(bool flag);    
void ShowTenResults();
void ShowContent(int docId);
void ShowMenu(bool flag);

int main()
{        
    LoadIndex();
    cout<<"Presione ENTER...";
    Search(true);
    //ShowTenResults();
    //ShowMenu(true);
    return 0;
}

void LoadIndex()
{
    cout<<"Indexing...";
    usleep(1000000);
    cout<<" Done!"<<endl;
}

vector<int> GetDirectoryFiles(const string& dir) 
{
    vector<int> files;
    string file;
    int id;
    shared_ptr<DIR> directory_ptr(opendir(dir.c_str()), [](DIR* dir){ dir && closedir(dir); });
    struct dirent *dirent_ptr;
    if (!directory_ptr) {
        cout << "Directory not found!! Error opening : " << strerror(errno) << dir << endl;
        return files;
    }

    while ((dirent_ptr = readdir(directory_ptr.get())) != nullptr) {
        file = string(dirent_ptr->d_name);
        file = file.substr(0,file.length() -4);
        if(file.compare(".") != 0 && file.compare("..") != 0)
        {
            id = stoi(file);
            files.push_back(id);
        }
    }
    return files;
}

void MakeSearch(vector<string>& queryWords)
{
    listIds = GetDirectoryFiles(directory_path);
    //list.push_back(32449);
    /*list.push_back(2323);
    list.push_back(3123);
    list.push_back(4232);
    list.push_back(1235);
    list.push_back(6123);
    list.push_back(7123);
    list.push_back(1238);
    list.push_back(9131);
    list.push_back(101323);*/
    //usleep(1000000);
    //cout<<"Ids done!"<<endl;
}

void Search(bool flag){

    system(CLEAR);
    //Timing
    if(flag){
        searchQuery = "";
        sumaryResult = "";
        clock_t start, end;
        string query, word;        
        vector<string> querywords;
        istringstream iss;
        
        page = 0;
        optionsList = {};
        cin.ignore( numeric_limits<streamsize>::max(), '\n' );
        cout <<"\nBUSCAR: ";
        
        getline(cin, query);
        
        iss.str(query);
        
        while (iss >> word) {
            //cout<<"IN: "<<word <<endl;
            parser->PreProcessWord(word);
            //cout<<"OUT: "<<word;
            querywords.push_back(word);
        }
        cout<<"\n";
        iss.clear();
        start = clock();
        MakeSearch(querywords);
        end = clock();

        searchQuery = query;
        sumaryResult = "Cerca de " + to_string(listIds.size()) + " resultados ("+ 
                        to_string((end-start)/(double)CLOCKS_PER_SEC) +" seconds)";

        cout<<sumaryResult<<endl<<endl;
        cin.clear();
        ShowTenResults();
        ShowMenu(true);            
    }
    else{
        cout <<"\nBUSCAR: "<<searchQuery<<endl<<endl;
        cout <<sumaryResult<<endl<<endl;
    }

    //ShowTenResults();
    //ShowMenu();
}

void ShowTenResults(){
    ifstream ifs;
    optionsList = {};
    map<int,string>::iterator it_ins = optionsList.begin();    
    
    int index;
    cout<< "  [ID] TITULO DE DOCUMENTO"<<endl;
    for(int i = 1 ; i <= 10; ++i){
        index = (10*page)+i;
        string filepath = directory_path +"/"+to_string(listIds[index])+".txt"; 
        //cout<<path;
        ifs.open(filepath);

        cout<< "  ["<<index<<"]   ";
        if (ifs.is_open()){
            bool is_title = true;
            string word, doc_id, line_content;		            
            getline(ifs, doc_id);                
            if(doc_id.compare(" ") != 0){
                optionsList.insert(it_ins, pair<int,string>(index,doc_id));
                it_ins++;
                //do {
                    getline(ifs, line_content);            
                    cout<<line_content;
                    
                //}while(!ifs.eof());
            }
            cout<<endl;
            ifs.close();       
        }
        else{
            cout<<"File not found!"<<endl;
        }    
    }
    
}

void ShowContent(int docId)
{
    system(CLEAR);
    //cout<<"Show Content of "<< to_string(docId)<< endl;
    ifstream ifs;
    int index;
    //cout<< "  [ID] TITULO DE DOCUMENTO"<<endl;
    //for(int i = 1 ; i <= 10; ++i){
        //index = (10*page)+i;
        //string filepath = directory_path +"/"+to_string(docId)+".txt"; 
        string filepath = directory_path +"/20559.txt"; 
        //cout<<path;
        ifs.open(filepath);

        //cout<< "  ["<<index<<"]   ";
        
            if (ifs.is_open()){
                bool is_title = true;
                string word, doc_id, line_content;
                getline(ifs, doc_id); 
                istringstream iss;		            
                while(!ifs.eof()){                    
                    getline(ifs, line_content);  
                    iss.str(line_content);
                    if((line_content.compare(" ") != 0) && ((line_content.compare("") != 0))){
                        while(iss >> word){                    
                            cout<<word <<" ";
                        }
                        iss.clear();
                    }
                    cout<<endl;                    
                } 
                ifs.close();      
            }
            else{
                cout<<"File not found!"<<endl;
            }    
        
    //}
}

void ShowMenu(bool flag)
{   
    if(flag){ 
        char optionMenu;
        int optionDocIndex;
        cout<<endl;
        cout<<" >> [O] Ingresar opcion \n"
            <<" >> [S] Mostrar siguiente \n"
            <<" >> [A] Mostrar anterior \n"
            <<" >> [V] Volver a buscar \n"
            <<" >> [E] Salir "<<endl<<endl << " >> ";
        cin>> optionMenu;
        switch(optionMenu){
            case 'o':
            case 'O':
                cout <<"\nIngrese [ID] de documento: >> ";
                cin >> optionDocIndex; 
                ShowContent(optionDocIndex);
                ShowMenu(false);            
            break;

            case 's':
            case 'S':
                page++;
                Search(false);
                ShowTenResults();
                ShowMenu(true);            
            break;

            case 'a':
            case 'A':
                if(page > 0){
                    page--;
                    Search(false);
                    ShowTenResults(); 
                    ShowMenu(true);          
                }
                else{
                    Search(true);
                    //ShowTenResults(); 
                    //ShowMenu();  
                }
            break;
            
            case 'v':
            case 'V':
                Search(true);
                //ShowTenResults(); 
                //ShowMenu();  
            break;

            case 'e':
            case 'E':
                return;
            break;

            default:
                Search(true);
                //ShowTenResults(); 
                //ShowMenu();  
        }
    }
    else{
        char optionMenu;
        int optionDocIndex;
        cout<<endl;
        cout<<" >> [V] Volver "<<endl<<endl << " >> ";
        cin>> optionMenu;
        switch(optionMenu){            
            case 'v':
            case 'V':
                Search(false);
                ShowTenResults(); 
                ShowMenu(true);  
            break;

            default:
                Search(true);                
        }
    }
}
