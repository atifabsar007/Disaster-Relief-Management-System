#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Shelter {
    string name, location;
    int cap, used;
};

class ShelterSystem {
public:
    Shelter s[100]; 
    int shelterCount = 0;

    void add(string n, string l, int c) {
        if (shelterCount < 100) {
            s[shelterCount++] = {n, l, c, 0};
            cout << "Shelter Added: " << n << endl;
        } else {
            cout << "Shelter Array Full!\n";
        }
    }

    string autoAssign() {
        for (int i = 0; i < shelterCount; i++) {
            if (s[i].used < s[i].cap) {
                s[i].used++;
                return s[i].name;
            }
        }
        return "NO SHELTER AVAILABLE";
    }

    void show() {
        cout << "\nSHELTER STATUS\n";
        cout << "----------------------------------------\n";
        for (int i = 0; i < shelterCount; i++) {
            cout << s[i].name << " | " << s[i].used << "/" << s[i].cap << endl;
        }
    }

    int active() {
        int c = 0;
        for (int i = 0; i < shelterCount; i++) {
            if (s[i].used > 0) c++;
        }
        return c;
    }
};
