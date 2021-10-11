#include<list>
#include<vector>
using namespace std;

class Graph {

	list<int> *l;
	int V;

public:
	Graph(int V) {
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int x, int y, bool directed = true) {
		l[x].push_back(y);

		if (!directed) {
			l[y].push_back(x);
		}
	}

	bool cycle_helper(int node, bool *visited, bool *stack) {

		//visit a node
		visited[node] = true;
		stack[node] = true;

		for (int nbr : l[node]) {
			//two cases
			if (stack[nbr] == true) {
				return true;
			}
			else if (visited[nbr] == false) {
				bool cycle_mila = cycle_helper(nbr, visited, stack);
				if (cycle_mila == true) {
					return true;
				}
			}

		}

		//leave a node
		stack[node] = false;
		return false;

	}

	bool contains_cycle() {
		//Check for Cycle in Directed Graph

		bool *visited = new bool[V];

		bool *stack = new bool[V];

		for (int i = 0; i < V; i++) {
			visited[i] = stack[i] = false;
		}
		return cycle_helper(0, visited, stack);
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