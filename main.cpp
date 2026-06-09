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
    cout << " DISASTER RELIEF SYSTEM\n";
    cout << "=================================\n";
    cout << "1. Add Victim\n";
    cout << "2. Show Victims\n";
    cout << "3. Dashboard\n";
    cout << "4. Shelter\n";
    cout << "5. Medical\n";
    cout << "6. Supply\n";
    cout << "7. Volunteer\n";
    cout << "8. ERV Dispatch\n";
    cout << "9. Logs\n";
    cout << "10. Zone Check\n";
    cout << "0. Exit\n";
    cout << "Enter: ";
}

int main(){
    int ch;

    while(true){
        menu();
        cin >> ch;

        if(ch==0) break;

        else if(ch==1){
            string n,g,c,s; int a;
            cout<<"Name Age Gender Condition Shelter:\n";
            cin>>n>>a>>g>>c>>s;
            victims.add(n,a,g,c,s);
            logs.add("Victim added: "+n);
        }

        else if(ch==2){
            victims.show();
        }

        else if(ch==3){
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

        else if(ch==4){
            string n,l; int c;
            cin>>n>>l>>c;
            shelters.add(n,l,c);
        }

        else if(ch==5){
            string n; int s;
            cin>>n>>s;
            medical.add(n,s);
            medical.treat();
        }

        else if(ch==6){
            string t;
            cin>>t;
            supply.use(t);
        }

        else if(ch==7){
            string n,s;
            cin>>n>>s;
            volunteers.add(n,s);
        }

        else if(ch==8){
            string id,l;
            cin>>id>>l;
            erv.add(id,l);
            erv.dispatch(l);
        }

        else if(ch==9){
            logs.show();
        }

        else if(ch==10){
            zone.classify(victims.critical());
        }
    }
}
