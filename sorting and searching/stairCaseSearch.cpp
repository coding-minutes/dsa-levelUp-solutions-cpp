#include<bits/stdc++.h>
using namespace std;


pair<int,int> search(int m, int n, vector<vector<int>> v, int k){
    int i=m-1;
    int j=0;
    while(j<n && i>=0){
        if(v[i][j]==k){
            break;
        }
        else if(v[i][j]<k){
            j++;
        }
        else{
            i--;
        }
    }
    pair<int,int> p={i,j};
    return p;
}