#include<bits/stdc++.h>
using namespace std;


class Graph {

	list<int> *l;
	int V;

public:
	Graph(int V) {
		l = new list<int>[V];
	}

	void addEdge(int x, int y, bool directed = true) {
		l[x].push_back(y);

		if (!directed) {
			l[y].push_back(x);
		}
	}

	bool cycle_helper(int node, bool *visited, int parent) {

		visited[node] = true;

		for (auto nbr : l[node]) {
			//two cases
			if (!visited[nbr]) {
				//go and recursively visit the nbr
				bool cycle_mila = cycle_helper(nbr, visited, node);
				if (cycle_mila) {
					return true;
				}


			}
			//nbr is visited but nbr should not be equal to parent
			else if (nbr != parent) {
				return true;
			}

		}
		return false;

	}

	bool contains_cycle() {
		//Check for Cycle in Directed Graph
		bool *visited = new bool[V];
		for (int i = 0; i < V; i++) {
			visited[i] = false;
		}
		return cycle_helper(0, visited, -1);
	}
};

bool contains_cycle(int V,vector<pair<int,int> > edges){
    //Complete this method
    Graph g(V);
    for(auto edge : edges){
        g.addEdge(edge.first,edge.second);
    }
    return g.contains_cycle();
}