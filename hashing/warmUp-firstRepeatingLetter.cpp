#include<bits/stdc++.h>
using namespace std;


char firstRepeatChar(string input){
    
    unordered_map<char,bool> m;
    
    for(char s : input){
        if(m.count(s)==0){
            m[s] = 1;
        }
        else{
            return s;
        }
    }
    return '\0';
}