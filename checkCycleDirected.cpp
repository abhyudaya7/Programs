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

bool isCyclicDFS(int V, vector<int> adj[]) {
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

bool isCyclicBFS(int N, vector<int> adj[]) {
    queue<int> q;
    vector<int> indegree(N, 0);

    // getting indegree for each node
    for (int i=0;i<N;i++) {
        for (auto it: adj[i]) {
            indegree[it]++;
        }
    }

    // adding nodes with indegree 0 to the queue
    for (int i=0;i<N;i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        count++;

        for (auto i:adj[node]) {
            indegree[i]--;
            if (indegree[i] == 0){
                q.push(i);
            }
        }
    }

    // checking wether cycle is there or not
    if (count == N)
        return false;
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
    if (isCyclicBFS(n,adj)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}