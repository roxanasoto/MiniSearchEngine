#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <sstream> 
#include <string>

#include "../include/parser.h"

using namespace std;

Parser::Parser(){}

bool Parser::LoadStopWords(string fileName)
{
    set<string>::iterator it;
    ifstream ifs;
    ifs.open(fileName);	
    //cout<<"Loading..."<<endl;
    if (ifs.is_open()){
        string word;
        while (!ifs.eof()) {
            word = "";
            ifs >> word;
            if(word.compare("") != 0)
                stopWordsList.insert(word);               
        }
        ifs.close();            
	}
    else{
        cout<<"ERROR opening the file" <<endl;
        return false;
    }		
	//cout<<"Total items: " <<stopWordsList.size() <<endl;
    
    /*for (it=stopWordsList.begin(); it!=stopWordsList.end(); ++it)
        cout << ' ' << *it;*/
	return true;
}

map<string, int> Parser::ParseFile(string _inputFile)
{    
    ifstream ifs;
    map<string, int> wordsList;
    map<string, int>::iterator it_ins = wordsList.begin();
    map<string, int>::iterator it_srch = wordsList.begin();
    ifs.open(_inputFile);    
    if (ifs.is_open()){
        bool is_title = true;
        string title, word, doc_id, line_content;		
		istringstream iss;
        getline(ifs, doc_id);                

        do {
            getline(ifs, line_content);
            is_title = false; //Second line is title, should weigth more
            iss.str(line_content);
		    while (iss >> word) {
			    PreProcessWord(word);
                //Save Word in list
			    if (!IsStopWord(word) && !word.empty()) {                    
                    it_srch = wordsList.find(word);
                    if (it_srch != wordsList.end()){                        
                         (*it_srch).second += 1;    
                    }
                    else{                        
                        wordsList.insert (it_ins, pair<string,int>(word,1));
                        it_ins++;                        
                    }
			    }
		    }
            iss.clear(); 
        }while(!ifs.eof());

        cout<<endl;
        ifs.close();            
	}
    else{
        cout<<"ERROR opening the file" <<endl;        
    }	

	ifs.close();   
    return wordsList; 
}

bool Parser::IsStopWord(string word){
    return stopWordsList.find(word) != stopWordsList.end();
}

bool Parser::IsMark(char sign) {
	return (sign < 0);
}

bool Parser::TakeOffMark(char &sign) {
	switch (sign) {
	case -95:
		sign = 'a';
		break;
	case -87:
		sign = 'e';
		break;
	case -83:
		sign = 'i';
		break;
	case -77:
		sign = 'o';
		break;
	case -70:
		sign = 'u';
		break;
	case -79:
		sign = 'n';
		break;
	default:
		return false;
	}
	return true;	 
}

void Parser::PreProcessWord(string &word)
{
    //cout<<"word in: "<<word <<" "<<word.length()<<endl;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
	for (int i = 0; i < word.length(); ++i) {
		if (IsMark(word[i])) {
            word.erase(i, 1);
			while (i < word.length() && !TakeOffMark(word[i])) {
				word.erase(i, 1);
			}
		} while (i < word.length() && !isalpha(word[i]) && !isdigit(word[i])) {
            word.erase(i, 1);
		}
	}
    //cout<<"word out: "<<word<<endl;	
}

Parser::~Parser()
{    
    //Clean WordList and stopWordList
}