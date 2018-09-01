#include<iostream>
using namespace std;

class Node{

private:
	string key;
	int counter;
	int length;
	Node* child;
	Node* slibing;
	// char flacLeaf;

public:
	Node();
	Node(string, int, int = 0);
	~Node();

	string GetKey();
	bool Setkey(string);
	int GetLength();
	bool SetLength(int);
	int GetCounter();
	void setCounter(int);
	Node* Child();
	Node* Brother();
	void setChild(Node*);
	void setBroter(Node*);
	// void setFlacLeaf(char);
	// char getFlacLeaf();

};