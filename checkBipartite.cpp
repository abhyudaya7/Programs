#include <bits/stdc++.h>
using namespace std;

bool bipartiteBFS(int start, vector<int> adj[], vector<int> &color) {
    queue<int> q;
    q.push(start);
    color[start] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto i: adj[node]) {
            if (color[i] == -1) {
                color[i] = 1 - color[node];
                q.push(i);
            }
            else if (color[i] == color[node]) 
                return false;
        }
    }
    return true;
}

bool bipartiteDFS(int start, vector<int> adj[], vector<int> &color) {
    if (color[start] == -1)
        color[start] = 0;
    
    for (auto i: adj[start]) {
        if (color[i] == -1) {
            color[i] = 1 - color[start];
            if (!bipartiteDFS(i, adj, color)) {
                return false;
            }
        }
        else if (color[i] == color[start]) 
            return false;
    }
    return true;
}

bool checkForBipartite(vector<int> adj[], int n) {
    vector<int> color(n, -1);
    for (int i=0;i<n;i++) {
        if (color[i] == -1) {
            if (!bipartiteDFS(i, adj, color)) 
                return false;
        }
    }
    return true;
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
    if (checkForBipartite(adj,n)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}