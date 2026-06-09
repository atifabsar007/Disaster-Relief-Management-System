#ifndef ERV_SYSTEM_H
#define ERV_SYSTEM_H

#include <bits/stdc++.h>
using namespace std;

/*
    🚑 ERV SMART DISPATCH SYSTEM
    - Emergency Response Vehicles
    - Greedy selection (first available OR nearest priority)
*/

class ERVSystem {

public:

    struct ERV {
        string id;
        string location;
        bool busy;
    };

    vector<ERV> vehicles;

    /* ➕ ADD NEW ERV */
    void add(string id, string location) {

        ERV v;
        v.id = id;
        v.location = location;
        v.busy = false;

        vehicles.push_back(v);

        cout << "🚑 ERV Registered: " << id << " at " << location << endl;
    }

    /* 🚨 SMART DISPATCH SYSTEM */
    void dispatch(string emergencyLocation) {

        cout << "\n🚑 ERV DISPATCH SYSTEM ACTIVATED\n";
        cout << "---------------------------------\n";

        for(auto &v : vehicles) {

            if(!v.busy) {

                v.busy = true;

                cout << "✅ ERV Assigned Successfully\n";
                cout << "🚑 Vehicle ID   : " << v.id << endl;
                cout << "📍 From Location: " << v.location << endl;
                cout << "📍 To Emergency : " << emergencyLocation << endl;

                cout << "⏱ Status       : DISPATCHED\n";
                cout << "---------------------------------\n";

                return;
            }
        }

        cout << "❌ No Available ERVs at the moment!\n";
        cout << "⚠ Please wait or deploy new vehicles.\n";
        cout << "---------------------------------\n";
    }

    /* 📋 SHOW ALL ERVs */
    void show() {

        cout << "\n🚑 ERV STATUS DASHBOARD\n";
        cout << "---------------------------------\n";

        if(vehicles.empty()) {
            cout << "No ERVs registered yet.\n";
            return;
        }

        for(auto &v : vehicles) {

            cout << "Vehicle ID : " << v.id << endl;
            cout << "Location   : " << v.location << endl;
            cout << "Status     : " << (v.busy ? "BUSY 🔴" : "AVAILABLE 🟢") << endl;
            cout << "---------------------------------\n";
        }
    }

    /* 🔄 RESET ALL ERVs (for simulation/testing) */
    void resetAll() {

        for(auto &v : vehicles)
            v.busy = false;

        cout << "🔄 All ERVs reset to AVAILABLE state.\n";
    }

    /* 📊 SUMMARY */
    void summary() {

        int total = vehicles.size();
        int busy = 0;

        for(auto &v : vehicles)
            if(v.busy) busy++;

        cout << "\n📊 ERV SUMMARY REPORT\n";
        cout << "---------------------------------\n";
        cout << "Total ERVs   : " << total << endl;
        cout << "Busy ERVs    : " << busy << endl;
        cout << "Available    : " << total - busy << endl;
        cout << "---------------------------------\n";
    }
};

#endif
