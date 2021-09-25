#include <bits/stdc++.h>
using namespace std;

void prims(vector<pair<int,int> > adj[], int V) {
    vector<int> parent(V,-1);
    vector<int> weights(V,INT_MAX);
    vector<bool> mst(V,false);

    weights[0] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0,0});

    for (int i=0;i<V-1;i++) {
        // burte force 
        // int minimum = INT_MAX, u;
        // for (int v=0;v < V;v++) {
        //     if (mst[v] == false and weights[v] < minimum) {
        //         minimum = weights[v];
        //         u = v;
        //     }
        // }

        // optimized
        int u = pq.top().second;
        pq.pop();

        mst[u] = true;
        for (auto it:adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mst[v] == false and weight < weights[v]) {
                parent[v] = u;
                weights[v] = weight;
                pq.push({weights[v],v});    
            }
        }
    }
    int mstWeight = 0;
    for (int i=0;i<V;i++) {
        mstWeight += weights[i];
    }
    cout << mstWeight << endl;
    
}

int main() {
    int V,E;
    cin >> V >> E;
    vector<pair<int,int>> adj[V];

    int a,b,wt;
    for (int i=0;i<E;i++) {
        cin >> a >> b >> wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }

    prims(adj,V);
    return 0;
}