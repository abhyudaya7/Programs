#include <bits/stdc++.h>
using namespace std; 

struct node {
    int u,v,wt;
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt;
}

int findParent(int u, vector<int> parent) {
    if (u == parent[u]) 
        return u;
    return findParent(parent[u], parent);
}

void Union(int u, int v, vector<int> &parent, vector<int> &rank) {

    u = findParent(u, parent);
    v = findParent(v, parent);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[v] < rank[u]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

void kruskals(vector<node> edges, int N) {
    // implenting disjoint set data structure
    vector<int> parent(N);
    for (int i=0;i<N;i++) {
        parent[i] = i;
    }
    vector<int> rank(N,0);

    int cost = 0;
    for (auto it:edges) {
        if (findParent(it.v, parent) != findParent(it.u, parent)) {
            cost += it.wt;
            Union(it.u, it.v, parent, rank);
        }
    }

    cout << cost << endl;
}

int main() {
    int N,m;
    cin >> N >> m;
    vector<node> edges;

    for (int i=0;i<m;i++) {
        int u,v,wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u,v,wt));
    }

    sort(edges.begin(), edges.end(), comp);

    kruskals(edges,N);
    return 0;
}