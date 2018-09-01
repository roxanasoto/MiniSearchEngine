#pragma once
#include <string>
#include <vector>
#include <set>
#include <map>
// #pragma once
// #include "wordlist.h"

using namespace std;

class Parser
{
	private:
		set<string> stopWordsList;		
		string inputFile;		
		
	public:
		Parser();
		~Parser();
			
		bool LoadStopWords(string fileName);		
		map<string, int> ParseFile(string _inputFile);
		bool IsStopWord(string word);
		void PreProcessWord(string &word);
		bool IsMark(char sign);		
		bool TakeOffMark(char &sign);
};