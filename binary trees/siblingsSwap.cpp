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


bool equal(Node * X, Node * Y){
    //Complete the Function
    if (X == Y) {
        return true;
    }
    return (X && Y) && (X->key == Y->key) &&
        ((equal(X->left, Y->left) && equal(X->right, Y->right)) ||
        (equal(X->right, Y->left) && equal(X->left, Y->right)));
    
}