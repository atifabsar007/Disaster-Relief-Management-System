#ifndef VICTIM_H
#define VICTIM_H

#include <bits/stdc++.h>
using namespace std;

struct Victim {
    string name;
    int age;
    string gender;
    string condition;
    string shelterAssigned;
    Victim* next;
};

class VictimList {
public:
    Victim* head;

    VictimList() {
        head = NULL;
    }

    void addVictim(string name, int age, string gender, string condition, string shelter) {

        Victim* v = new Victim();
        v->name = name;
        v->age = age;
        v->gender = gender;
        v->condition = condition;
        v->shelterAssigned = shelter;

        v->next = head;
        head = v;
    }

    void display() {

        cout << "\n🏠 REGISTERED VICTIMS\n";
        cout << "---------------------------------\n";

        Victim* temp = head;

        while(temp) {
            cout << "Name: " << temp->name
                 << " | Age: " << temp->age
                 << " | Gender: " << temp->gender
                 << " | Condition: " << temp->condition
                 << " | Shelter: " << temp->shelterAssigned << endl;

            temp = temp->next;
        }

        cout << "---------------------------------\n";
    }
};

#endif
