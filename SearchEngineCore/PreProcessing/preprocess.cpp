#include <iostream>
#include <string.h>
#include <dirent.h>
#include <memory>
#include "include/parser.h"

using namespace std;

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
	Parser *parser = new Parser();
	WordList *wordlist = new WordList();
	parser->ReadRawData();	
	parser->LoadStopWords("../stopWords.txt");

	string directory_path = string("../../../../Docs");
  	vector<string> files = GetDirectoryFiles(directory_path);

	for(int i = 0; i<files.size(); ++i)
	{		
		if(files[i].compare(".") != 0 && files[i].compare("..") != 0){			
			wordlist->docId = stoi(files[i].substr(0,files[i].length() -4));	
			wordlist->wordList = parser->ParseFile(directory_path+"/"+to_string(wordlist->docId)+".txt");
			//Ready for insert into the Tree
			InsertWords(wordlist);
			wordlist->docId = 0;
			wordlist->wordList = {};			
		}		
	}
	return 0;
}