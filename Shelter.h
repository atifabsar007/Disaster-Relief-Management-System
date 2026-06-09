#ifndef SHELTER_H
#define SHELTER_H

#include <bits/stdc++.h>
using namespace std;

struct Shelter {
    string name, location;
    int cap, used;
};

class ShelterSystem {
public:
    vector<Shelter> s;

    void add(string n,string l,int c){
        s.push_back({n,l,c,0});
        cout << "✅ Shelter Added: " << n << endl;
    }

    string autoAssign(){
        if(s.empty()) return "NO SHELTER AVAILABLE";

        for(auto &x:s){
            if(x.used < x.cap){
                x.used++;
                return x.name;
            }
        }
        return "ALL SHELTERS FULL";
    }

    void show(){
        cout << "\n🏠 SHELTER STATUS\n";
        for(auto &x:s){
            cout << "• " << x.name
                 << " | " << x.used << "/" << x.cap << endl;
        }
    }
};

#endif
