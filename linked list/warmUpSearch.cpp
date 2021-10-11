#include<bits/stdc++.h>
using namespace std;


class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};


bool isPresent(node * head, int key){
    //Complete this function to return kth last element
    
    node * temp = head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }       
        temp = temp->next;
    }
    
    return false;
}