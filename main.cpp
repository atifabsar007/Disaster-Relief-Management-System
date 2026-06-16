#include <iostream>
#include <string>

// Include all our custom header modules
#include "VictimSystem.h"
#include "ShelterSystem.h"
#include "MedicalSystem.h"
#include "VolunteerSystem.h"
#include "ERVSystem.h"
#include "LogSystem.h"
#include "SupplyAndDashboard.h"

using namespace std;

// Instantiate global objects from our headers
VictimList victims;
ShelterSystem shelters;
MedicalQueue medical;
SupplySystem supply;
VolunteerSystem volunteers;
ERVSystem erv;
LogSystem logs;
Dashboard dash;

int main() {
    int ch;
    while (true) {
        cout << "\n=================================\n";
        cout << "DISASTER RELIEF SYSTEM\n";
        cout << "=================================\n";
        cout << "1. Add Victim\n2. Show Victims\n3. Search Victim\n4. Dashboard\n";
        cout << "5. Add Shelter\n6. Medical Queue\n7. Supply Management\n";
        cout << "8. Volunteer Management\n9. ERV Management\n10. View Logs\n";
        cout << "0. Exit\nEnter your choice: ";
        cin >> ch;

        if (ch == 0) { cout << "Exiting System...\n"; break; }
        else if (ch == 1) {
            string n, g, c; int a, x;
            cout << "Name: "; cin >> n;
            cout << "Age: "; cin >> a;
            cout << "Gender: "; cin >> g;
            cout << "Condition (1.Critical 2.Serious 3.Minor): "; cin >> x;
            if (x == 1) c = "Critical"; else if (x == 2) c = "Serious"; else c = "Minor";

            string sh = shelters.autoAssign();
            cout << "Assigned Shelter: " << sh << endl;
            victims.add(n, a, g, c, sh);
            logs.add("Victim added: " + n);
        }
        else if (ch == 2) victims.show();
        else if (ch == 3) {
            string n; cout << "Enter name to search: "; cin >> n;
            victims.search(n);
        }
        else if (ch == 4) {
            dash.show(victims.count(), victims.critical(), shelters.active(), erv.busyCount(), volunteers.size(), supply.food, supply.water);
        }
        else if (ch == 5) {
            string n, l; int c;
            cout << "Shelter Name: "; cin >> n;
            cout << "Location: "; cin >> l;
            cout << "Capacity: "; cin >> c;
            shelters.add(n, l, c);
            logs.add("Shelter added: " + n);
        }
        else if (ch == 6) {
            cout << "\nMEDICAL QUEUE\n1. Add Patient\n2. Treat Next\n3. View All (Heap Sorted)\nChoice: ";
            int op; cin >> op;
            if (op == 1) {
                string n; int s;
                cout << "Patient Name: "; cin >> n;
                cout << "Severity (1-10): "; cin >> s;
                medical.add(n, s);
                logs.add("Patient added: " + n);
            } else if (op == 2) {
                medical.treat();
            } else if (op == 3) {
                medical.displayHeapSorted();
            }
        }
        else if (ch == 7) {
            cout << "\nSUPPLY MGT\n1. Use Food\n2. Use Water\n3. Use Meds\n4. Use Blanket\n5. Show\nChoice: ";
            int x; cin >> x;
            if (x == 1) supply.use("food"); else if (x == 2) supply.use("water");
            else if (x == 3) supply.use("med"); else if (x == 4) supply.use("blanket");
            else if (x == 5) supply.show();
        }
        else if (ch == 8) {
            cout << "\nVOLUNTEERS\n1. Add\n2. Show\nChoice: ";
            int x; cin >> x;
            if (x == 1) volunteers.add();
            else if (x == 2) volunteers.show();
        }
        else if (ch == 9) {
            cout << "\nERV MGT\n1. Add ERV\n2. Dispatch (Available locations: CityCenter, Suburb, Industrial, Hills)\n3. Show\nChoice: ";
            int op; cin >> op;
            if (op == 1) erv.add();
            else if (op == 2) {
                string d; cout << "Destination Map Target: "; cin >> d;
                erv.dispatch(d);
                logs.add("ERV Dispatched to " + d);
            }
            else if (op == 3) erv.show();
        }
        else if (ch == 10) logs.show();
        else {
            cout << "Invalid Option! Try again.\n";
        }
    }
    return 0;
}
