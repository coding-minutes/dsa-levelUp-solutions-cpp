#include<bits/stdc++.h>
using namespace std;

//Note : Don't Edit the class structure, only update the push method
class MedianHandler{
public:
    float median;
    
    priority_queue<int,vector<int>, greater<int> > right; 
	priority_queue<int> left; //max heap
    
    void push(int number){
        //Complete this method to update median after every insertion 
        if(left.empty() and right.empty()){
			median = number;
			left.push(number);
		}
		
		else if(left.size()==right.size()){
			if(number <= median){
				left.push(number);
				median = left.top();
			}
			else{
				right.push(number);
				median = right.top();
			}
		}
		else if(left.size()>right.size()){
			
			if(number <= median){
				right.push(left.top());
				left.pop();
				left.push(number);
			}
			else{
				right.push(number);
			}
			median = (left.top() + right.top())/2.0;
		}
		else{
			if(number > median){
				left.push(right.top());
				right.pop();
				right.push(number);
			}
			else{
				left.push(number);
			}
			median = (left.top() + right.top())/2.0;
		}
        
    }
    float getMedian(){
        //Should return the median in O(1) time
        return median;
    }
};