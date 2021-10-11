#include<vector>
#include<algorithm>
using namespace std;

//This is O(NLogN) Solution, O(N) Solution also exists
pair<int,int> subarraySorting(vector<int> a) {

	vector<int> b(a);
	sort(a.begin(),a.end());
	
	//do comparison
	int i = 0;
	int n = a.size();
	while(i<n and a[i]==b[i]){
		i++;
	}
	int j = a.size()-1;
	while(j>=0 and a[j]==b[j]){
		j--;
	}
	//already sorted
	if(i==a.size()){
			return {-1,-1};
	}
  return {i,j};
}