#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsvis) {
    vis[node] = true;
    dfsvis[node] = true;

    for (auto i:adj[node]) {
        if (!vis[i]) {
            if (detectCycle(i, adj, vis, dfsvis)) return true;
        }
        else if (dfsvis[i]) return true;
    }

    dfsvis[node] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);
    vector<bool> dfsvis(V, false);

    for (int i=0;i<V;i++) {
        if (!vis[i]) {
            if (detectCycle(i, adj, vis, dfsvis))
                return true;
        }
    }
    return false;
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
    if (isCyclic(n,adj)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}