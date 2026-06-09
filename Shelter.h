#ifndef SHELTER_H
#define SHELTER_H

#include <bits/stdc++.h>
using namespace std;

/* 🏠 SHELTER STRUCTURE */
struct Shelter {
    string name;
    string location;
    int capacity;
    int occupied;
};

/* 🏠 SHELTER MANAGEMENT SYSTEM */
class ShelterSystem {
public:
    vector<Shelter> shelters;

    /* ➕ ADD SHELTER */
    void addShelter(string name, string location, int capacity) {

        Shelter s;
        s.name = name;
        s.location = location;
        s.capacity = capacity;
        s.occupied = 0;

        shelters.push_back(s);
    }

    /* 👤 ASSIGN VICTIM TO SHELTER */
    bool assignVictim(string shelterName) {

        for(auto &s : shelters) {

            if(s.name == shelterName) {

                if(s.occupied < s.capacity) {
                    s.occupied++;
                    return true;
                }
                else {
                    cout << "❌ Shelter Full: " << shelterName << endl;
                    return false;
                }
            }
        }

        cout << "❌ Shelter Not Found!\n";
        return false;
    }

    /* 📋 SHOW SHELTERS */
    void showShelters() {

        cout << "\n🏠 SHELTER STATUS\n";
        cout << "---------------------------------\n";

        for(auto &s : shelters) {

            cout << "Shelter Name : " << s.name << endl;
            cout << "Location     : " << s.location << endl;
            cout << "Capacity     : " << s.capacity << endl;
            cout << "Occupied     : " << s.occupied << endl;

            if(s.occupied == s.capacity)
                cout << "Status       : 🔴 FULL\n";
            else if(s.occupied > s.capacity * 0.7)
                cout << "Status       : 🟡 NEARLY FULL\n";
            else
                cout << "Status       : 🟢 AVAILABLE\n";

            cout << "---------------------------------\n";
        }
    }

    /* 📊 TOTAL SUMMARY */
    void summary() {

        int totalCap = 0, totalOcc = 0;

        for(auto &s : shelters) {
            totalCap += s.capacity;
            totalOcc += s.occupied;
        }

        cout << "\n📊 SHELTER SUMMARY\n";
        cout << "---------------------------------\n";
        cout << "Total Capacity : " << totalCap << endl;
        cout << "Occupied Beds  : " << totalOcc << endl;
        cout << "Available Beds : " << (totalCap - totalOcc) << endl;
        cout << "---------------------------------\n";
    }
};

#endif
