#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <bits/stdc++.h>
using namespace std;

class Dashboard {
public:
    int totalVictims = 0;
    int criticalPatients = 0;
    int activeShelters = 0;
    int ervDeployed = 0;

    int foodPackets = 100;
    int waterBottles = 100;
    int medicineKits = 50;
    int blankets = 80;

    void showDashboard() {

        cout << "\n🚨 DISASTER CONTROL DASHBOARD\n";
        cout << "=================================\n";

        cout << "👥 Total Victims      : " << totalVictims << endl;
        cout << "🏥 Critical Patients  : " << criticalPatients << endl;
        cout << "🏠 Active Shelters    : " << activeShelters << endl;
        cout << "🚑 ERVs Deployed      : " << ervDeployed << endl;

        cout << "\n📦 RESOURCE STATUS\n";
        cout << "Food Packets   : " << foodPackets << endl;
        cout << "Water Bottles  : " << waterBottles << endl;
        cout << "Medicine Kits  : " << medicineKits << endl;
        cout << "Blankets       : " << blankets << endl;

        cout << "=================================\n";
    }
};

#endif
