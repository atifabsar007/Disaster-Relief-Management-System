#include <bits/stdc++.h>
using namespace std;

#include "Graph.h"
#include "Emergency.h"
#include "BST.h"
#include "LinkedList.h"

Graph g(6);
priority_queue<Emergency> pq;
BST tree;
LinkedList logSystem;

void showMenu() {
    cout << "\n=====================================\n";
    cout << "   DISASTER RELIEF MANAGEMENT SYSTEM\n";
    cout << "=====================================\n";
    cout << "1. View City Network (BFS)\n";
    cout << "2. Add Emergency\n";
    cout << "3. Process Emergency\n";
    cout << "4. Find Shortest Route\n";
    cout << "5. View Disaster Records (BST)\n";
    cout << "6. View System Logs\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
}

/* ---------------- Sample Graph Setup ---------------- */
void setupGraph() {
    g.addEdge(0,1,4);
    g.addEdge(0,2,2);
    g.addEdge(1,3,5);
    g.addEdge(2,3,8);
    g.addEdge(3,4,6);
    g.addEdge(4,5,3);
}

/* ---------------- MAIN ---------------- */
int main() {

    setupGraph();

    int choice;

    cout << "🚨 Welcome to Disaster Management System 🚨\n";

    while(true) {

        showMenu();
        cin >> choice;

        if(choice == 0) {
            cout << "Exiting System...\n";
            break;
        }

        /* ---------------- BFS VIEW ---------------- */
        else if(choice == 1) {
            cout << "\n🌐 City Network (Breadth First Search)\n";
            cout << "Explanation: Shows nearby connected cities step-by-step\n\n";
            g.BFS(0);
        }

        /* ---------------- ADD EMERGENCY ---------------- */
        else if(choice == 2) {
            Emergency e;
            cout << "\nEnter Emergency ID: ";
            cin >> e.id;
            cout << "Enter City (0-5): ";
            cin >> e.city;
            cout << "Enter Severity (1-10): ";
            cin >> e.severity;

            pq.push(e);

            cout << "✅ Emergency Added Successfully!\n";

            logSystem.insert("Emergency Added ID: " + to_string(e.id));
        }

        /* ---------------- PROCESS EMERGENCY ---------------- */
        else if(choice == 3) {

            if(pq.empty()) {
                cout << "No emergencies to process!\n";
                continue;
            }

            Emergency e = pq.top();
            pq.pop();

            cout << "\n🚨 Processing Emergency...\n";
            cout << "ID: " << e.id << endl;
            cout << "City: " << e.city << endl;
            cout << "Severity: " << e.severity << endl;

            cout << "📊 Severity based priority system activated\n";

            vector<int> dist;
            g.dijkstra(0, dist);

            cout << "🚑 Nearest Rescue Distance: " << dist[e.city] << endl;

            tree.root = tree.insert(tree.root, e.severity, e.city);

            logSystem.insert("Processed Emergency ID: " + to_string(e.id));

            cout << "✅ Emergency Successfully Handled\n";
        }

        /* ---------------- SHORTEST PATH ---------------- */
        else if(choice == 4) {

            int src;
            cout << "Enter source city (0-5): ";
            cin >> src;

            vector<int> dist;
            g.dijkstra(src, dist);

            cout << "\n🛣 Shortest Distances from City " << src << ":\n";

            for(int i=0;i<dist.size();i++) {
                cout << "City " << i << " => " << dist[i] << endl;
            }

            cout << "\n📌 (Lower distance = faster rescue route)\n";
        }

        /* ---------------- BST VIEW ---------------- */
        else if(choice == 5) {

            cout << "\n🌳 Disaster Records (Sorted by Severity)\n";
            cout << "Format: City | Severity\n\n";

            tree.inorder(tree.root);
        }

        /* ---------------- LOGS ---------------- */
        else if(choice == 6) {

            cout << "\n📜 System Logs:\n\n";
            logSystem.display();
        }

        else {
            cout << "❌ Invalid Choice!\n";
        }
    }

    return 0;
}
