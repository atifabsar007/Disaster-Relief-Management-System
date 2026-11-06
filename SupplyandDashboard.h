#pragma once
#include <iostream>
#include <string>

using namespace std;

class SupplySystem {
public:
    int food = 100, water = 100, med = 50, blanket = 80;

    bool use(const string& type) {
        int* selectedSupply = nullptr;

        if (type == "food") selectedSupply = &food;
        else if (type == "water") selectedSupply = &water;
        else if (type == "med") selectedSupply = &med;
        else if (type == "blanket") selectedSupply = &blanket;
        else {
            cout << "Unknown supply type. No inventory changed.\n";
            return false;
        }

        if (*selectedSupply <= 0) {
            cout << "Insufficient " << type << " supply. Inventory unchanged.\n";
            return false;
        }

        --(*selectedSupply);
        cout << "Supply Updated\n";
        return true;
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
