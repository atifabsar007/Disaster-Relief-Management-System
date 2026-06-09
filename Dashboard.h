#ifndef DASH_H
#define DASH_H

#include <bits/stdc++.h>
using namespace std;

class Dashboard {
public:
    void show(int v,int c,int sh,int erv,int vol,int f,int w){
        cout<<"\n🚨 DASHBOARD\n";
        cout<<"Victims: "<<v<<endl;
        cout<<"Critical: "<<c<<endl;
        cout<<"Shelters: "<<sh<<endl;
        cout<<"ERV Busy: "<<erv<<endl;
        cout<<"Volunteers: "<<vol<<endl;
        cout<<"Food: "<<f<<" Water: "<<w<<endl;
    }
};

#endif
