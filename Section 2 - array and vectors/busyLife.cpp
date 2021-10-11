#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> v1, pair<int,int> v2){
    return v1.second < v2.second;
}


int countActivites(vector<pair<int,int> > v){
    //Complete this method
    
    sort(v.begin(),v.end(),compare);
    int count = 1;
    int finish = v[0].second;
    
    for(int i=1;i<v.size();i++){
        if(v[i].first>=finish){
            count++;
            finish = v[i].second;
        }
    }
    return count;
}