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
    cout<<"\n=================================\n";
    cout<<" DISASTER RELIEF SYSTEM\n";
    cout<<"=================================\n";
    cout<<"1. Add Victim\n";
    cout<<"2. Show Victims\n";
    cout<<"3. Search Victim\n";
    cout<<"4. Dashboard\n";
    cout<<"5. Add Shelter\n";
    cout<<"6. Medical\n";
    cout<<"7. Supply\n";
    cout<<"8. Volunteer\n";
    cout<<"9. ERV Dispatch\n";
    cout<<"10. Logs\n";
    cout<<"11. Zone Check\n";
    cout<<"0. Exit\n";
    cout<<"Enter: ";
}

int main(){
    int ch;

    while(true){
        menu();
        cin>>ch;

        if(ch==0) break;

        else if(ch==1){
            string n,g,c;
            int a;

            cout<<"Name Age Gender:\n";
            cin>>n>>a>>g;

            cout<<"\nSelect Condition:\n1.Critical 2.Serious 3.Minor\n";
            int x; cin>>x;
            if(x==1) c="Critical";
            else if(x==2) c="Serious";
            else c="Minor";

            string shelter = shelters.autoAssign();

            victims.add(n,a,g,c,shelter);
            logs.add("Victim added: "+n);
        }

        else if(ch==2) victims.show();

        else if(ch==3){
            string n;
            cout<<"Enter Name: ";
            cin>>n;
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
            cout<<"Shelter Name Location Capacity:\n";
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
            int x;
            cout<<"1.Food 2.Water 3.Med 4.Blanket\n";
            cin>>x;

            if(x==1) supply.use("food");
            else if(x==2) supply.use("water");
            else if(x==3) supply.use("med");
            else supply.use("blanket");
        }

        else if(ch==8){
            string n,s;
            cin>>n>>s;
            volunteers.add(n,s);
        }

        else if(ch==9){
            string id,l;
            cin>>id>>l;
            erv.add(id,l);
            erv.dispatch(l);
        }

        else if(ch==10){
            logs.show();
        }

        else if(ch==11){
            zone.classify(victims.critical());
        }
    }
}
