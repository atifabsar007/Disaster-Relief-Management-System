#ifndef MEDICAL_H
#define MEDICAL_H

#include <bits/stdc++.h>
using namespace std;

struct Patient {
    string name;
    int severity;

    bool operator<(const Patient& p) const {
        return severity < p.severity;
    }
};

class MedicalQueue {
public:
    priority_queue<Patient> pq;

    void add(string n,int s){
        pq.push({n,s});
    }

    void treat(){
        if(pq.empty()){
            cout<<"No Patients\n";
            return;
        }

        auto p=pq.top(); pq.pop();
        cout<<"\n🏥 TREATING PATIENT\n";
        cout<<"Name: "<<p.name<<" | Severity: "<<p.severity<<endl;
    }
};

#endif
