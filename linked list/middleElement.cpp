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

int getMid(node * head){
    //Complete this function to return kth last element
    node * fast = head->next;
    node * slow = head;
    
    while(fast and fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow->data;
}