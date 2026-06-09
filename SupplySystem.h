#ifndef SUPPLY_H
#define SUPPLY_H

#include <bits/stdc++.h>
using namespace std;

class SupplySystem {
public:
    int food = 100;
    int water = 100;
    int medicine = 50;
    int blanket = 80;

    void use(string t) {
        if (t == "food") food--;
        if (t == "water") water--;
        if (t == "medicine") medicine--;
        if (t == "blanket") blanket--;

        if (food < 20 || water < 20)
            cout << "⚠ LOW SUPPLY ALERT!\n";
    }

    void show() {
        cout << "\n📦 SUPPLIES\n";
        cout << "Food: " << food
             << " Water: " << water
             << " Medicine: " << medicine
             << " Blanket: " << blanket << endl;
    }
};

#endif
