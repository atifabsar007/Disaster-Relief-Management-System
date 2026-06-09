#ifndef SUPPLY_H
#define SUPPLY_H

#include <bits/stdc++.h>
using namespace std;

class SupplySystem {
public:
    int food=100, water=100, med=50, blanket=80;

    void use(string t) {
        if(t=="food") food--;
        if(t=="water") water--;
        if(t=="med") med--;
        if(t=="blanket") blanket--;

        if(food<=10 || water<=10)
            cout << "⚠ LOW SUPPLY ALERT!\n";
    }

    void show() {
        cout << "\n📦 SUPPLY\n";
        cout << "Food:" << food << " Water:" << water
             << " Med:" << med << " Blanket:" << blanket << endl;
    }
};

#endif
