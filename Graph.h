// Graph.h

#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<pair<int,int>> adj[100];

    Graph(int v);

    void addEdge(int u, int v, int w);

    void BFS(int start, vector<string> &city);
    void DFSUtil(int v, vector<bool> &visited, vector<string> &city);
    void DFS(int start, vector<string> &city);

    void dijkstra(int src, vector<int> &dist);
};

#endif
