#include <bits/stdc++.h>
using namespace std;

/* ================= HEADERS ================= */
#include "Victim.h"
#include "MedicalQueue.h"
#include "SupplySystem.h"
#include "VolunteerSystem.h"
#include "ERVSystem.h"
#include "LinkedListLog.h"
#include "Shelter.h"

/* ================= SYSTEM OBJECTS ================= */
VictimList victims;
MedicalQueue medical;
SupplySystem supply;
VolunteerSystem volunteers;
ERVSystem erv;
LogSystem logs;
ShelterSystem shelters;

/* ================= MENU ================= */
void menu() {

    cout << "\n=====================================\n";
    cout << " DISASTER RELIEF SYSTEM (RED CROSS)\n";
    cout << "=====================================\n";

    cout << "1. Register Victim\n";
    cout << "2. Medical Emergency Queue\n";
    cout << "3. Supply Distribution\n";
    cout << "4. Volunteer Management\n";
    cout << "5. Emergency Vehicles (ERV)\n";
    cout << "6. View Victims\n";
    cout << "7. Shelter Management\n";
    cout << "8. View System Logs\n";
    cout << "0. Exit\n";

    cout << "Enter choice: ";
}

/* ================= MAIN ================= */
int main() {

    int choice;

    while(true) {

        menu();
        cin >> choice;

        /* ================= EXIT ================= */
        if(choice == 0) {
            cout << "\n🚨 System Shutdown Completed...\n";
            break;
        }

        /* ================= 1. REGISTER VICTIM ================= */
        else if(choice == 1) {

            string name, gender, condition, shelter;
            int age;

            cout << "\nEnter Name: ";
            cin >> name;

            cout << "Enter Age: ";
            cin >> age;

            cout << "Enter Gender: ";
            cin >> gender;

            cout << "Enter Condition (injured/normal/critical): ";
            cin >> condition;

            shelters.showShelters();

            cout << "Assign Shelter Name: ";
            cin >> shelter;

            victims.addVictim(name, age, gender, condition, shelter);

            logs.add("Victim registered: " + name + " -> Shelter: " + shelter);

            cout << "✅ Victim Registered Successfully\n";
        }

        /* ================= 2. MEDICAL ================= */
        else if(choice == 2) {

            string name;
            int severity;

            cout << "\nPatient Name: ";
            cin >> name;

            cout << "Severity (1-10): ";
            cin >> severity;

            medical.addPatient(name, severity);
            medical.treatPatient();

            logs.add("Medical case handled: " + name);
        }

        /* ================= 3. SUPPLY ================= */
        else if(choice == 3) {

            string item;

            cout << "\nEnter Supply Item: ";
            cin >> item;

            supply.addSupply(item);
            supply.distribute();

            logs.add("Supply distributed: " + item);
        }

        /* ================= 4. VOLUNTEER ================= */
        else if(choice == 4) {

            string name, skill;

            cout << "\nVolunteer Name: ";
            cin >> name;

            cout << "Skill (medical/rescue/logistics): ";
            cin >> skill;

            volunteers.add(name, skill);

            logs.add("Volunteer added: " + name);

            cout << "✅ Volunteer Registered\n";
        }

        /* ================= 5. ERV ================= */
        else if(choice == 5) {

            string id, loc;

            cout << "\nERV ID: ";
            cin >> id;

            cout << "Location: ";
            cin >> loc;

            erv.add(id, loc);

            logs.add("ERV deployed: " + id);

            cout << "🚑 ERV Added Successfully\n";
        }

        /* ================= 6. VIEW VICTIMS ================= */
        else if(choice == 6) {
            victims.display();
        }

        /* ================= 7. SHELTER MANAGEMENT ================= */
        else if(choice == 7) {

            int sub;

            cout << "\n🏠 SHELTER MANAGEMENT SYSTEM\n";
            cout << "----------------------------\n";
            cout << "1. Add Shelter\n";
            cout << "2. View Shelters\n";
            cout << "3. View Summary\n";
            cout << "4. Assign Victim\n";
            cout << "Enter choice: ";

            cin >> sub;

            if(sub == 1) {

                string name, loc;
                int cap;

                cout << "Shelter Name: ";
                cin >> name;

                cout << "Location: ";
                cin >> loc;

                cout << "Capacity: ";
                cin >> cap;

                shelters.addShelter(name, loc, cap);

                logs.add("Shelter added: " + name);

                cout << "✅ Shelter Added\n";
            }

            else if(sub == 2) {
                shelters.showShelters();
            }

            else if(sub == 3) {
                shelters.summary();
            }

            else if(sub == 4) {

                string name;

                cout << "Enter Shelter Name: ";
                cin >> name;

                if(shelters.assignVictim(name)) {

                    logs.add("Victim assigned to shelter: " + name);
                    cout << "✅ Victim Assigned Successfully\n";
                }
                else {
                    cout << "❌ Failed (Shelter Full or Not Found)\n";
                }
            }
        }

        /* ================= 8. LOGS ================= */
        else if(choice == 8) {
            logs.show();
        }

        else {
            cout << "❌ Invalid Choice\n";
        }
    }

    return 0;
}
