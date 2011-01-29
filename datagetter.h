#ifndef DATAGETTER_H
#define DATAGETTER_H

#include <QProcess>
#include "uptimestruct.h"

class DataGetter
{
public:
    DataGetter();
    virtual UptimeStruct getData() = 0;

protected:
    QString processName;
    QString returnDataString();
};

class WinDataGetter  : public DataGetter
{
public:
    WinDataGetter();
    UptimeStruct getData();

private:
    UptimeStruct processData(QString data);
};

class UnixDataGetter  : public DataGetter
{
public:
    UnixDataGetter();
    UptimeStruct getData();

private:
    UptimeStruct processData(QString data);
};

#endif // DATAGETTER_H
