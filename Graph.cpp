//Graph.cpp

#include "Graph.h"

Graph::Graph(int v) {
    V = v;
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

/* 🌐 BFS */
void Graph::BFS(int start, vector<string> &city) {

    vector<bool> visited(V,false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "\n🌐 City Network (BFS Traversal)\n\n";

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        cout << "➡ " << city[u] << endl;

        for(auto edge : adj[u]) {
            int v = edge.first;
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

/* 🌳 DFS */
void Graph::DFSUtil(int v, vector<bool> &visited, vector<string> &city) {

    visited[v] = true;
    cout << "➡ " << city[v] << endl;

    for(auto edge : adj[v]) {
        if(!visited[edge.first]) {
            DFSUtil(edge.first, visited, city);
        }
    }
}

void Graph::DFS(int start, vector<string> &city) {

    vector<bool> visited(V,false);

    cout << "\n🌳 City Network (DFS Traversal)\n\n";
    DFSUtil(start, visited, city);
}

/* 🚑 Dijkstra */
void Graph::dijkstra(int src, vector<int> &dist) {

    dist.assign(V, INT_MAX);

    priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0,src});

    while(!pq.empty()) {

        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for(auto edge : adj[u]) {

            int v = edge.first;
            int w = edge.second;

            if(dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
}
