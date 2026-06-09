#ifndef LOG_H
#define LOG_H

#include <bits/stdc++.h>
using namespace std;

class LogSystem {
public:
    vector<string> logs;

    void add(string s) {
        logs.push_back(s);
    }

    void show() {

        cout << "\n📜 SYSTEM LOGS\n";
        cout << "---------------------------------\n";

        for(string s : logs)
            cout << "• " << s << endl;

        cout << "---------------------------------\n";
    }
};

#endif
