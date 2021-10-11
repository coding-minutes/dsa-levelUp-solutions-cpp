#include<bits/stdc++.h>
using namespace std;

pair<bool,int> findPath(int m,int n, int i, int j, vector<vector<int>> v, bool mat[][100]){
    if(i==m-1 && j==n-1){
       
        pair<bool,int> p={true,0};
        return p;
    }
    if(i>=m || i<0 || j>=n || j<0 ){
        
        pair<bool,int> p={false,-1};
        return p;
    }
    else{
       
        mat[i][j]=true;
        pair<bool,int> res={false,-1};
        
       if(i<m-1 && v[i+1][j]==1 && mat[i+1][j]==false){
            pair<bool,int> p1=findPath(m,n,i+1,j,v,mat);
            if(p1.first){
                res.first=true;
                res.second=max(res.second,p1.second);
            }
       }
       if(j<n-1 && v[i][j+1]==1 && mat[i][j+1]==false){
            pair<bool,int> p2=findPath(m,n,i,j+1,v,mat);
            if(p2.first){
                res.first=true;
                res.second=max(res.second,p2.second);
            }
       }
       if(i>0 && v[i-1][j]==1 && mat[i-1][j]==false){
            pair<bool,int> p3=findPath(m,n,i-1,j,v,mat);
            if(p3.first){
                res.first=true;
                res.second=max(res.second,p3.second);
            }
       }
       if(j>0 && v[i][j-1]==1 && mat[i][j-1]==false){
           pair<bool,int> p4=findPath(m,n,i,j-1,v,mat);
           if(p4.first){
               res.first=true;
               res.second=max(res.second,p4.second);
           }
       }
       mat[i][j]=false;
       res.second+=1;
       return res;
    }
}


int findLongestPath(int m, int n, vector<vector<int>> v){
    bool mat[100][100]={{0}};
    
    pair<bool,int> p=findPath(m,n,0,0,v,mat);
    return p.second;
}
