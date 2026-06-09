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
    cout << "1. Add Victim\n2. Show Victims\n3. Search\n4. Dashboard\n";
    cout << "5. Add Shelter\n6. Medical\n7. Supply\n8. Volunteer\n";
    cout << "9. ERV\n10. Logs\n11. Zone\n0. Exit\n";
    cout << "Enter: ";
}

int main(){
    int ch;

    while(true){
        menu();
        cin >> ch;

        if(ch==0) break;

        else if(ch==1){
            string n,g,c;
            int a;

            cout<<"Name: "; cin>>n;
            cout<<"Age: "; cin>>a;
            cout<<"Gender: "; cin>>g;

            cout<<"Condition (1.Critical 2.Serious 3.Minor): ";
            int x; cin>>x;

            if(x==1) c="Critical";
            else if(x==2) c="Serious";
            else c="Minor";

            string sh = shelters.autoAssign();
            cout<<"Assigned Shelter: "<<sh<<endl;

            victims.add(n,a,g,c,sh);
            logs.add("Victim added");
        }

        else if(ch==2) victims.show();

        else if(ch==3){
            string n; cin>>n;
            victims.search(n);
        }

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

        else if(ch==5){
            string n,l; int c;
            cin>>n>>l>>c;
            shelters.add(n,l,c);
        }

        else if(ch==6){
            string n; int s;
            cin>>n>>s;
            medical.add(n,s);
            medical.treat();
        }

        else if(ch==7){
            int x; cin>>x;
            if(x==1) supply.use("food");
            else if(x==2) supply.use("water");
            else if(x==3) supply.use("med");
            else supply.use("blanket");
        }

        else if(ch==8){
            volunteers.add();
        }

        else if(ch==9){
            int op;
            cin>>op;

            if(op==1) erv.add();
            else{
                string d;
                cin>>d;
                erv.dispatch(d);
            }
        }

        else if(ch==10) logs.show();

        else if(ch==11) zone.classify(victims.critical());
    }
}
