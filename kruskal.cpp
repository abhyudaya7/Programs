#include <bits/stdc++.h>
using namespace std;

class Graph {
    private:
        vector<pair<int, pair<int,int>>> G; // for graph
        vector<pair<int, pair<int,int>>> T; // for MST
        vector<int> parent;
        int V; // number of vertices in the graph
    public:
        Graph(int V);
        void newWieghtedEdge(int u, int v, int w);
        int find_set(int i);
        void union_set(int u, int v);
        void kruskal();
        void print();
};

Graph :: Graph(int V){
    parent.assign(V,0);
    
    for (int i=0; i<V;i++) {
        parent[i] = i;
    }

    G.clear();
    T.clear();
}

void Graph :: newWieghtedEdge(int u, int v, int w) {
    G.push_back(make_pair(w, make_pair(u,v)));
}

int Graph :: find_set(int i) {
    // if i is the parent of itself
    if (i == parent[i]) 
        return i;
    else 
    {
        return find_set(parent[i]);
    }
}


void Graph :: union_set(int u, int v) {
    parent[u] = parent[v];
}

void Graph :: kruskal() {
    int uRep, vRep;
    sort(G.begin(),G.end());

    for (int i=0;i<G.size();i++) {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);

        if (uRep != vRep) {
            T.push_back(G[i]); // adding edge to the tree
            union_set(uRep, vRep);
        }
    }
}

void Graph :: print() {
    cout << "Egde: " << " Weight\n";
    int sum = 0;

    for (int i=0;i<T.size();i++) {
        cout << T[i].second.first << "-" << T[i].second.second << " : " << T[i].first << "\n";
        sum += T[i].first;
    }
    cout << "Minimum cost via Kruskal is: " << sum << endl;
}

int main() {
    Graph g(6);
    g.newWieghtedEdge(0,1,1);
    g.newWieghtedEdge(0,2,3);
    g.newWieghtedEdge(1,2,4);
    g.newWieghtedEdge(1,3,11);
    g.newWieghtedEdge(1,5,10);
    g.newWieghtedEdge(2,4,12);
    g.newWieghtedEdge(2,5,5);
    g.newWieghtedEdge(4,5,2);
    g.newWieghtedEdge(3,5,6);

    g.kruskal();
    g.print();
    return 0;
}