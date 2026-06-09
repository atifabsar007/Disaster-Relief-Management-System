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

void menu(){
    cout << "\n=================================\n";
    cout << " 🌍 DISASTER RELIEF SYSTEM\n";
    cout << "=================================\n";
    cout << "1. Add Victim\n";
    cout << "2. Show Victims\n";
    cout << "3. Search Victim\n";
    cout << "4. Dashboard\n";
    cout << "5. Add Shelter\n";
    cout << "6. Add Medical Case\n";
    cout << "7. Supply System\n";
    cout << "8. Add Volunteer\n";
    cout << "9. ERV System\n";
    cout << "10. View Logs\n";
    cout << "11. Zone Check\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
}

int main(){
    int ch;

    while(true){
        menu();
        cin >> ch;

        if(ch==0) break;

        // ---------------- VICTIM ----------------
        else if(ch==1){
            string n,g,c;
            int a;

            cout << "\n👤 NAME: "; cin >> n;
            cout << "AGE: "; cin >> a;

            cout << "\nGENDER (M/F): ";
            cin >> g;

            cout << "\nCONDITION:\n";
            cout << "1. Critical 🔴\n2. Serious 🟡\n3. Minor 🟢\n";
            int x; cin >> x;

            if(x==1) c="Critical";
            else if(x==2) c="Serious";
            else c="Minor";

            string sh = shelters.autoAssign();

            cout << "🏠 Assigned Shelter: " << sh << endl;

            victims.add(n,a,g,c,sh);
            logs.add("Victim added: " + n);
        }

        // ---------------- SHELTER ----------------
        else if(ch==5){
            string n,l;
            int c;

            cout << "\n🏠 SHELTER NAME: "; cin >> n;
            cout << "LOCATION: "; cin >> l;
            cout << "CAPACITY: "; cin >> c;

            shelters.add(n,l,c);
        }

        // ---------------- VOLUNTEER ----------------
        else if(ch==8){
            volunteers.add();
            logs.add("Volunteer added");
        }

        // ---------------- ERV ----------------
        else if(ch==9){
            int op;
            cout << "\n1. Add ERV\n2. Dispatch ERV\nChoice: ";
            cin >> op;

            if(op==1){
                erv.add();
                logs.add("ERV added");
            }
            else{
                string dest;
                cout << "Enter Destination: ";
                cin >> dest;

                erv.dispatch(dest);
                logs.add("ERV dispatched");
            }
        }

        // ---------------- DASHBOARD ----------------
        else if(ch==4){
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

        // ---------------- OTHER SYSTEMS ----------------
        else if(ch==2) victims.show();

        else if(ch==3){
            string n;
            cout << "Enter Name: ";
            cin >> n;
            victims.search(n);
        }

        else if(ch==10) logs.show();

        else if(ch==11) zone.classify(victims.critical());

        else if(ch==6){
            string n; int s;
            cin >> n >> s;
            medical.add(n,s);
            medical.treat();
        }

        else if(ch==7){
            int x;
            cout << "\n1.Food 2.Water 3.Med 4.Blanket\n";
            cin >> x;

            if(x==1) supply.use("food");
            else if(x==2) supply.use("water");
            else if(x==3) supply.use("med");
            else supply.use("blanket");
        }
    }
}
