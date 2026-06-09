#ifndef EMERGENCY_H
#define EMERGENCY_H

#include <bits/stdc++.h>
using namespace std;

struct Emergency {
    string id;
    string city;
    int severity;

    bool operator<(const Emergency &e) const {
        return severity < e.severity;
    }

    void print() {

        cout << "\n=================================\n";
        cout << "🚨 EMERGENCY REPORT\n";
        cout << "=================================\n";
        cout << "ID        : " << id << endl;
        cout << "City      : " << city << endl;
        cout << "Severity  : " << severity << "/10\n";

        if(severity >= 8)
            cout << "Priority  : 🔴 CRITICAL\n";
        else if(severity >= 5)
            cout << "Priority  : 🟡 MODERATE\n";
        else
            cout << "Priority  : 🟢 LOW\n";

        cout << "=================================\n";
    }
};

#endif
