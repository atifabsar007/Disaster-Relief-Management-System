#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class LogSystem {
    string logs[100];
    int top = -1;

    string timeNow() {
        time_t t = time(0);
        string str = ctime(&t);
        str.erase(str.length() - 1); 
        return str;
    }

public:
    void add(string s) {
        if (top < 99) logs[++top] = timeNow() + " -> " + s;
    }

    void show() {
        cout << "\nRECENT LOGS (LIFO/Stack)\n";
        cout << "----------------------------------------\n";
        for (int i = top; i >= 0; i--) {
            cout << logs[i] << endl;
        }
    }
};
