#ifndef ZONE_H
#define ZONE_H

#include <bits/stdc++.h>
using namespace std;

class ZoneSystem {
public:

    void classify(int victims) {

        cout << "\n🧭 DISASTER ZONE CLASSIFICATION\n";

        if(victims >= 50)
            cout << "🔴 RED ZONE (CRITICAL AREA)\n";

        else if(victims >= 20)
            cout << "🟡 YELLOW ZONE (MODERATE RISK)\n";

        else
            cout << "🟢 GREEN ZONE (SAFE AREA)\n";
    }
};

#endif
