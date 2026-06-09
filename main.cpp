#include <bits/stdc++.h>
using namespace std;

#include "Graph.h"
#include "Emergency.h"
#include "BST.h"
#include "LinkedList.h"

/* 🌆 CITY SYSTEM (NO NUMBERS SHOWN TO USER) */
vector<string> cities = {
    "Dhaka",
    "Chittagong",
    "Khulna",
    "Rajshahi",
    "Barisal",
    "Sylhet"
};

Graph g(6);
priority_queue<Emergency> pq;
BST tree;
LinkedList logs;

/* 🔍 CITY FINDER */
int getCityIndex(string name) {
    for(int i=0;i<cities.size();i++) {
        if(cities[i] == name) return i;
    }
    return -1;
}

/* 🌐 GRAPH SETUP */
void setupGraph() {

    g.addEdge(0,1,4);
    g.addEdge(0,2,2);
    g.addEdge(1,3,5);
    g.addEdge(2,3,8);
    g.addEdge(3,4,6);
    g.addEdge(4,5,3);
}

/* 📋 MENU */
void menu() {

    cout << "\n=====================================\n";
    cout << " DISASTER RELIEF MANAGEMENT SYSTEM\n";
    cout << "=====================================\n";
    cout << "1. View City Network (BFS)\n";
    cout << "2. View City Network (DFS)\n";
    cout << "3. Add Emergency\n";
    cout << "4. Process Emergency\n";
    cout << "5. Find Shortest Routes\n";
    cout << "6. View Disaster Records (BST)\n";
    cout << "7. View System Logs\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
}

/* 🌆 SHOW CITIES */
void showCities() {

    cout << "\n🌆 Available Cities:\n";
    for(string c : cities)
        cout << " - " << c << endl;
}

int main() {

    setupGraph();

    int choice;

    cout << "🚨 WELCOME TO DISASTER MANAGEMENT SYSTEM 🚨\n";

    while(true) {

        menu();
        cin >> choice;

        if(choice == 0) {
            cout << "System shutting down...\n";
            break;
        }

        /* 🌐 BFS */
        else if(choice == 1) {
            g.BFS(0, cities);
        }

        /* 🌳 DFS */
        else if(choice == 2) {
            g.DFS(0, cities);
        }

        /* 🚨 ADD EMERGENCY */
        else if(choice == 3) {

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

            logs.insert("Emergency added in " + e.city);
        }

        /* 🚑 PROCESS */
        else if(choice == 4) {

            if(pq.empty()) {
                cout << "No emergencies!\n";
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

            logs.insert("Processed emergency in " + e.city);
        }

        /* 🛣 SHORTEST PATH */
        else if(choice == 5) {

            string src;

            showCities();

            cout << "\nEnter Source City: ";
            cin >> src;

            int s = getCityIndex(src);

            vector<int> dist;
            g.dijkstra(s, dist);

            cout << "\n🛣 Shortest Routes:\n\n";

            for(int i=0;i<cities.size();i++) {
                cout << cities[i] << " => " << dist[i] << endl;
            }
        }

        /* 🌳 BST */
        else if(choice == 6) {

            cout << "\n🌳 Disaster Records:\n\n";
            tree.inorder(tree.root);
        }

        /* 📜 LOGS */
        else if(choice == 7) {

            logs.display();
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
