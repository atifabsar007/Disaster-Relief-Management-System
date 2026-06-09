#ifndef MEDICALQUEUE_H
#define MEDICALQUEUE_H

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

    void addPatient(string name, int severity) {
        pq.push({name, severity});
    }

    void treatPatient() {

        if(pq.empty()) {
            cout << "No patients in queue!\n";
            return;
        }

        Patient p = pq.top();
        pq.pop();

        cout << "\n🏥 Treating Patient: " << p.name
             << " (Severity: " << p.severity << ")\n";
    }

    void show() {

        cout << "\n🏥 MEDICAL PRIORITY QUEUE\n";
        cout << "---------------------------------\n";

        priority_queue<Patient> temp = pq;

        while(!temp.empty()) {
            Patient p = temp.top();
            temp.pop();

            cout << p.name << " | Severity: " << p.severity << endl;
        }

        cout << "---------------------------------\n";
    }
};

#endif
