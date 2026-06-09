//main.cpp

#include <bits/stdc++.h>
using namespace std;

#include "Graph.h"
#include "Emergency.h"
#include "BST.h"
#include "LinkedList.h"
#include "Team.h"

int main() {

    cout << "===== DISASTER RELIEF SYSTEM =====\n\n";

    /* ---------------- GRAPH ---------------- */
    Graph g(6);

    g.addEdge(0,1,4);
    g.addEdge(0,2,2);
    g.addEdge(1,3,5);
    g.addEdge(2,3,8);
    g.addEdge(3,4,6);
    g.addEdge(4,5,3);

    /* ---------------- BFS & DFS ---------------- */
    g.BFS(0);
    g.DFS(0);

    /* ---------------- PRIORITY QUEUE ---------------- */
    priority_queue<Emergency> pq;

    pq.push({1, 3, 9});
    pq.push({2, 5, 4});
    pq.push({3, 2, 7});

    /* ---------------- BST ---------------- */
    BST tree;

    /* ---------------- LOG SYSTEM ---------------- */
    LinkedList log;

    cout << "\nProcessing Emergencies...\n\n";

    while(!pq.empty()) {

        Emergency e = pq.top();
        pq.pop();

        cout << "Emergency ID: " << e.id << endl;
        cout << "City: " << e.city << endl;
        cout << "Severity: " << e.severity << endl;

        tree.root = tree.insert(tree.root, e.severity, e.city);

        vector<int> dist;
        g.dijkstra(0, dist);

        cout << "Distance from HQ: " << dist[e.city] << endl;

        log.insert("Handled Emergency ID: " + to_string(e.id));

        cout << "-----------------------\n";
    }

    /* ---------------- BST OUTPUT ---------------- */
    cout << "\n📊 Disaster BST (Sorted by Severity):\n";
    tree.inorder(tree.root);

    /* ---------------- LOG OUTPUT ---------------- */
    cout << "\n📜 System Logs:\n";
    log.display();

    /* ---------------- SORTING EXAMPLE ---------------- */
    Team teams[3] = {{1,10},{2,5},{3,20}};

    sort(teams, teams+3, [](Team a, Team b){
        return a.distance < b.distance;
    });

    cout << "\n🚑 Sorted Teams by Distance:\n";
    for(auto t : teams) {
        cout << "Team " << t.id << " Distance: " << t.distance << endl;
    }

    return 0;
}
