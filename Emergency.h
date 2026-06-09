// Emergency.h

#ifndef EMERGENCY_H
#define EMERGENCY_H

#include <bits/stdc++.h>
using namespace std;

struct Emergency {
    int id;
    int city;
    int severity;

    bool operator<(const Emergency &e) const {
        return severity < e.severity; // max heap
    }

    void print(string cityName[]) {
        cout << "ID: " << id
             << " | City: " << cityName[city]
             << " | Severity: " << severity << endl;
    }
};

#endif
