#ifndef SHELTER_H
#define SHELTER_H

#include <bits/stdc++.h>
using namespace std;

struct Shelter {
    string name;
    string location;
    int capacity;
    int occupied;
};

class ShelterSystem {
public:
    vector<Shelter> shelters;

    void addShelter(string name, string location, int capacity) {
        Shelter s;
        s.name = name;
        s.location = location;
        s.capacity = capacity;
        s.occupied = 0;
        shelters.push_back(s);
    }

    bool assignVictim(string name) {
        for(auto &s : shelters) {
            if(s.name == name) {
                if(s.occupied < s.capacity) {
                    s.occupied++;
                    return true;
                }
                return false;
            }
        }
        return false;
    }

    void showShelters() {
        cout << "\n🏠 SHELTERS\n";
        cout << "-------------------------\n";

        for(auto &s : shelters) {
            cout << "Name: " << s.name << endl;
            cout << "Location: " << s.location << endl;
            cout << "Capacity: " << s.capacity << endl;
            cout << "Occupied: " << s.occupied << endl;

            if(s.occupied == s.capacity)
                cout << "Status: FULL 🔴\n";
            else if(s.occupied > s.capacity * 0.7)
                cout << "Status: NEAR FULL 🟡\n";
            else
                cout << "Status: AVAILABLE 🟢\n";

            cout << "-------------------------\n";
        }
    }

    void summary() {
        int cap = 0, occ = 0;

        for(auto &s : shelters) {
            cap += s.capacity;
            occ += s.occupied;
        }

        cout << "\n📊 SHELTER SUMMARY\n";
        cout << "Total Capacity: " << cap << endl;
        cout << "Occupied: " << occ << endl;
        cout << "Available: " << cap - occ << endl;
    }
};

#endif
