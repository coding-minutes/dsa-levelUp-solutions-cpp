#include<bits/stdc++.h>
using namespace std;
vector<int> stockSpan(vector<int> v) {
    int n = v.size();
	stack <int> s;
	vector<int> vec(n, 1);
	vec[0] = 1;
	s.push(0);
	for (int i = 1; i < n; i++) {
		while (!s.empty() and v[s.top()] <= v[i]) {
			s.pop();
		}
		if (!s.empty()) {
			vec[i] = i - s.top();
		} 
        else vec[i] = i + 1;
		s.push(i);
	}
	
    return vec;
}
