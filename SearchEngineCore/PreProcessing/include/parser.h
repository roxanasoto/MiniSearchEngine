#pragma once
#include <string>
#include <vector>
#include <set>
#include "wordlist.h"

using namespace std;

class Parser
{
	private:
		string id;
		string titulo;
		string body ;
		FILE *archivo;
		FILE *archivo_destino;
		set<string> stopWordsList;		
		string inputFile;		
		
	public:
		Parser();
		~Parser();

		bool ReadRawData();	
		bool LoadStopWords(string fileName);		
		map<string, int> ParseFile(string _inputFile);
		bool IsStopWord(string word);
		void PreProcessWord(string &word);
		bool IsMark(char sign);		
		bool TakeOffMark(char &sign);
};