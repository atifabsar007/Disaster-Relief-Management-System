#pragma once
#include <iostream>
#include <string>

using namespace std;

class ERVSystem {
    struct ERV { string id, loc; bool busy; };
    ERV v[20];
    int ervCount = 0;

    int adj[5][5] = {
        {0, 1, 1, 0, 0}, // 0: Base
        {1, 0, 0, 1, 0}, // 1: CityCenter
        {1, 0, 0, 0, 1}, // 2: Suburb
        {0, 1, 0, 0, 1}, // 3: Industrial
        {0, 0, 1, 1, 0}  // 4: Hills
    };
    string locs[5] = {"Base", "CityCenter", "Suburb", "Industrial", "Hills"};

public:
    void add() {
        string id;
        cout << "\nADD ERV\nID: "; cin >> id;
        v[ervCount++] = {id, "Base", false};
        cout << "ERV Added at Base\n";
    }

    void dispatch(string dest) {
        cout << "\nERV DISPATCH\nSearching available ERVs...\n";
        for (int i = 0; i < ervCount; i++) {
            if (!v[i].busy) {
                v[i].busy = true;
                cout << "\nERV ASSIGNED | ID: " << v[i].id << endl;
                
                int dIdx = -1;
                for (int j = 0; j < 5; j++) if (locs[j] == dest) dIdx = j;
                
                if (dIdx == -1) { cout << "Directing to unmapped location: " << dest << endl; return; }

                int q[100], front = 0, rear = 0;
                bool visited[5] = {false};
                int parent[5] = {-1, -1, -1, -1, -1};

                q[rear++] = 0; 
                visited[0] = true;

                while (front < rear) {
                    int curr = q[front++];
                    if (curr == dIdx) break;
                    for (int j = 0; j < 5; j++) {
                        if (adj[curr][j] && !visited[j]) {
                            visited[j] = true;
                            parent[j] = curr;
                            q[rear++] = j;
                        }
                    }
                }

                cout << "Shortest Route (BFS): ";
                int p = dIdx;
                int path[10], pLen = 0;
                while (p != -1) { path[pLen++] = p; p = parent[p]; }
                for (int j = pLen - 1; j >= 0; j--) cout << locs[path[j]] << (j == 0 ? "" : " -> ");
                cout << "\n";
                return;
            }
        }
        cout << "NO ERV AVAILABLE\n";
    }

    int busyCount() {
        int c = 0;
        for (int i = 0; i < ervCount; i++) if (v[i].busy) c++;
        return c;
    }

    void show() {
        cout << "\nERVs\n----------------------------------------\n";
        for (int i = 0; i < ervCount; i++) cout << v[i].id << " | " << (v[i].busy ? "BUSY" : "FREE") << endl;
    }
};
