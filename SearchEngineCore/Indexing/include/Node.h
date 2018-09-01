#include<iostream>
#include<vector>
// #include "types.h"
#include <tuple> 
#include <set> 
#include <algorithm>
using namespace std;

class Node{

private:
	string key;
	int counter;
	int length;
	Node* child;
	Node* slibing;
	vector<int>* documents;
	
	set<tuple<int, int>, greater<tuple<int,int>> > tuples;

public:
int idx;
	Node();
	Node(string, int, int = 0);
	~Node();

	string& GetKey();
	bool Setkey(string);
	int GetLength();
	bool SetLength(int);
	int& GetCounter();
	Node*& Child();
	Node*& Brother();
	// vector<int>*& getIdsDocuments();
	// void addDocument(int);
	// string printDocuments();
	// void cleanDocuments();

	// int noDocuments();
	int noTuples();
	int getContador();
	void addTuple(int freq, int idDoc);
	void cleanTuples();
	string printTuples();
	void setTuples(set<tuple<int, int>, greater<tuple<int,int>> >);
	set<tuple<int, int>, greater<tuple<int,int>>> getTuples();
	bool removeTuple(int freq,int idDoc);
	set<tuple<int, int>>::iterator findTuple(int idDoc);
	// void setFlacLeaf(char);
	// char getFlacLeaf();

};