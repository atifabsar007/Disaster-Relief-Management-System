#ifndef SHELTER_H
#define SHELTER_H

#include <bits/stdc++.h>
using namespace std;

struct Shelter {
    string name;
    string location;
    int capacity;
    int used;
};

class ShelterSystem {
public:
    vector<Shelter> shelters;

    void add(string n, string l, int c) {
        shelters.push_back({n, l, c, 0});
    }

    bool assign(string n) {
        for (auto &s : shelters) {
            if (s.name == n && s.used < s.capacity) {
                s.used++;
                return true;
            }
        }
        return false;
    }

    int active() {
        int c = 0;
        for (auto &s : shelters)
            if (s.used > 0) c++;
        return c;
    }

    void show() {
        cout << "\n🏠 SHELTERS\n";
        for (auto &s : shelters) {
            cout << s.name << " | " << s.location
                 << " | " << s.used << "/" << s.capacity << endl;
        }
    }
};

#endif
