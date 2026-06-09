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

/* 🌆 CITY LIST (USER ONLY SEES THIS) */
vector<string> cities = {
    "Dhaka",
    "Chittagong",
    "Khulna",
    "Rajshahi",
    "Barisal",
    "Sylhet"
};

void showCities() {
    cout << "\n🌆 Available Cities:\n";
    for(int i = 0; i < cities.size(); i++) {
        cout << "- " << cities[i] << endl;
    }
}

void showMenu() {
    cout << "\n=========================================\n";
    cout << "   DISASTER RELIEF & MANAGEMENT SYSTEM\n";
    cout << "=========================================\n";
    cout << "1. View City Network (BFS)\n";
    cout << "2. Add Emergency\n";
    cout << "3. Process Emergency\n";
    cout << "4. Find Shortest Route\n";
    cout << "5. View Disaster Records (BST)\n";
    cout << "6. View System Logs\n";
    cout << "7. Show Cities\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
}

/* 🌐 GRAPH SETUP */
void setupGraph() {
    g.addEdge(0,1,4); // Dhaka - Chittagong
    g.addEdge(0,2,2); // Dhaka - Khulna
    g.addEdge(1,3,5);
    g.addEdge(2,3,8);
    g.addEdge(3,4,6);
    g.addEdge(4,5,3);
}

/* 🔍 CITY INDEX FINDER */
int getCityIndex(string name) {
    for(int i=0;i<cities.size();i++) {
        if(cities[i] == name) return i;
    }
    return -1;
}

int main() {

    setupGraph();

    int choice;

    cout << "🚨 WELCOME TO DISASTER MANAGEMENT SYSTEM 🚨\n";

    while(true) {

        showMenu();
        cin >> choice;

        if(choice == 0) {
            cout << "Exiting System...\n";
            break;
        }

        /* 🌐 BFS */
        else if(choice == 1) {
            cout << "\n🌐 City Network (BFS Traversal)\n";
            cout << "Showing how cities are connected...\n\n";
            g.BFS(0);
        }

        /* 🚨 ADD EMERGENCY */
        else if(choice == 2) {

            Emergency e;

            cout << "\nEnter Emergency ID: ";
            cin >> e.id;

            showCities();

            cout << "Enter City Name: ";
            cin >> e.city;

            cout << "Enter Severity (1-10): ";
            cin >> e.severity;

            pq.push(e);

            cout << "\n✅ Emergency Added Successfully!\n";
            e.print();

            logSystem.insert("Added Emergency in " + e.city);
        }

        /* 🚑 PROCESS EMERGENCY */
        else if(choice == 3) {

            if(pq.empty()) {
                cout << "No emergencies available!\n";
                continue;
            }

            Emergency e = pq.top();
            pq.pop();

            cout << "\n🚨 Processing Emergency...\n";
            e.print();

            int src = getCityIndex("Dhaka");
            int dest = getCityIndex(e.city);

            vector<int> dist;
            g.dijkstra(src, dist);

            cout << "\n🚑 Distance from Dhaka to " 
                 << e.city << " = " << dist[dest] << endl;

            tree.root = tree.insert(tree.root, e.city, e.severity);

            logSystem.insert("Processed Emergency in " + e.city);

            cout << "✅ Emergency Handled Successfully\n";
        }

        /* 🛣 SHORTEST ROUTE */
        else if(choice == 4) {

            string srcCity;

            showCities();
            cout << "\nEnter Source City: ";
            cin >> srcCity;

            int src = getCityIndex(srcCity);

            vector<int> dist;
            g.dijkstra(src, dist);

            cout << "\n🛣 Shortest Distances from " 
                 << srcCity << ":\n\n";

            for(int i=0;i<cities.size();i++) {
                cout << cities[i] << " => " << dist[i] << endl;
            }
        }

        /* 🌳 BST */
        else if(choice == 5) {

            cout << "\n🌳 Disaster Records (Sorted by Severity)\n\n";
            tree.inorder(tree.root);
        }

        /* 📜 LOGS */
        else if(choice == 6) {

            cout << "\n📜 System Logs:\n\n";
            logSystem.display();
        }

        /* 🌆 SHOW CITIES */
        else if(choice == 7) {
            showCities();
        }

        else {
            cout << "❌ Invalid Choice!\n";
        }
    }

    return 0;
}
