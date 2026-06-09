// Emergency.h

#ifndef EMERGENCY_H
#define EMERGENCY_H

#include <bits/stdc++.h>
using namespace std;

struct Emergency {
    int id;
    string city;
    int severity;

    bool operator<(const Emergency &e) const {
        return severity < e.severity;
    }

    void print() {
        cout << "ID: " << id
             << " | City: " << city
             << " | Severity: " << severity << endl;
    }
};

#endif
