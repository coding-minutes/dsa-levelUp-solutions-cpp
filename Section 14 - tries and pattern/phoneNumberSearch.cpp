#include<bits/stdc++.h>
using namespace std;

string keypad[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
//words that can be found "IN" the phone number not necessarily EQUAL
//good problem, take unordered set to avoid duplicates

class Node{
	public:
	char ch;
	bool isTerminal;
	string s;
	unordered_map<char,Node*> children;
	
	Node(char ch){
		this->ch = ch;
		isTerminal = false;
		s = "";
	}
};


class Trie{
	public:
	Node *root;
	Trie(){
		root = new Node('\0');
	}
	void addWord(string word){
		Node* temp = root;
		
		for(int i=0;i<word.length();i++){
			char ch = word[i];
			if(temp->children.count(ch)==0){
				temp->children[ch] = new Node(ch);
			}
			temp = temp->children[ch];
		}
		temp->isTerminal = true;
		temp->s = word;
	}
};

//recursive algorithm will get the trie to prune uncessary branches
void validWords(Node *n,string num,int i,unordered_set<string> &outputs){
	//base case
	//if we reach a node	
	if(n->isTerminal){
			outputs.insert(n->s);
	}
	if(i==num.length()){
		return;
	}
		
	//otherwise
	int digit = num[i] - '0';

	//explore options from current node
	
	for(int j=0;j<keypad[digit].length();j++){
		
		char ch = keypad[digit][j];
		if(n->children.count(ch)!=0){
			validWords(n->children[ch],num,i+1,outputs);
		}
	}
	return;
}

vector<string> filterNames(string phoneNumber, vector<string> words) {
  // Write your code here.
	//add all words to the trie
	Trie t;
	for(auto w : words){
		t.addWord(w);
	}
	
	unordered_set<string> valid_words;
	
	for(auto i=0;i<phoneNumber.size();i++){
		validWords(t.root,phoneNumber,i,valid_words);
	}
	
  return vector<string>(valid_words.begin(),valid_words.end());
}