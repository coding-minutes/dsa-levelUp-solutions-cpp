#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


pair<int,int> minDifference(vector<int> a1,vector<int> a2){
    //Complete this method
    // Write your code here.
	sort(a2.begin(),a2.end());
	vector<int> result;
	//iterate over 1 and do binary search
	int p1,p2;
	
	int diff = INT_MAX;
	
	for(int x : a1){
			auto lb = lower_bound(a2.begin(),a2.end(),x) - a2.begin();

			if(lb>=1 and x - a2[lb-1] < diff){
					diff = x - a2[lb-1];
				  p2 = a2[lb-1];
				  p1 = x;
			}

		 if(lb!=a2.size() and a2[lb]-x < diff ){
			 		diff = a2[lb] - x;
			 		p1 = x;
			 		p2 = a2[lb];
		 }
	}
	
  return {p1,p2};
}