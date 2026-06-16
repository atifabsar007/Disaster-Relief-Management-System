#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Victim {
    string name, gender, condition, shelter;
    int age;
    Victim* next;
};

class VictimList {
public:
    Victim* head = NULL;

    void add(string n, int a, string g, string c, string s) {
        Victim* v = new Victim();
        v->name = n;
        v->age = a;
        v->gender = g;
        v->condition = c;
        v->shelter = s;
        v->next = head;
        head = v;
    }

    void show() {
        cout << "\nVICTIMS LIST\n";
        cout << "----------------------------------------\n";
        for (auto t = head; t; t = t->next) {
            cout << t->name << " | " << t->age
                 << " | " << t->gender
                 << " | " << t->condition
                 << " | " << t->shelter << endl;
        }
    }

    void search(string name) {
        for (auto t = head; t; t = t->next) {
            if (t->name == name) {
                cout << "\nFOUND VICTIM\n";
                cout << "Name: " << t->name << "\nAge: " << t->age 
                     << "\nCondition: " << t->condition << "\nShelter: " << t->shelter << endl;
                return;
            }
        }
        cout << "Not Found\n";
    }

    int count() {
        int c = 0;
        for (auto t = head; t; t = t->next) c++;
        return c;
    }

    int critical() {
        int c = 0;
        for (auto t = head; t; t = t->next)
            if (t->condition == "Critical") c++;
        return c;
    }
};
