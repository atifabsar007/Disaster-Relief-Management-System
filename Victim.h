#ifndef VICTIM_H
#define VICTIM_H

#include <bits/stdc++.h>
using namespace std;

struct Victim {
    string name;
    int age;
    string gender;
    string condition;
    string shelter;
    Victim* next;
};

class VictimList {
public:
    Victim* head = NULL;

    void add(string name, int age, string gender, string condition, string shelter) {
        Victim* v = new Victim();
        v->name = name;
        v->age = age;
        v->gender = gender;
        v->condition = condition;
        v->shelter = shelter;
        v->next = head;
        head = v;
    }

    void show() {
        cout << "\n🏠 VICTIM LIST\n";
        Victim* t = head;
        while(t) {
            cout << t->name << " | " << t->age
                 << " | " << t->condition
                 << " | Shelter: " << t->shelter << endl;
            t = t->next;
        }
    }
};

#endif
