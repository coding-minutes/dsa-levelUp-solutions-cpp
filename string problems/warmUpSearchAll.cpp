#include<bits/stdc++.h>
using namespace std;

vector<int> stringSearch(string big,string small){
    
    vector<int> result;
    int index = big.find(small);
    while(index!=-1){
    	result.push_back(index);
    	index = big.find(small,index+1);
    }
    
    return result;
}
