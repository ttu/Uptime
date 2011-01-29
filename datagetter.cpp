#include "datagetter.h"

DataGetter::DataGetter()
{
}

// Start process and get output to string
QString DataGetter::returnDataString()
{
    QByteArray out;
    QProcess process;
    QString retVal;

    try
    {
        process.start(processName);
        process.waitForFinished();

        out = process.readAllStandardOutput();
        retVal = QString(out);
    }
    catch(...)
    {
        retVal = QString::null;
    }

    return retVal;
}

WinDataGetter::WinDataGetter()
{
    this->processName = "SystemInfo.exe";
}

// Get output data from process and process it to object
UptimeStruct WinDataGetter::getData()
{
    QString data = this->returnDataString();

    UptimeStruct up;

    if (data != QString::null)
        up = processData(data);

    return up;
}

// Find needed info from output string and process it to object
UptimeStruct WinDataGetter::processData(QString data)
{
    // Needed data is in System Up Time:, next data is System Manufacturer..
    int startIndex = data.indexOf("System Up Time:");
    int endIndex = data.indexOf("System Manufacturer:");

    // At least should be.. if some "failure", just take next 300 after System Up time
    if (endIndex < startIndex)
        endIndex = startIndex + 300;

    QString newData = data.mid(startIndex, endIndex-startIndex);
    QStringList list = newData.split(" ");

    QString str;

    // Remove empty items from list
    foreach(str, list)
    {
        if (str.isEmpty())
            list.removeOne(str);
    }

    int d = list[3].toInt();
    int h = list[5].toInt();
    int m = list[7].toInt();
    int s = list[9].toInt();

    UptimeStruct *up = new UptimeStruct(d,h,m,s);

    return *up;
}

UnixDataGetter::UnixDataGetter()
{
    this->processName = "uptime";
}

// Get output data from process and process it to object
UptimeStruct UnixDataGetter::getData()
{
    //data = "7:24pm  up 1849 day(s),  3:20,  1 user,  load average: 0.00, 0.01, 0.01";
    QString data = this->returnDataString();

    UptimeStruct up;

    // Cant find or from crappy keyboard :P
    if (data != QString::null)
        if (data != "")
        up = processData(data);

    return up;
}

// Find needed info from output string and process it to object
// 23:59:37 up 1 day, 59 min,  3 users,  load average: 0.16, 0.23, 0.17
// 00:00:56 up 1 day,  1:00,  3 users,  load average: 0.18, 0.22, 0.17
// 00:01:20 up 1 min, 1 users..
// 00:01:20 up 1:34, 1 users..
UptimeStruct UnixDataGetter::processData(QString data)
{
    // ... up 2 day(s), 20:20, ...
    // ... up 20:20, ...
    int startIndex = data.indexOf("up");;
    int endIndex = data.indexOf(",");

    // get next ,
    if (data.contains("day"))
        endIndex = data.indexOf(",", endIndex+1);

    // At least should be.. if some "failure", just take next 30
    if (endIndex < startIndex)
        endIndex = startIndex + 30;

    QString newData = data.mid(startIndex, endIndex-startIndex);   
    QStringList list = newData.split(" ");

    // Remove empty items from list (should not be any)
    foreach(QString str, list)
    {
        if (str.isEmpty())
            list.removeOne(str);
    }

    // first element = up 2 days
    int d = 0;
    int h = 0;
    int m = 0;
    // seconds not in use with unix
    int s = -1;

    int counter = 1;

    if (newData.contains("day"))
    {
        d = list[counter].toInt();
        counter += 2;
    }

    if (newData.contains("min"))
    {
        m = list[counter].toInt();
    }
    else
    {
        QStringList hourMin = list[counter].split(":");
        h = hourMin[0].toInt();
        m = hourMin[1].toInt();
    }

    UptimeStruct *up = new UptimeStruct(d,h,m,s);

    return *up;
}
