#include<bits/stdc++.h>
using namespace std;

void dfs (int node, vector<int>adj[], int visited[], vector<int>& ls){
    visited[node] = 1;
    ls.push_back(node);
    for (auto it : adj[node]){
        if (!visited[it]){
            dfs(it, adj, visited, ls);
        }
    }
}

vector<int> bfs ( int v, vector<int> adj[]){
    int visited[v] = {0};
    visited[0] =1 ;
    queue<int> q;
    q.push(0);
    
    vector<int> bfs_list ;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs_list.push_back(node);

        for(auto it : adj[node]){
            if (!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs_list;
}

vector<int> dfs_traverse (int v, vector<int>adj[], int start){
    int visited[v] = {0};
    visited[ start ] = 1;
    stack <int> s;
    s.push(0);
    vector<int> res;
    while(!s.empty()){
        int node = s.top();
        s.pop();
        res.push_back(node);

        for (auto it = adj[node].rbegin(); it != adj[node].rend(); ++it) {
            if (!visited[*it]) {
                visited[*it] = 1;
                s.push(*it);
            }
        }
    }

    return res;
}

vector<int> traversal(int v, vector<int>adj[]){
    int visited[v] = {0};
    int start = 0;
    vector<int> ls;

    dfs(start, adj, visited, ls);

    return ls;
}

int main(){

    int vertices, edges;
    cout<<"Enter no. of vertices: ";
    cin>>vertices;
    cout<<"Enter no of edges: ";
    cin>>edges;
    vector<int>adj[vertices];
    for (int i=0; i<edges; i++){
        int u, v;
        cin>>u >>v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<"DFS traversal: \n\n";
    vector<int> res = traversal(vertices, adj);
    for(int i=0; i< res.size(); i++){
        cout<<res[i] <<" ";
    }

    cout<<"\n\n";
    cout<<"BFS traversal: \n\n";
    vector<int> bfs_res = bfs(vertices, adj);
    for(int i=0; i< bfs_res.size(); i++){
        cout<<bfs_res[i] <<" ";
    }
    cout<<"\n\n";
    cout<<"DFS traversal2: \n\n";
    vector<int> res1 = dfs_traverse(vertices, adj, 0);
    for(int i=0; i< res1.size(); i++){
        cout<<res1[i] <<" ";
    }

}