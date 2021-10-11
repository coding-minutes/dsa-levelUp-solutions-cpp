#include<vector>
using namespace std;


vector<int> sortBalls(vector<int> a){
    //sort the balls in place
    int n = a.size();
    
    int s = 0;
    int e = n-1;
    int mid = 0;
    
    while(mid<=e){
        if(a[mid] == 0){
            swap(a[s++],a[mid++]);
        }
        else if(a[mid] == 1){
            mid++;
        }
        else{
            swap(a[mid],a[e--]);
        }
    }
    return a;
}