#ifndef ERV_H
#define ERV_H

#include <bits/stdc++.h>
using namespace std;

class ERVSystem {
public:
    struct ERV {
        string id, loc;
        bool busy;
    };

    vector<ERV> v;

    void add(string id, string l) {
        v.push_back({id, l, false});
        cout << "✅ ERV ADDED: " << id << " at " << l << endl;
    }

    void show() {
        cout << "\n🚑 AVAILABLE ERVs\n";
        for (auto &x : v) {
            cout << x.id << " | "
                 << (x.busy ? "BUSY" : "FREE") << endl;
        }
    }

    void dispatch(string loc) {

        cout << "\n🚑 ERV DISPATCH SYSTEM\n";
        cout << "Searching available ERVs...\n";

        for (auto &x : v) {
            if (!x.busy) {
                x.busy = true;

                cout << "\n✅ ERV ASSIGNED SUCCESSFULLY\n";
                cout << "ID   : " << x.id << endl;
                cout << "FROM : " << x.loc << endl;
                cout << "TO   : " << loc << endl;
                cout << "STATUS: DISPATCHED 🚑\n";

                return;
            }
        }

        cout << "\n❌ NO ERV AVAILABLE RIGHT NOW\n";
        cout << "Please wait or add new ERV\n";
    }

    int busyCount() {
        int c = 0;
        for (auto &x : v)
            if (x.busy) c++;
        return c;
    }
};

#endif
