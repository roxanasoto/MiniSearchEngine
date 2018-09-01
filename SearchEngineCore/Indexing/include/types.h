#include<iostream>
#include<vector>
using namespace std;
const char leaf = '1';
const char noleaf = '0';
struct Word{
    int id;
    int freq;
};

struct Row{
    int id;
    vector<int> docs;
};