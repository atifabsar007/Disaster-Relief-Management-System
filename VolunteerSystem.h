#ifndef VOLUNTEER_H
#define VOLUNTEER_H

#include <bits/stdc++.h>
using namespace std;

struct Volunteer {
    string name, skill;
};

class VolunteerSystem {
public:
    vector<Volunteer> v;

    void add(string n, string s) {
        v.push_back({n,s});
    }

    void show() {
        cout << "\n🤝 VOLUNTEERS\n";
        for(auto &x:v)
            cout << x.name << " | " << x.skill << endl;
    }
};

#endif
