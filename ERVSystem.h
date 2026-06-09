#ifndef ERV_H
#define ERV_H

#include <bits/stdc++.h>
using namespace std;

class ERVSystem {
public:
    struct ERV {
        string id;
        string location;
        bool busy = false;
    };

    vector<ERV> v;

    void add(string id, string loc) {
        v.push_back({id, loc, false});
    }

    void dispatch(string loc) {
        for (auto &x : v) {
            if (!x.busy) {
                x.busy = true;
                cout << "\n🚑 ERV DISPATCHED\n";
                cout << "ID: " << x.id << endl;
                cout << "From: " << x.location << endl;
                cout << "To: " << loc << endl;
                return;
            }
        }
        cout << "No ERVs available\n";
    }

    int busyCount() {
        int c = 0;
        for (auto &x : v)
            if (x.busy) c++;
        return c;
    }

    void show() {
        cout << "\n🚑 ERVs\n";
        for (auto &x : v)
            cout << x.id << " | " << (x.busy ? "BUSY" : "FREE") << endl;
    }
};

#endif
