#ifndef SUPPLYSYSTEM_H
#define SUPPLYSYSTEM_H

#include <bits/stdc++.h>
using namespace std;

class SupplySystem {
public:
    queue<string> supplies;

    void addSupply(string item) {
        supplies.push(item);
    }

    void distribute() {

        if(supplies.empty()) {
            cout << "No supplies left!\n";
            return;
        }

        cout << "📦 Distributed: " << supplies.front() << endl;
        supplies.pop();
    }

    void show() {

        cout << "\n📦 SUPPLY STOCK\n";
        cout << "---------------------------------\n";

        queue<string> temp = supplies;

        while(!temp.empty()) {
            cout << "- " << temp.front() << endl;
            temp.pop();
        }

        cout << "---------------------------------\n";
    }
};

#endif
