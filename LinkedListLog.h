#ifndef LOG_H
#define LOG_H
#include <bits/stdc++.h>
using namespace std;

class LogSystem {
public:
    vector<string> logs;

    string timeNow(){
        time_t now=time(0);
        return string(ctime(&now));
    }

    void add(string s){
        string entry = timeNow() + " -> " + s;
        logs.push_back(entry);
    }

    void show(){
        cout<<"\n📜 SYSTEM LOGS (TIMELINE)\n";
        for(auto &x:logs)
            cout<<"• "<<x;
    }
};
#endif
