// Emergency.h

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
        cout << "🚨 Emergency ID: " << id << endl;
        cout << "📍 City: " << city << endl;
        cout << "⚠ Severity: " << severity << endl;
    }
};

#endif
