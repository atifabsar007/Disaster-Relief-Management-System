#include <bits/stdc++.h>
using namespace std;

#include "Victim.h"
#include "MedicalQueue.h"
#include "SupplySystem.h"
#include "VolunteerSystem.h"
#include "ERVSystem.h"
#include "LinkedListLog.h"

VictimList victims;
MedicalQueue medical;
SupplySystem supply;
VolunteerSystem volunteers;
ERVSystem erv;
LogSystem logs;

void menu() {

    cout << "\n=====================================\n";
    cout << " DISASTER RELIEF SYSTEM (RED CROSS)\n";
    cout << "=====================================\n";

    cout << "1. Register Victim\n";
    cout << "2. Medical Queue\n";
    cout << "3. Supply Distribution\n";
    cout << "4. Volunteers\n";
    cout << "5. Emergency Vehicles\n";
    cout << "6. View Victims\n";
    cout << "7. View Logs\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
}

int main() {

    int choice;

    while(true) {

        menu();
        cin >> choice;

        if(choice == 0) break;

        else if(choice == 1) {

            string name, gender, condition, shelter;
            int age;

            cout << "Name: "; cin >> name;
            cout << "Age: "; cin >> age;
            cout << "Gender: "; cin >> gender;
            cout << "Condition: "; cin >> condition;
            cout << "Shelter: "; cin >> shelter;

            victims.addVictim(name, age, gender, condition, shelter);

            logs.add("Victim registered: " + name);
        }

        else if(choice == 2) {

            string name;
            int sev;

            cout << "Patient name: ";
            cin >> name;
            cout << "Severity (1-10): ";
            cin >> sev;

            medical.addPatient(name, sev);
            medical.treatPatient();

            logs.add("Medical case handled: " + name);
        }

        else if(choice == 3) {

            string item;
            cout << "Supply item: ";
            cin >> item;

            supply.addSupply(item);
            supply.distribute();

            logs.add("Supply distributed: " + item);
        }

        else if(choice == 4) {

            string name, skill;

            cout << "Volunteer name: ";
            cin >> name;
            cout << "Skill: ";
            cin >> skill;

            volunteers.add(name, skill);
            logs.add("Volunteer added: " + name);
        }

        else if(choice == 5) {

            string id, loc;

            cout << "ERV ID: ";
            cin >> id;
            cout << "Location: ";
            cin >> loc;

            erv.add(id, loc);
            logs.add("ERV added: " + id);
        }

        else if(choice == 6) {
            victims.display();
        }

        else if(choice == 7) {
            logs.show();
        }
    }

    return 0;
}
