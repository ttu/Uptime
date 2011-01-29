#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QSysInfo>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QApplication>
#include <QTimer>
#include <QObject>

#include "widget.h"
#include "datagetter.h"
#include "datagetterfactory.h"
#include "uptimestruct.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller(QObject *parent = 0);
    void start();
private:
    void setFactory();
    void saveToFile(UptimeStruct* uptime);
    QString getFileLocation();
    QStringList getRecordInfo();
    QString getSaveString(UptimeStruct *uptime);
    void saveRecordInfo(QString saveInfo);

    DataGetterFactory *myFactory;
    DataGetter *myDataGetter;
    int recordTotalInSec;
    QString fileLocation;
    QTimer* updateTimer;
    QTimer* clockTimer;
    int checkInterval;
     int tickInterval;
    bool showSeconds;
    bool showLabels;
    UptimeStruct uptime;

signals:
    void mySignal();
   void updateTime(int d, int h, int m, int s);
   void updateDisplay(bool showSeconds, bool showLabels);
private slots:
    void checkUptime();
    void tickUptime();
};

// Example on interface for UI. Not used, yet..
class IUserInterface
{
public:
    virtual void SetDay(int i);
    virtual void SetHour(int i);
    virtual void SetMin(int i);
    virtual void SetSec(int i);
    virtual void ShowSeconds(bool show);
    virtual void ShowLabels(bool show);
    virtual void Show();
};

#endif // CONTROLLER_H
