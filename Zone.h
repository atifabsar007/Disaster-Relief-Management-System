#ifndef ZONE_H
#define ZONE_H

#include <bits/stdc++.h>
using namespace std;

class ZoneSystem {
public:
    void classify(int v){
        cout<<"\n🧭 ZONE STATUS: ";
        if(v>50) cout<<"🔴 RED ZONE\n";
        else if(v>20) cout<<"🟡 YELLOW ZONE\n";
        else cout<<"🟢 GREEN ZONE\n";
    }
};

#endif
