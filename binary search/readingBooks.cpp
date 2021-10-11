#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &books,int m,int mid){
    
    int n = books.size();
    int cs = 0;
    int students = 1;
    
    for(int i = 0; i < n; i++){
        
        if(cs + books[i] > mid){
            students++;
            cs = books[i];
            
            if(students > m){
                return false;
            }
        }
        else{
            cs += books[i];
        }
    }
    
    return true;
}


int minPages(vector<int> books, int m){
    int n = books.size();
    //complete this code
    int end = 0;
    int start = 0;
    
    for(int b:books){
        end += b;
        start = max(start,b);
    }
    int result = INT_MAX;
    
    while(start<=end){
        int mid = (start + end)/2;
        if(isPossible(books,m,mid)){
            result = min(result,mid);
            end = mid - 1;
        }
        
        else{
            start = mid + 1;
        }
    }
    return result;
}