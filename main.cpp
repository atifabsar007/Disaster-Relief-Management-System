#include <bits/stdc++.h>
using namespace std;

#include "Victim.h"
#include "Shelter.h"
#include "MedicalQueue.h"
#include "SupplySystem.h"
#include "VolunteerSystem.h"
#include "ERVSystem.h"
#include "LinkedListLog.h"
#include "Dashboard.h"
#include "Zone.h"

VictimList victims;
ShelterSystem shelters;
MedicalQueue medical;
SupplySystem supply;
VolunteerSystem volunteers;
ERVSystem erv;
LogSystem logs;
Dashboard dash;
ZoneSystem zone;

// ---------------- UI ----------------

void menu(){
    cout << "\n=================================\n";
    cout << " 🌍 DISASTER RELIEF SYSTEM\n";
    cout << "=================================\n";
    cout << "1. Add Victim\n";
    cout << "2. Show Victims\n";
    cout << "3. Search Victim\n";
    cout << "4. Dashboard\n";
    cout << "5. Add Shelter\n";
    cout << "6. Medical Triage\n";
    cout << "7. Supply System\n";
    cout << "8. Add Volunteer\n";
    cout << "9. ERV Dispatch\n";
    cout << "10. Show Logs\n";
    cout << "11. Zone Check\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
}

// ---------------- MAIN ----------------

int main(){
    int ch;

    while(true){
        menu();
        cin >> ch;

        if(ch == 0) break;

        // ---------------- VICTIM ----------------
        else if(ch == 1){
            string name, gender, cond;
            int age;

            cout << "\n👤 ENTER VICTIM DETAILS\n";
            cout << "Name: ";
            cin >> name;

            cout << "Age: ";
            cin >> age;

            cout << "Gender: ";
            cin >> gender;

            cout << "\nSelect Condition:\n";
            cout << "1. Critical 🔴\n";
            cout << "2. Serious 🟡\n";
            cout << "3. Minor 🟢\n";
            cout << "Choice: ";

            int c; cin >> c;

            if(c == 1) cond = "Critical";
            else if(c == 2) cond = "Serious";
            else cond = "Minor";

            string shelter = shelters.autoAssign();

            cout << "\n🏠 Assigned Shelter: " << shelter << endl;

            victims.add(name, age, gender, cond, shelter);

            logs.add("Victim added: " + name);
        }

        // ---------------- SHOW VICTIMS ----------------
        else if(ch == 2){
            victims.show();
        }

        // ---------------- SEARCH ----------------
        else if(ch == 3){
            string n;
            cout << "Enter Name: ";
            cin >> n;
            victims.search(n);
        }

        // ---------------- DASHBOARD ----------------
        else if(ch == 4){
            dash.show(
                victims.count(),
                victims.critical(),
                shelters.active(),
                erv.busyCount(),
                volunteers.size(),
                supply.food,
                supply.water
            );
        }

        // ---------------- SHELTER ----------------
        else if(ch == 5){
            string n,l;
            int c;

            cout << "\n🏠 Add Shelter\n";
            cout << "Name: ";
            cin >> n;
            cout << "Location: ";
            cin >> l;
            cout << "Capacity: ";
            cin >> c;

            shelters.add(n,l,c);
            cout << "✅ Shelter Added\n";
        }

        // ---------------- MEDICAL ----------------
        else if(ch == 6){
            string n;
            int s;

            cout << "\n🏥 Patient Name: ";
            cin >> n;

            cout << "Severity (1-10): ";
            cin >> s;

            medical.add(n,s);
            medical.treat();
        }

        // ---------------- SUPPLY ----------------
        else if(ch == 7){
            cout << "\n📦 Supply Menu\n";
            cout << "1. Food\n2. Water\n3. Medicine\n4. Blanket\n";
            cout << "Choice: ";

            int x;
            cin >> x;

            if(x == 1) supply.use("food");
            else if(x == 2) supply.use("water");
            else if(x == 3) supply.use("med");
            else supply.use("blanket");
        }

        // ---------------- VOLUNTEER ----------------
        else if(ch == 8){
            string n,s;

            cout << "\n🤝 Volunteer Name: ";
            cin >> n;

            cout << "Skill: ";
            cin >> s;

            volunteers.add(n,s);

            cout << "✅ Volunteer Added\n";
        }

        // ---------------- ERV ----------------
        else if(ch == 9){
            string id, loc;

            cout << "\n🚑 ERV SYSTEM\n";

            if(erv.v.size() == 0){
                cout << "⚠ No ERVs available. Add ERV first!\n";
                cout << "Enter ERV ID: ";
                cin >> id;

                cout << "Location: ";
                cin >> loc;

                erv.add(id, loc);
            }

            cout << "\nEnter Emergency Destination: ";
            cin >> loc;

            erv.dispatch(loc);
        }

        // ---------------- LOGS ----------------
        else if(ch == 10){
            logs.show();
        }

        // ---------------- ZONE ----------------
        else if(ch == 11){
            zone.classify(victims.critical());
        }
    }

    return 0;
}
