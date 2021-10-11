#include<vector>
using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr){
    int n = arr.size();
      // Base case
    if (n == 1) {
        return {0};
    }
 
    int i, temp = 1;
 
    vector<int> prod(n,1);
    /* In this loop, temp variable contains product of
       elements on left side excluding arr[i] */
    for (i = 0; i < n; i++) {
        prod[i] = temp;
        temp *= arr[i];
    }
 
    /* Initialize temp to 1
    for product on right side */
    temp = 1;
 
    /* In this loop, temp variable contains product of
       elements on right side excluding arr[i] */
    for (i = n - 1; i >= 0; i--) {
        prod[i] *= temp;
        temp *= arr[i];
    }
    return prod;
}