#include <iostream>
#include <string.h>
#include <dirent.h>
#include <memory>
#include "include/parser.h"

using namespace std;

///*** Insert Words into a file
void InsertWords(WordList *wl)
{
	cout<<"Doc Id: "<<wl->docId<<endl;
	cout<<"Words: ";
	map<string,int>::iterator it;
	for (it=wl->wordList.begin(); it!=wl->wordList.end(); ++it){
    	cout << it->first << " => " << it->second << '\n';
	}
	cout<<endl;
}

///*** Get all files in directory "Docs"
vector<string> GetDirectoryFiles(const string& dir) 
{
  vector<string> files;
  shared_ptr<DIR> directory_ptr(opendir(dir.c_str()), [](DIR* dir){ dir && closedir(dir); });
  struct dirent *dirent_ptr;
  if (!directory_ptr) {
    cout << "Error opening : " << strerror(errno) << dir << endl;
    return files;
  }
 
  while ((dirent_ptr = readdir(directory_ptr.get())) != nullptr) {
    files.push_back(string(dirent_ptr->d_name));
  }
  return files;
}

int main()
{
	//Timing
	clock_t start, end;

	Parser *parser = new Parser();
	//Parser *parser = new Parser("WordList.txt");
	
	/*start = clock();
	parser->ReadRawData();	
	end = clock();
	cout<<"Reading Raw Data: "<<(end-start)/(double)CLOCKS_PER_SEC <<" seconds."<< endl;
	
	start = clock();
	parser->LoadStopWords("../stopWords.txt");
	end = clock();
	cout<<"Loading StopWords: "<<(end-start)/(double)CLOCKS_PER_SEC <<" seconds."<< endl;
	
	string directory_path = string("../../../../Docs");
  	vector<string> files = GetDirectoryFiles(directory_path);

	int currentDocId = 0;
	cout<<" - Amount of files: "<<files.size()<<endl;
	start = clock();	
	for(int i = 0; i<files.size(); ++i)
	{		
		if(files[i].compare(".") != 0 && files[i].compare("..") != 0){			
			currentDocId = stoi(files[i].substr(0,files[i].length() -4));	
			parser->ParseFile(directory_path+"/"+to_string(currentDocId)+".txt");
			//Ready for insert into the Tree
			//InsertWords(wordlist);
			//cout<<"File: "<<currentDocId <<" processed!"<<endl;			
		}		
	}
	end = clock();
	cout<<"Parsing files: "<<(end-start)/(double)CLOCKS_PER_SEC <<" seconds."<< endl;
	*/
	parser->LoadWordListFile();
	return 0;
}