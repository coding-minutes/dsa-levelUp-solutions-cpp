#include<vector>
#include<algorithm>
using namespace std;

class node{

public:
	int data;
	node*left;
	node*right;
	
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};


void printAtLevelK(vector<int> &v, node*root, int k){
	if(root==NULL){
		return;
	}
	if(k==0){
	    v.push_back(root->data);
		return;
	}
	printAtLevelK(v,root->left,k-1);
	printAtLevelK(v,root->right,k-1);
	return;
}


int printNodesAtDistanceK(vector<int> &v, node* root, node* target,int k){

	//base case
	if(root==NULL){
		return -1;
	}

	//reach the target node
	if(root==target){
		printAtLevelK(v,target,k);
		return 0;
	}


	//other case
	int DL = printNodesAtDistanceK(v,root->left,target,k);
	if(DL!=-1){

		//2 cases
		// Print the current node
		if(DL + 1 ==k){
			v.push_back(root->data);
		}
		// or print somenodes in the rightsubtree
		else{
			printAtLevelK(v,root->right,k-2-DL);
		}
		return 1 + DL;
	}
	int DR = printNodesAtDistanceK(v,root->right,target,k);
	if(DR!=-1){
		//2 cases
		//print current node
		if(DR + 1 ==k){
			v.push_back(root->data);
		}
		else{
			printAtLevelK(v,root->left,k-2-DR);
		}
		return 1 + DR;
	}
	return -1;
}

vector<int> nodesAtDistanceK(node *root, node *target, int k){
    //return a SORTED vector of the nodes
    
    vector<int> result;
    printNodesAtDistanceK(result, root, target,k);
    sort(result.begin(),result.end());
    return result;
    
}