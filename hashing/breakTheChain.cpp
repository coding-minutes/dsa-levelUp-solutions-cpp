#include<bits/stdc++.h>
using namespace std;

class node{
public:  
  int data;
  node * next;
  
  node(int data){
      this->data = data;
  }
};


 node * breakChain(node * head){
     //Complete this method
     unordered_map<node* , bool> m;
     
     node * temp = head;
     node * prev = NULL;
     while(1){
         m[temp] = true;
         
         prev = temp;
         temp = temp->next;
         
         if(m[temp]){
             break;
         }
     }
     if(prev!=NULL){
         prev->next = NULL;
     }
     return head;
 }