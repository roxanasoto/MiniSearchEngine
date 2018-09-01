#pragma once
#include <string>
#include <map>

using namespace std;

class WordList
{
    public:    
        int docId;        
		map<string, int> wordList;

        WordList();
        ~WordList();
};