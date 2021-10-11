#include <bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<int> v1, vector<int> v2)
{
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<int> v;
    unordered_map<int, bool> map;

    for(auto x : v1) 
        map[x] = true;

    for(auto x : v2)
    {
        if(map[x] == true)
            v.push_back(x);
    }

    return v;
}
