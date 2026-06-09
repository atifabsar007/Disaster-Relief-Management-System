#ifndef TEAM_H
#define TEAM_H

#include <bits/stdc++.h>
using namespace std;

/* 🚑 RESCUE TEAM STRUCTURE */
struct Team {
    string name;       // Team name (e.g., "Dhaka Rescue Unit")
    string baseCity;   // Base location
    int distance;      // Distance from emergency (km)
    int availability;  // 1 = available, 0 = busy

    /* 🔹 DISPLAY TEAM INFO */
    void print() {

        cout << "---------------------------------\n";
        cout << "🚑 Team Name   : " << name << endl;
        cout << "📍 Base City   : " << baseCity << endl;
        cout << "📏 Distance    : " << distance << " km\n";

        if(availability)
            cout << "🟢 Status      : Available\n";
        else
            cout << "🔴 Status      : Busy\n";
    }
};

/* 🔹 SORTING FUNCTION (BY DISTANCE) */
bool compareTeam(Team a, Team b) {
    return a.distance < b.distance;
}

#endif
