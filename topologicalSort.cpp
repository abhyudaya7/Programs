#include <bits/stdc++.h>
using namespace std;

void getTopoSortDFS(int node, vector<int> adj[], vector<bool> &vis, stack<int> &st) {
    vis[node] = true;

    for (auto i: adj[node]) {
        if (!vis[i]) {
            getTopoSortDFS(i, adj, vis, st);
        }
    }

    st.push(node);
}

vector<int> getTopoSortBFS(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);

    // getting the indegree of each node in the graph
    for (int i=0;i<V;i++) {
        for (auto it: adj[i]) {
            indegree[it]++;
        }
    }

    // adding nodes with zero indegree to the queue
    queue<int> q;
    for (int i=0;i<V;i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto i: adj[node]) {
            indegree[i]--;
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
    }
    return topo;
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> topo;
    vector<bool> vis(V, false);
    stack<int> st;

    for (int i=0;i<V;i++) {
        if (!vis[i]) {
            getTopoSortDFS(i, adj, vis, st);
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
    vector<int> topo = getTopoSortBFS(n,adj);
    for (auto i:topo)
        cout << i << " ";
    return 0;
}