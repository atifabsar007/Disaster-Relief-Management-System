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

    cout << "\n🌐 CITY NETWORK (BFS)\n";
    cout << "---------------------------------\n";

    while(!q.empty()) {

        int u = q.front();
        q.pop();

        cout << "➡ " << city[u] << " is connected\n";

        for(auto edge : adj[u]) {
            int v = edge.first;

            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    cout << "---------------------------------\n";
}

/* 🌳 DFS */
void Graph::DFS(int start, vector<string> &city) {

    vector<bool> visited(V,false);
    stack<int> st;

    st.push(start);

    cout << "\n🌳 CITY NETWORK (DFS)\n";
    cout << "---------------------------------\n";

    while(!st.empty()) {

        int u = st.top();
        st.pop();

        if(!visited[u]) {

            visited[u] = true;
            cout << "➡ " << city[u] << endl;

            for(auto edge : adj[u]) {
                if(!visited[edge.first])
                    st.push(edge.first);
            }
        }
    }

    cout << "---------------------------------\n";
}

/* 🚑 DIJKSTRA */
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
