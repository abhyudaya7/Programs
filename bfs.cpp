#include <bits/stdc++.h>
using namespace std;

class Graph {
    int v,e;
    vector<vector<int>> adj;
    public:
    Graph(int v, int e);
    void bfs(int start);
    void newEdge(int start, int end);
};

Graph :: Graph(int v, int e){
    this->v = v;
    this->e = e;
    adj.assign(v, vector<int>(v,0));
}

void Graph :: newEdge(int start, int end) {
    adj[start][end] = 1;
    adj[end][start] = 1;
}

void Graph :: bfs(int start) {
    vector<bool> visited(v, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int vis;

    while(!q.empty()) {
        vis = q.front();
        cout << vis << " ";
        q.pop();
        for (int i = 0;i < v;i++) {
            if (adj[vis][i] == 1 and !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
	int v,e;
	v = 8;
    e = 9;

	Graph G(v,e);
	G.newEdge(0,1);
	G.newEdge(0,2);
	G.newEdge(1,3);
	G.newEdge(2,4);
    G.newEdge(3,4);
	G.newEdge(2,6);
	G.newEdge(6,7);
	G.newEdge(3,5);
	G.newEdge(5,4);

	G.bfs(0);
}