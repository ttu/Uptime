#ifndef UPTIMESTRUCT_H
#define UPTIMESTRUCT_H

#include <QDateTime>

// Was struct int the beginning.. After refactoring, just objct named Struct.
class UptimeStruct
{
public:
    UptimeStruct();
    UptimeStruct(int d, int h, int m, int s);
    void tick();
    int days;
    int hours;
    int mins;
    int secs;
    int totalInSec;
    QDateTime saveTime;
};

#endif // UPTIMESTRUCT_H
