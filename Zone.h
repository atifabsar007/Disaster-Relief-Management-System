#ifndef ZONE_H
#define ZONE_H

#include <bits/stdc++.h>
using namespace std;

class ZoneSystem {
public:
    void classify(int victims) {
        cout << "\n🧭 ZONE STATUS: ";

        if (victims > 50)
            cout << "🔴 RED ZONE (CRITICAL)\n";
        else if (victims > 20)
            cout << "🟡 YELLOW ZONE (MODERATE)\n";
        else
            cout << "🟢 GREEN ZONE (SAFE)\n";
    }
};

#endif
