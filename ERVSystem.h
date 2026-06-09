#ifndef ERV_H
#define ERV_H

#include <bits/stdc++.h>
using namespace std;

class ERVSystem {
public:

    struct ERV {
        string id, loc;
        bool busy = false;
    };

    vector<ERV> v;

    void add(string id, string loc) {
        v.push_back({id, loc, false});
    }

    void dispatch(string em) {
        for(auto &x:v) {
            if(!x.busy) {
                x.busy = true;
                cout << "🚑 ERV " << x.id
                     << " dispatched to " << em << endl;
                return;
            }
        }
        cout << "No ERVs available\n";
    }

    void show() {
        cout << "\n🚑 ERVs\n";
        for(auto &x:v)
            cout << x.id << " | " << (x.busy?"BUSY":"FREE") << endl;
    }
};

#endif
