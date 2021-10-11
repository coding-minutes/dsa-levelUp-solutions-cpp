#include<bits/stdc++.h>
using namespace std;


int min_bars_helper(string s,vector<string> words,int idx, unordered_set<string> &m){

	//base case
	if(s[idx]=='\0'){
		return 0;
	}

	//rec case
	int ans = INT_MAX;
	string current_string = "";

	for(int j=idx; s[j]!='\0';j++){
		current_string += s[j];

		//at every step you can whether this prefix is present in set 
		if(m.find(current_string)!=m.end()){
			int remaning_ans = min_bars_helper(s,words,j+1,m);
			if(remaning_ans!=-1){
				ans = min(ans, 1 + remaning_ans);

			}
		}
	}

	if(ans==INT_MAX){
		return -1;
	}
	return ans;
}



int min_bars(string s, vector<string> words, int n){

	unordered_set<string> m;

	for(string w:words){
		m.insert(w);
	}

	//recursive helper function 
	int output = min_bars_helper(s,words,0,m);
	return output - 1;
}