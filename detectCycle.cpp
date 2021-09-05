#include <bits/stdc++.h>
using namespace std;

bool checkForCycle(int node, int parent, vector<int> adj[], vector<bool> &vis) {
    vis[node] = true;
    for (auto i: adj[node]) {
        if (!vis[i]) {
            if (checkForCycle(i, node, adj, vis))   
                return true;
        } else if (i != parent) 
                return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);
    for (int i=0;i < V;i++) {
        if (!vis[i]) {
            if (checkForCycle(i, -1, adj, vis))
                return true;
        }
    }
    return false;
}

int main() {
    int V,E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i=0;i < E;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (isCycle(V, adj)) {
        cout << "There is cycle\n";
    }
    else {
        cout << "No cycle\n";
    }
    return 0;
}

/* input: 
    5 5
    0 4
    1 2
    1 4
    2 3
    3 4
*/

/* Output: 
    There is cycle
*/
