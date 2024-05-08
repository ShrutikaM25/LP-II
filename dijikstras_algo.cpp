#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int v, vector<vector<int>>adj[], int s){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int>dist(v, INT_MAX);

    dist[s] = 0;
    // {distance, source}
    pq.push({0, s});

    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]){
            int adjNode = it[0];
            int edge_wt = it[1];

            if(distance + edge_wt < dist[adjNode]){
                dist[adjNode] = distance + edge_wt;
                pq.push({dist[adjNode], adjNode});

            }
        }
    }
    return dist;
}

int main(){
    int vertices, edges ;
    cout<<"Enter no. of vertices: ";
    cin>>vertices;
    cout<<"Enter no. of edges: ";
    cin>>edges;
    vector<vector<int>> adj[vertices] ;
    for (int i=0; i<edges; i++){
        int u,v,w;
        cin>>u >>v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source;
    cout<<"Start point: ";
    cin>>source;

    vector<int> result = dijkstra(vertices, adj, source);

    for (int i=0; i<result.size(); i++){
        cout<<"Vertex "<< i << " : "<<result[i]<<endl;

    }

}