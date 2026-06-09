#ifndef VOL_H
#define VOL_H

#include <bits/stdc++.h>
using namespace std;

struct Volunteer {
    string name;
    string skill;
};

class VolunteerSystem {
public:
    vector<Volunteer> v;

    void add(){
        string n;
        int c;

        cout << "\n🤝 VOLUNTEER NAME: ";
        cin >> n;

        cout << "\nSELECT SKILL:\n";
        cout << "1. Medical 🏥\n2. Rescue 🚑\n3. Logistics 📦\n";
        cout << "Choice: ";
        cin >> c;

        string skill;
        if(c==1) skill="Medical";
        else if(c==2) skill="Rescue";
        else skill="Logistics";

        v.push_back({n,skill});

        cout << "✅ Volunteer Added\n";
    }

    void show(){
        cout << "\n🤝 VOLUNTEERS\n";
        for(auto &x:v){
            cout << x.name << " | " << x.skill << endl;
        }
    }

    int size(){ return v.size(); }
};

#endif
