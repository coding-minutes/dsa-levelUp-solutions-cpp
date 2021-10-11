#include<bits/stdc++.h>
using namespace std;

class Node{
	
	public:
		char ch;
		bool isTerminal;
		unordered_map<char,Node*> children;
	
		Node(char ch){
			this->ch = ch;
			isTerminal = false;
		}
};

class Trie{
	Node*root;
public:
	Trie(){
		root = new Node('\0');
	}
	
	Node*getRoot(){
		return root;
	}
	
	void addWord(string s){
		
		Node*temp = root;
		for(char ch : s){
			if(temp->children.count(ch)==0){
				temp->children[ch] = new Node(ch);
			}
			temp = temp->children[ch];
		}
		temp->isTerminal = true;
		return;
	}
};

bool isSpecial(Trie t,Node*root, string s,int i,int cnt){
	//entire string is finished
	if(i==s.length()){
		cout<<"Count is "<<cnt + 1 <<"  and "<<root->ch<<endl;
		return root->isTerminal and (cnt + 1) >=2;
	}
	
	char ch = s[i];
	// trie is finished
	if(root->children.count(ch)==0){
		return false;
	}
	//bewkoofon vali mistake <---
	root = root->children[ch];
	//current node is terminal 
	if(root->isTerminal){
		bool remaining = isSpecial(t,t.getRoot(),s,i+1,cnt+1);
		if(remaining==true){
			return true;
		}
	}
	return isSpecial(t,root,s,i+1,cnt);
}


vector<string> googlyStrings(vector<string> strings) {
  // Write your code here.
	Trie t;
	
	for(auto str:strings){
		t.addWord(str);
	}
	vector<string> output = {};
	// for every word in the list of strings
	//check if it can be formed using atleast 2 words from the trie
	
	for(auto s : strings){
	  //cnt how many words are repeated to form a given string
		int cnt = 0;
		Node*temp = t.getRoot();
		if(isSpecial(t,temp,s,0,cnt)){
			output.push_back(s);
		}
	}
	
  return output;
}