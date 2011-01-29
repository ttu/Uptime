#include "uptimestruct.h"

UptimeStruct::UptimeStruct()
{
    days = -1;
    hours = -1;
    mins = -1;
    secs = -1;
}

UptimeStruct::UptimeStruct(int d, int h, int m,int s)
{
    days = d;
    hours = h;
    mins = m;
    secs = s;

    totalInSec = d*60*60*24 + h*60*60 + m*60 ;
    if (secs != -1)
        totalInSec += s;
    saveTime = QDateTime::currentDateTime();
}

// Basic clock functionality
void UptimeStruct::tick()
{
    // Add 1 to secs
    secs += 1;

    if (secs >= 60)
    {
        secs -= 60;
        mins += 1;
        if (mins >= 60)
        {
            mins -= 60;
            hours += 1;
            if (hours >= 24)
            {
                hours -= 24;
                days += 1;
            }
        }
    }
}
