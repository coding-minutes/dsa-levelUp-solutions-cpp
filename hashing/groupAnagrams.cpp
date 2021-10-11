#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> strs)
{
    vector<vector<string>> res;
    unordered_map<string, int> map;
    
    //sort each string, and make it the key. 
    for(int i=0; i<strs.size(); i++)
    {
        string key = strs[i];
        sort(key.begin(), key.end());
        if(map.find(key)!=map.end())
        {
            //key is in the map: find the entrance in the res and push
            int location = map[key];
            res[location].push_back(strs[i]);
        }
        else
        {
            //key is not in the map: make new entrance in the res, and store its location in the map
            vector<string> temp(1, strs[i]);
            res.push_back(temp);
            
            int location = res.size()-1;
            map[key] = location;                
        }
    }
    return res;
}