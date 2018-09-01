#include "../include/Node.h"

Node::Node() : counter(0) {
	this->child=NULL;
	this->slibing=NULL;
	this->documents=NULL;
	idx =-1;
	// idDoc=0;
}

Node::Node(string new_key, int set_lenght, int set_counter): 
        key(new_key), 
        length(set_lenght), 
        counter(set_counter) {
			this->child=NULL;
			this->slibing=NULL;
			this->documents=new vector<int>();
			idx =-1;
			// idDoc=0;
		};

Node::~Node() {}

// vector<int>*& Node::getIdsDocuments(){
// 	return this->documents;
// }
set<tuple<int, int>>::iterator Node::findTuple(int idDoc)
{       
    int count = 0;
	tuple<int, int> t = make_tuple(0, idDoc);
    // cout << "---" << endl;
    set<tuple<int, int>>::iterator it = find_if(tuples.begin(), tuples.end(), [&t](const tuple<int,int>& item) 
    {
        return get<1>(t) == get<1>(item);
    });

    // if(it!=tuples.end())
    //   cout << "found" << endl;
	return it;
}
void Node::addTuple(int freq, int idDoc){
	set<tuple<int, int>>::iterator it = findTuple(idDoc);
	if(it==tuples.end()){
		tuples.insert(make_tuple(freq, idDoc));
	}
    //   cout << "no se insertara" << endl;
	
}
bool Node::removeTuple(int freq,int idDoc){
	tuple<int, int> t = make_tuple(freq, idDoc);
	int count = 0;
    set<tuple<int, int>>::iterator it = find_if(tuples.begin(), tuples.end(), [&t](const tuple<int,int>& item) 
    {
        return get<1>(t) == get<1>(item);
    });

    if(it!=tuples.end()){
		cout << "found" << endl;
		tuples.erase(it);
		return true;
	}
	return false;
}

void Node::setTuples(set<tuple<int, int>, greater<tuple<int,int>> > tups){
	tuples.clear();
	tuples = tups;
}
set<tuple<int, int>, greater<tuple<int,int>>> Node::getTuples(){
	return this->tuples;
}

// void Node::addDocument(int w){
// 	documents->push_back(w);
// }
string & Node::GetKey() {
	return key;
}
// string Node::printDocuments(){
// 	string cad = "[";
// 	int size = documents->size();
// 	for(int i=0;i<size;i++){
// 		// cad = cad+"("+to_string((*documents)[i].id)+","+to_string((*documents)[i].freq)+")"+"-";
// 		cad = cad+to_string((*documents)[i])+",";
// 	}
// 	cad+="]";
// 	return cad;
// }
string Node::printTuples(){
	string cad = "[";
	int size = tuples.size();

	tuple<int, int> element;
    for (set<tuple<int, int>>::iterator i = tuples.begin(); i != tuples.end(); i++) 
    {
        element = *i;
		cad += "("+to_string(get<1>(element))+","+to_string(get<0>(element))+")";
        // cout<< get<0>(element) <<" - " << get<1>(element)<<endl;
    }
	cad+="]";
	return cad;
}
// void Node::cleanDocuments(){
// 	this->documents->clear();
// 	this->documents->resize(0);
// }
void Node::cleanTuples(){
	this->tuples.clear();
	// this->documents->resize(0);
}
int Node::getContador(){
	return counter;
}

bool Node::Setkey(string new_key) {
	key = new_key;
	return true;
}

int Node::GetLength() {
	return length;
}

bool Node::SetLength(int new_length) {
	length = new_length;
	return true;
}

int &Node::GetCounter() {
	return counter;
}

Node*& Node::Child() {
	return this->child;
}

Node*& Node::Brother() {
	return this->slibing;
}
int Node::noTuples(){
	return tuples.size();
}
// int Node::noDocuments(){
// 	return this->documents->size();
// }
// void Node::setFlacLeaf(char flac){
//     flacLeaf = flac;
// }
// char Node::getFlacLeaf(){
//     return flacLeaf;    
// }