#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <bits/stdc++.h>
using namespace std;

class Dashboard {
public:
    void show(int victims, int critical,
              int shelters, int erv,
              int volunteers, int food, int water) {

        cout << "\n🚨 CONTROL DASHBOARD\n";
        cout << "========================\n";
        cout << "Victims      : " << victims << endl;
        cout << "Critical     : " << critical << endl;
        cout << "Shelters     : " << shelters << endl;
        cout << "ERVs Busy    : " << erv << endl;
        cout << "Volunteers   : " << volunteers << endl;
        cout << "Food Stock   : " << food << endl;
        cout << "Water Stock  : " << water << endl;
        cout << "========================\n";
    }
};

#endif
