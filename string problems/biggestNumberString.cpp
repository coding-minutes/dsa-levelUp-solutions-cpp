#include<bits/stdc++.h>
using namespace std;

bool compare(string s1,string s2){
    return s1 + s2 > s2 + s1;
}

string concatenate(vector<int> numbers){
    vector<string> output;

    for(int no:numbers){
        output.push_back(to_string(no));
    }
    sort(output.begin(),output.end(),compare);

    string ans = "";
    for(string x:output){
        ans += x;
    }
    return ans;
}