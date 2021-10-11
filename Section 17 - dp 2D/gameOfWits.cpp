#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
 int game(string s, int i, int j, int dp[105][105]){
     if(i+1==j){
        if(s[i]=='O' && s[j]=='O'){
            return 2;
        }
        else if(s[i]=='H'&& s[j]=='H'){
            return -3;
        }
        else{
            return -1;
        }
     }
     if(i==j){
         if(s[i]=='O'){
             return 1;
         }
         else{
             return -2;
         }
     }
     if(dp[i][j] != 0) return dp[i][j];
     

     if(s[i]=='H' && s[j]=='H'){
         return dp[i][j] = -1* (j-i+1) - 1;
     }
     else if(s[i]=='H' && s[j]=='O'){
         int op1=INT_MAX;
         if(s[j-1]=='H'){
             op1 = game(s,i,j-2,dp);
         }
         int op2 = game(s,i+1,j-1,dp);
        return dp[i][j] =  min(op1,op2);
     }
      else if(s[i]=='O' && s[j]=='H'){
         int op1=INT_MAX;
         if(s[i+1]=='H'){
             op1 = game(s,i+2,j,dp);
         }
         int op2 = game(s,i+1,j-1,dp);
        return dp[i][j] =  min(op1,op2);
     }
     else{
        
         if(s[i+1]=='O'){
             return j-i+1;
         }
         else if(s[j-1]=='O'){
             
             return j-i+1;
         }
         else {
             int op1=game(s,i+2,j,dp);
             int op2=game(s,i,j-2,dp);
             return dp[i][j] =  max(op1,op2);
         }
     }
 }
 pair<char,int> GameOfWits(string s){
    int n=s.length();
    int ans= game(s,0,n-1,dp);
         if(ans>0){
              return {'O',abs(ans)};
         }
         else
         return {'H',abs(ans)};
             
}