#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<pair<int,int>> adj[], int src) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n, INT_MAX);

    dist[src] = 0;
    pq.push({0,src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it:adj[node]) {
            int next = it.first;
            int nextDist = it.second;

            if (dist[next] > d + nextDist) {
                dist[next] = d + nextDist;
                pq.push({dist[next], next});
            }
        }
    }

    return dist;
}

int main() {
    int n,m,src;
    cin >> n >> m;
    vector<pair<int,int>> adj[n];

    for (int i=0;i<m;i++) {
        int u,v,wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    cin >> src;

    vector<int> path = dijkstra(n,adj,src);
    for (int i:path){
        cout << i << " ";
    }
    return 0;
}