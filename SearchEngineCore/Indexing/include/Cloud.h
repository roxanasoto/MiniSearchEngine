#include<iostream>
#include "types.h"
#include <tuple> 
#include <set> 
#include <algorithm>
using namespace std;

class Cloud{
    int id_generate;
    vector<Row> rows;
public:
    Cloud();
    ~Cloud();
    int insert(set<tuple<int, int>, greater<tuple<int,int>>> nodo_tuplas);
    void insert(Row row);
    Row getRow(int index);
    int cloudSize();
    string string_ids_of_row(int index);
    void printCloud();
};