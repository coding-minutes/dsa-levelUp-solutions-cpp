#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};


bool isPresent(Node * root,int key){
    //Complete this method
    if(root==NULL){
        return false;
    }
    if(root->key==key){
        return true;
    }
    if(root->key > key){
        return isPresent(root->left,key);
    }
    return isPresent(root->right,key);
    
}