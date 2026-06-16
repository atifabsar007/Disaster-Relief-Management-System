#pragma once
#include <iostream>
#include <string>

using namespace std;

class SupplySystem {
public:
    int food = 100, water = 100, med = 50, blanket = 80;

    void use(string t) {
        if (t == "food") food--;
        else if (t == "water") water--;
        else if (t == "med") med--;
        else blanket--;
        cout << "Supply Updated\n";
    }

    void show() {
        cout << "\nSUPPLIES\nFood: " << food << " | Water: " << water 
             << " | Med: " << med << " | Blanket: " << blanket << endl;
    }
};

class Dashboard {
public:
    void show(int v, int c, int sh, int erv, int vol, int f, int w) {
        cout << "\nDASHBOARD\n----------------------------------------\n";
        cout << "Victims: " << v << "\nCritical: " << c << "\nShelters: " << sh 
             << "\nERV Busy: " << erv << "\nVolunteers: " << vol 
             << "\nFood: " << f << " | Water: " << w << endl;
    }
};
