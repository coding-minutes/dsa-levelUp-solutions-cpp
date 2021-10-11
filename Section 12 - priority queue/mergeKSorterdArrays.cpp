#include<bits/stdc++.h>
using namespace std;


vector<int> mergeKArrays(vector<vector<int> > arrays){
    //logic  
  
    int k = arrays.size();
    //triplet -> element, array idx, element idx
    priority_queue< vector<int> , vector<vector<int> > , greater<vector<int> > > q;


    vector<int> output;

    //init the heap 
    for(int i=0;i<k;i++){
        int element = arrays[i][0];
        q.push({element,i,0});
    }

    //start popping & pushing more elements
    while(!q.empty()){

        auto top = q.top();
        q.pop();

        int element = top[0];
        int a_idx = top[1];
        int e_idx = top[2];


        output.push_back(element);

        if(e_idx + 1 < arrays[a_idx].size()){
            int next_element = arrays[a_idx][e_idx+1];
            q.push({next_element,a_idx,e_idx+1});
        }

    }

    return output;
}
