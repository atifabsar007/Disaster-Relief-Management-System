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
    }

    string autoAssign(){
        for(auto &x:s){
            if(x.used < x.cap){
                x.used++;
                return x.name;
            }
        }
        return "NO SHELTER AVAILABLE";
    }

    int active(){
        int c=0;
        for(auto &x:s) if(x.used>0) c++;
        return c;
    }

    void show(){
        cout<<"\n🏠 SHELTERS\n";
        for(auto &x:s){
            cout<<x.name<<" | "<<x.used<<"/"<<x.cap<<endl;
        }
    }
};

#endif
