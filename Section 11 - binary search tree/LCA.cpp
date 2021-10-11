#include<bits/stdc++.h>
using namespace std;


class node {
public:
	int data;
	node*left;
	node*right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};


node* lca(node*root, int a, int b) {


	if (root == NULL) {
		return NULL;
	}

	if (root->data == a or root->data == b) {
		return root;
	}

	//search in left and right subtrees
	node * leftans = lca(root->left, a, b);
	node* rightans = lca(root->right, a, b);

	if (leftans != NULL and rightans != NULL) {
		return root;
	}

	if (leftans != NULL) {
		return leftans;
	}
	return rightans;
}