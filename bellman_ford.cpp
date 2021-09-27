#include <bits/stdc++.h>
using namespace std; 

struct node {
    int u,v,wt;
    node(int parent, int child, int weight) {
        u = parent;
        v = child;
        wt = weight;
    }
}; 

int main() {
    int N,E;
    cin >> N >> E;
    vector<node> edges;


    int u,v,wt;
    for (int i=0;i<E;i++) {
        cin >> u >> v >> wt;
        edges.push_back(node(u,v,wt));
    }

    int src;
    cin >> src;
    
    vector<int> dist(N, INT_MAX);
    dist[src] = 0;

    for (int i=0;i<N-1;i++) {
        for (auto it:edges) {
            if (dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    bool negativeCycle = false;
    for (auto it: edges) {
        if (dist[it.u] + it.wt < dist[it.v]) {
            negativeCycle = true;
            break;
        }
    }

    if (!negativeCycle) {
        for (int i=0;i<N;i++) {
            cout << dist[i] << " ";
        }
    }
    else {
        cout << "Negative weight cycle detected\n";
    }

    return 0;
}