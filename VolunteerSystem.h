#ifndef VOLUNTEER_H
#define VOLUNTEER_H

#include <bits/stdc++.h>
using namespace std;

struct Volunteer {
    string name;
    string skill;
    bool available;
};

class VolunteerSystem {
public:
    vector<Volunteer> v;

    void add(string name, string skill) {
        v.push_back({name, skill, true});
    }

    void show() {

        cout << "\n🤝 VOLUNTEERS\n";
        cout << "---------------------------------\n";

        for(auto &x : v) {
            cout << x.name << " | " << x.skill << endl;
        }

        cout << "---------------------------------\n";
    }
};

#endif
