#include <bits/stdc++.h>
using namespace std;

void prims(int v, vector<vector<int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> visited(v, 0);
    // {weight, node}
    pq.push({0, 0});
    int sum = 0;

    vector<vector<int>> mst(v, vector<int>(v, 0));


    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;
        cout<<"SSM: "<< wt <<" "<<node <<endl;


        int MinEdge = INT_MAX;

        if (visited[node] == 1)
            continue;
        else {
            visited[node] = 1;
            sum += wt;
            cout<<"sum: "<<sum<<endl;
            int adjnode, ed_wt;
 
            for( auto edge: adj[node]){
                int adjNode = edge[0];
                int edge_wt = edge[1];
                // cout<<"edge wt: "<<edge_wt <<" adj node: "<<adjNode<<endl; 
                adjnode = adjNode;
                ed_wt = edge_wt;
            }
                if (ed_wt < MinEdge)
                 mst[node][adjnode] = mst[adjnode][node] = ed_wt;
        }
        // cout<<"Node: "<<node<<endl;
        for (auto it : adj[node]) {
            int adjNode = it[0];
            int edge_wt = it[1];
            
            // cout << "adj: "<<adjNode <<" ed wt: "<<edge_wt<<endl;
            if (!visited[adjNode] && edge_wt < MinEdge) {
                MinEdge = edge_wt;
                pq.push({edge_wt, adjNode});
                // cout<<"edge wt: "<<edge_wt <<" adj node: "<<adjNode<<endl;
            }
        }

    }

    cout << "Prim's Minimum Spanning Tree:\n";
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
                cout << mst[i][j] << " ";
        }
        cout<<endl;
    }

    cout << "\nOptimal cost: " << sum;
}

int main() {
    int vertices, edges;
    cout << "Enter no of vertices: ";
    cin >> vertices;
    cout << "\nEnter no of edges: ";
    cin >> edges;

    vector<vector<int>> adj[vertices];

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            bool connected = false;

            for (auto it : adj[i]) {
                if (it[0] == j) {
                    cout << it[1] << " ";
                    connected = true;
                    break;
                }
            }
            if (!connected)
                cout << "0" << " ";
        }
        cout << endl;
    }

    prims(vertices, adj);

    return 0;
}
