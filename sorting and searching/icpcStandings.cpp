#include<bits/stdc++.h>
using namespace std;

int badness(vector<pair<string,int> > teams){
    //Complete this function to return the min badness
    int n = teams.size();
    //create a count array init with 0
    vector<int> cnt(n+1,0);
    
    
    for(int i=0;i<n;i++){
        cnt[teams[i].second]++;
    }
    
    int pos = 1;
    int sum = 0;
    for(int i=1;i<=n;i++){
        while(cnt[i]){
            sum += abs(pos-i);
            cnt[i]--;
            pos++;
        }
    }
       
    return sum;
}