#include "etl.h"

using namespace std;
map<char, int> etl::transform(const map<int,vector<char>> &old){
    map<char, int> &new_data = *(new map<char, int>);
    for(pair<int, vector<char>> kv:old) {
        for(char c:kv.second){
            new_data[tolower(c)] = kv.first;
        }
    }
    return new_data;
}