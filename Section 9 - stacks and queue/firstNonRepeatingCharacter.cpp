#include<bits/stdc++.h>
using namespace std;


vector<char> FindFirstNonRepeatingCharacter(string s){
    queue<char> q;
    int freq[26]={0};
    vector<char> res;
    for(int i=0; i<s.length(); i++){
        q.push(s[i]);
        freq[s[i]-'a']++;
        while(!q.empty()){
            if(freq[q.front()-'a']>1){
                q.pop();
            }
            else{
                res.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            res.push_back('0');
        }
    }
    return res;
    
}