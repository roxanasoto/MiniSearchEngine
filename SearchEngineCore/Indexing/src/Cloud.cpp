#include "../include/Cloud.h"

Cloud::Cloud():id_generate(0){}

Cloud::~Cloud(){}

int Cloud::insert(set<tuple<int, int>, greater<tuple<int,int>>> nodo_tuplas){
    if(nodo_tuplas.size()>0){
        tuple<int, int> element;
        id_generate++;
        Row row;
        for (set<tuple<int, int>>::iterator i = nodo_tuplas.begin(); i != nodo_tuplas.end(); i++) 
        {
            element = *i;
            row.id = id_generate;
            row.docs.push_back(get<1>(element));
        }
        rows.push_back(row);
        // cout<< "size del row ids: " <<" - " << get<1>(element)<<endl;
        return id_generate;
    }
    return -1;
}
void Cloud::insert(Row row){
    rows.push_back(row);
}
Row Cloud::getRow(int index){
    return rows[index];
}
int Cloud::cloudSize(){
    return rows.size();
}
string Cloud::string_ids_of_row(int index){
    string cad;
    int size_ids = rows[index].docs.size();
    // cout<<"size de ids: "<<size_ids<<endl;
    for(int i=0;i<size_ids;i++){
        cad = cad + to_string(rows[index].docs[i]);
        if(i == size_ids-1){
           cad+="\n";
        }
        else{
            cad+=" ";
        }
    }
    // cad +="\n";
    return cad;
}
void Cloud::printCloud(){
    for(int i =0;i<rows.size();i++){
        cout<<"id: "<<rows[i].id<<" docs: "<<string_ids_of_row(i);
    }
}
