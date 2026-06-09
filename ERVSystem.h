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

    void add(){
        string id, loc;

        cout << "\n🚑 ADD ERV\n";
        cout << "ID: ";
        cin >> id;

        cout << "Base Location: ";
        cin >> loc;

        v.push_back({id,loc,false});

        cout << "✅ ERV Added\n";
    }

    void dispatch(string dest){
        cout << "\n🚑 ERV DISPATCH\n";
        cout << "Searching available ERVs...\n";

        for(auto &x:v){
            if(!x.busy){
                x.busy=true;

                cout << "\n✅ ERV ASSIGNED\n";
                cout << "ID: " << x.id << endl;
                cout << "FROM: " << x.loc << endl;
                cout << "TO: " << dest << endl;
                return;
            }
        }

        cout << "❌ NO ERV AVAILABLE\n";
    }

    int busyCount(){
        int c=0;
        for(auto &x:v)
            if(x.busy) c++;
        return c;
    }

    void show(){
        cout << "\n🚑 ERVs\n";
        for(auto &x:v){
            cout << x.id << " | "
                 << (x.busy?"BUSY":"FREE") << endl;
        }
    }
};

#endif
