#include<bits/stdc++.h>
using namespace std;

class Disjoint {
    vector<int> parent, size;
    vector<vector<int>> mst;

public:
    Disjoint(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        mst.resize(n, vector<int>(n, 0)); 
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void UnionbySize(int u, int v, int wt) {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
            mst[u][v] = mst[v][u] = wt; 
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
            mst[u][v] = mst[v][u] = wt; 
        }
    }

    vector<vector<int>> getMST() {
        return mst;
    }
};

void kruskal(int N, vector<vector<int>> adj[]) {

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < N; i++) {
        for (auto it : adj[i]) {
            int adjNode = it[0];
            int wt = it[1];
            int node = i;

            edges.push_back({ wt, {node, adjNode} });
        }
    }

    sort(edges.begin(), edges.end());
    Disjoint d(N);
    int mstWt = 0;
    for (auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (d.findUParent(u) != d.findUParent(v)) {
            mstWt += wt;

            d.UnionbySize(u, v, wt); 
        }
    }

    cout << "Kruskal Spanning tree: \n\n";

    auto mst = d.getMST(); 

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << mst[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n\nOptimal cost: " << mstWt;
}

int main() {
    int vertices, edges;
    cout << "Enter no of vertices: ";
    cin >> vertices;
    cout << "Enter no of edges: ";
    cin >> edges;
    vector<vector<int>> adj[vertices];

    for (int i = 0; i < edges; i++) {
        vector<int> t1, t2;
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            bool connected = false;
            for (auto edge : adj[i]) {
                if (edge[0] == j) {
                    cout << edge[1] << " ";
                    connected = true;
                    break;
                }
            }
            if (!connected)
                cout << "0 ";
        }
        cout << endl;
    }

    kruskal(vertices, adj);

    return 0;
}
