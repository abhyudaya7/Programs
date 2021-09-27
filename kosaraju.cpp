#include <bits/stdc++.h>
using namespace std;

void getTopoDFS(int node, vector<bool> &vis, stack<int> &st, vector<int> adj[]) {
    vis[node] = true;
    for (auto it:adj[node]) {
        if (!vis[it]) {
            getTopoDFS(it, vis, st, adj);
        }
    }

    st.push(node);
}

void dfs(int node, vector<bool> &vis, vector<int> transpose[]) {
    cout << node << " ";
    vis[node] = true;
    for (auto it: transpose[node]) {
        if (!vis[it]) {
            dfs(it, vis, transpose);
        }
    }
}

int main() {
    int N,E;
    cin >> N >> E;
    vector<int> adj[N];

    int u,v;
    for (int i=0;i<E;i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> st; // to store topo sort
    vector<bool> vis(N, false);
    for (int i=0;i<N;i++) {
        if (!vis[i]) {
            getTopoDFS(i, vis, st, adj);
        }
    }

    vector<int> transpose[N]; // to store the transpose of the graph

    for (int i=0;i<N;i++) {
        vis[i] = false;
        for (auto it:adj[i]) {
            transpose[it].push_back(i);
        }
    }

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            dfs(node, vis, transpose);
            cout << "\n";
        }
    }
    
    return 0;
}