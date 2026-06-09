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
        int choice;

        cout << "\n🤝 ENTER VOLUNTEER NAME: ";
        cin >> n;

        cout << "\nSELECT SKILL:\n";
        cout << "1. Medical 🏥\n";
        cout << "2. Rescue 🚑\n";
        cout << "3. Logistics 📦\n";
        cout << "Choice: ";
        cin >> choice;

        string skill;
        if(choice==1) skill="Medical";
        else if(choice==2) skill="Rescue";
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
