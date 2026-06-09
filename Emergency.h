// Emergency.h

#ifndef EMERGENCY_H
#define EMERGENCY_H

struct Emergency {
    int id;
    int city;
    int severity;

    bool operator<(const Emergency &e) const {
        return severity < e.severity; // max heap
    }
};

#endif
