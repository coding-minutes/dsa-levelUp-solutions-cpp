#include <iostream>
#include<set>
#include<vector>
#include<climits>
using namespace std;

//dijkshtras
class Node{
    public:
        int x,y;
        int dist;

        Node(int x,int y,int dist){
            this->x = x;
            this->y = y;
            this->dist = dist;
        }

};

//comparator should return boolean value, indicating whether the element passed as first argument is considered to go before the second in the specific strict weak ordering 
class Compare{
    public:
    bool operator()(Node a,Node b){
        return a.dist <= b.dist;
    }

};

int shortest_path(vector<vector<int> > grid){
    
    //----------------/////
    int m = grid.size();
    int n = grid[0].size();
    int i = 0;
    int j = 0;
    
    vector<vector<int> > dist(m+1,vector<int>(n+1,INT_MAX));

    dist[i][j] = grid[0][0];
    set<Node,Compare> s;
    s.insert(Node(i,j,dist[0][0]));

    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};

    while(!s.empty()){
        //get the node that is having smallest dist
        auto it = s.begin();
        int cx = it->x;
        int cy = it->y;
        int cd = it->dist;
        s.erase(it);

        //update the neigbours of this node and push them in the set
        for(int k=0;k<4;k++){
            int nx = cx + dx[k];
            int ny = cy + dy[k];
            if(nx>=0 and nx<m and ny>=0 and ny<n and dist[nx][ny] > cd + grid[nx][ny]){
                //remove the old node from the set
                Node temp(nx,ny,dist[nx][ny]);
                if(s.find(temp)!=s.end()){
                    s.erase(s.find(temp));
                }
                //insert the new node in the set
                int nd = grid[nx][ny] + cd;
                dist[nx][ny] = nd;
                s.insert(Node(nx,ny,nd));
            }
        }

    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return dist[m-1][n-1];
}