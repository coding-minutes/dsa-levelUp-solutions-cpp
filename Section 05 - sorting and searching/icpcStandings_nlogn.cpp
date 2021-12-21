#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string,int>a, pair<string,int> b){
    return a.second < b.second;
}

int badness(vector<pair<string,int> > teams){
    //Complete this function to return the min badness
    sort(teams.begin(), teams.end(), compare);
    int cnt = 0;
    for(int i = 0; i < teams.size(); i++){
        int j = i+1;
        cnt += abs(teams[i].second-j);
    }
    return cnt;
}