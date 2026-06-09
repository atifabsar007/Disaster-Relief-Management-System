#ifndef ERV_H
#define ERV_H

#include <bits/stdc++.h>
using namespace std;

struct ERV {
    string id;
    string location;
    bool available;
};

class ERVSystem {
public:
    vector<ERV> vehicles;

    void add(string id, string loc) {
        vehicles.push_back({id, loc, true});
    }

    void show() {

        cout << "\n🚑 EMERGENCY RESPONSE VEHICLES\n";
        cout << "---------------------------------\n";

        for(auto &v : vehicles) {
            cout << v.id << " | " << v.location << endl;
        }

        cout << "---------------------------------\n";
    }
};

#endif
