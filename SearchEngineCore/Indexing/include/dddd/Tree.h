#include "Node.h"
#include<iostream>
#include<string>
// #include <sstream>  
#include <fstream>
#include "types.h"
#include <vector>
// #include "wordlist.h"
// #include <stdio.h>
using namespace std;


class Tree{
private:
	Node* root;

public:
	Tree();
	~Tree();

	Node* GetRoot();
	bool SetRoot(Node*);
	bool InsertWord(string);
	int Prefix(string, string);
    Node* Find(string);
	Node* Find(Node*, string);
	void Split(Node*, int);
	bool Insert(string, int);
	
	Node* Insert(Node*,string , int);
	void TraversalSave(Node*, ofstream&);
	void Save(string);
	// void TraversalLoad(Node*&, ifstream&, istringstream&);
	void Load(string);
	void printTree();
	void printNode(Node*);

	// bool Insert(Word);
	bool indexDocument(vector<string> );
};