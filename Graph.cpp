//Graph.cpp

#include "Graph.h"

Graph::Graph(int v) {
    V = v;
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

/* ---------------- BFS ---------------- */
void Graph::BFS(int start) {
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for(auto edge : adj[u]) {
            int v = edge.first;
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

/* ---------------- DFS ---------------- */
void Graph::DFSUtil(int v, vector<bool> &visited) {
    visited[v] = true;
    cout << v << " ";

    for(auto edge : adj[v]) {
        if(!visited[edge.first]) {
            DFSUtil(edge.first, visited);
        }
    }
}

void Graph::DFS(int start) {
    vector<bool> visited(V, false);
    cout << "DFS Traversal: ";
    DFSUtil(start, visited);
    cout << endl;
}

/* ---------------- DIJKSTRA ---------------- */
void Graph::dijkstra(int src, vector<int> &dist) {
    dist.assign(V, INT_MAX);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

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
