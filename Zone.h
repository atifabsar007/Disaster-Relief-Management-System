#ifndef ZONE_H
#define ZONE_H

#include <bits/stdc++.h>
using namespace std;

class ZoneSystem {
public:
    void classify(int v){
        cout << "\n🧭 ZONE: ";
        if(v>50) cout << "🔴 RED\n";
        else if(v>20) cout << "🟡 YELLOW\n";
        else cout << "🟢 GREEN\n";
    }
};

#endif
