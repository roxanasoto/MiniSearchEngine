#include "Node.h"
#include<iostream>
#include<string>
// #include <sstream>  
#include <fstream>
// #include "types.h"
#include <vector>
#include "../../PreProcessing/include/wordlist.h"
#include "Cloud.h"
#include <sstream>
using std::stringstream;
using namespace std;


class Tree{
private:
	Node* root;
	int idLastDoc;
	
	int contador;
	string residuo;
	int avance;
	bool miss=false;
	string missword;
	int distanceMax=4;
public:
Cloud* cloud;
	Tree();
	~Tree();

	Node* GetRoot();
	bool SetRoot(Node*);
	bool InsertWord(string);
	int Prefix(string, string);
    Node* Find(string);
	Node* Find(Node*, string);
	void Split(Node*, int, int freq,int idDoc);
	bool Insert(string key, int counter, int freq,int idDoc);
	
	Node* Insert(Node*,string key, int counter, int freq,int idDoc);
	void TraversalSave(Node*, ofstream&);
	void Save(string);
	void TraversalLoad(Node*&, ifstream&, istringstream&);
	void Load(string);
	void printTree();
	void printNode(Node*);

	// bool indexDocument(vector<string> );
	bool indexDocument(WordList* );
	string printIdsDocuments(Node* );
	void setIdLastDocument(int);
	void restarCounters();
	void restarCounters(Node*);
	set<tuple<int, int>, greater<tuple<int,int>>> search(string);
	bool search(vector<string>);
	void SaveCloud(string);
	void LoadCloud(string);
	void printCloud();
	vector<int> search_sentence(vector<string> keys);
	int distanceHamming(string key, string keynew);
	int searchPrefix(string key);/******************************************************* Add Roxana******************/
	void searchRecursive(string key, Node* rpta, vector<string> &suggestionsRec );/******************************************************* Add Roxana******************/
	void searchMRecursive(string key, Node* rpta, vector<string> &suggestionsRec );/******************************************************* Add Roxana******************/
	int searchMiss(string key);
	Node* FindM(Node* node, string key);
	// bool Insert(Word);
};