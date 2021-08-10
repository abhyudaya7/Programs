#include <bits/stdc++.h>
using namespace std;

class Graph {
	int v;
	int e;
	// adjacency matrix
	int **adj;
public:
	Graph(int v,int e);
	void newEdge(int start, int e);
	void dfs(int start, vector<bool>& visited);
};

Graph :: Graph(int v,int e) {
	this->e = e;
	this->v = v;
	adj = new int*[v];
	for (int i=0;i<v;i++) {
		adj[i] = new int[v];
		for (int j=0;j<v;j++) {
			adj[i][j] = 0;
		}
	}
}

void Graph :: newEdge(int start, int end) {
	adj[start][end] = 1;
	adj[end][start] = 1;
}

void Graph :: dfs(int start, vector<bool>& visited) {
	cout << start << " ";
	visited[start] = true;
	for (int i=0;i<v;i++) {
		if (adj[start][i] = 1 and !visited[i]) 
			dfs(i, visited);
	}
}

int main() {
	int v,e;
	cin >> v >> e;

	Graph G(v,e);
	G.newEdge(0,1);
	G.newEdge(0,2);
	G.newEdge(1,3);
	G.newEdge(2,4);
	G.newEdge(2,6);
	G.newEdge(6,7);
	G.newEdge(3,5);
	G.newEdge(5,4);

	vector<bool> visited(v, false);
	G.dfs(0, visited);
}