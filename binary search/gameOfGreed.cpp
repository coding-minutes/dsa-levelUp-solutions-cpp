#include<bits/stdc++.h>
using namespace std;

bool divideAmongK(vector<int> arr,int n,int k,int limit){
    //return true if every partition gets atleast limit no of coins

        int cnt = 0;
        int current_sum = 0;
        
        for(int i=0;i<n;i++){
            if(current_sum + arr[i] >=limit){
                cnt +=1;
                current_sum = 0;
            }
            else{
                current_sum += arr[i];
            }
        } 
       
    return cnt>=k;
}

int getCoins(vector<int> arr,int k){
    //return the minimum number
    int n = arr.size();
    int e = 0;
    int s = 0;
    for(int i=0;i<n;i++){
        e += arr[i];
    }
    //mid
    int mid;
    int ans;
    //search range (s,e)
    while(s<=e){
         mid = (s+e)/2;
         
        bool isPossible = divideAmongK(arr,n,k,mid);

        if(isPossible){
            s = mid + 1;
            ans = mid;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}