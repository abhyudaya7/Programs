#include <bits/stdc++.h>
using namespace std;

void getTopoSort(int node, vector<int> adj[], vector<bool> &vis, stack<int> &st) {
    vis[node] = true;

    for (auto i: adj[node]) {
        if (!vis[i]) {
            getTopoSort(i, adj, vis, st);
        }
    }

    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> topo;
    vector<bool> vis(V, false);
    stack<int> st;

    for (int i=0;i<V;i++) {
        if (!vis[i]) {
            getTopoSort(i, adj, vis, st);
        }
    }

    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    
    return topo;
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
    vector<int> topo = topoSort(n,adj);
    for (auto i:topo)
        cout << i << " ";
    return 0;
}