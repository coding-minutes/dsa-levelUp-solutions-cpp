#include<iostream>
#include <vector>
#include<climits>
using namespace std;

int palindromePartitioningMinCuts(string s) {
  
	// 2d grid
	int n = s.length();
	vector<vector<bool> > isPalin(n+1,vector<bool>(n,false));
	
	for(int i=0;i<n;i++){
		isPalin[i][i] = true;
	}
	
	//2d dp palindromic grid for helper
	// tell whether a string i...j is a palindrome or not
	for(int len=2;len<=n;len++){
		for(int i=0;i<=n-len;i++){
			//substring i to j
			int j = i + len - 1;
			if(len==2){
				isPalin[i][j] = (s[i]==s[j]);
			}
			else{
				isPalin[i][j] = (s[i]==s[j] and isPalin[i+1][j-1]);
			}
		}
	}
	
	//min cut logic
	vector<int> cuts(n+1,INT_MAX);
	
	for(int i=0;i<n;i++){
		if(isPalin[0][i]){
			cuts[i] = 0;
		}
		else{
			cuts[i]  = cuts[i-1] + 1;
			for(int j=1;j<i;j++){
				if(isPalin[j][i] and cuts[j-1] + 1 < cuts[i]){
					cuts[i] = cuts[j-1] + 1;
				}
			}
		}
	}
  return cuts[n-1];
}

int partitioning(string str)
{
    int ans = palindromePartitioningMinCuts(str);
    return ans;
}