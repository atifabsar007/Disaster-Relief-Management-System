#ifndef LOG_H
#define LOG_H

#include <bits/stdc++.h>
using namespace std;

class LogSystem {
public:
    vector<string> logs;

    string timeNow(){
        time_t t=time(0);
        return string(ctime(&t));
    }

    void add(string s){
        logs.push_back(timeNow()+" -> "+s);
    }

    void show(){
        cout << "\n📜 LOGS\n";
        for(auto &x:logs)
            cout << "• " << x;
    }
};

#endif
