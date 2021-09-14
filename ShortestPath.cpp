#include <bits/stdc++.h>
using namespace std;


void BFS(int N, int src, vector<int> adj[]) {
    vector<int> dist(N, INT_MAX); // vector to store the distance of each node from source
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it:adj[node]) {
            if (dist[node] + 1 < dist[it]) {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    for (int i:dist) {
        cout << i << " ";
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i=0;i < m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS(n,0,adj);
    return 0;
}