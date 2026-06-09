#ifndef SHELTER_H
#define SHELTER_H

#include <bits/stdc++.h>
using namespace std;

struct Shelter {
    string name;
    string location;
    int cap;
    int used;
};

class ShelterSystem {
public:
    vector<Shelter> s;

    void add(string n, string l, int c) {
        s.push_back({n,l,c,0});
    }

    bool assign(string name) {
        for(auto &x: s) {
            if(x.name == name) {
                if(x.used < x.cap) {
                    x.used++;
                    return true;
                }
            }
        }
        return false;
    }

    void show() {
        cout << "\n🏠 SHELTERS\n";
        for(auto &x: s) {
            cout << x.name << " | " << x.location
                 << " | " << x.used << "/" << x.cap << endl;
        }
    }

    void summary() {
        int total=0, used=0;
        for(auto &x: s){
            total += x.cap;
            used += x.used;
        }
        cout << "\n📊 Shelter Capacity: " << used << "/" << total << endl;
    }
};

#endif
