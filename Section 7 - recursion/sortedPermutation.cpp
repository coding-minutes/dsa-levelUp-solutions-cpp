#include<bits/stdc++.h>
using namespace std;
vector<string> v;

void find_Permutations(char *inp, int i){
   if(inp[i]=='\0'){
      string str(inp);
      v.push_back(str);
      return;
   }
   for(int j=i; inp[j]!=0; j++){
        swap(inp[i],inp[j]);
        find_Permutations(inp,i+1);
        swap(inp[i],inp[j]);
   }

}

vector<string> findSortedPermutations(string s){
    v.clear();
    int n=s.length();
    char inp[n+1];
    for(int i=0; i<n; i++){
        inp[i]=s[i];
    }
    inp[n]='\0';
    find_Permutations(inp,0);
    
    set<string> st;
    for(int i=0; i<v.size(); i++){
        st.insert(v[i]);
    }
    v.clear();
    for(auto x:st){
        v.push_back(x);
    }
    return v;
}
