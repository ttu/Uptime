#include "controller.h"

Controller::Controller(QObject *parent) :
QObject(parent)
{
    recordTotalInSec = 0;
    checkInterval = 10000;
    tickInterval = 1000;
    showSeconds = false;
    showLabels = true;

    fileLocation = getFileLocation();
    setFactory();
    myDataGetter = myFactory->returnDataGetter();

    updateTimer = new QTimer(this);
    updateTimer->setInterval(checkInterval);
    QObject::connect(updateTimer,SIGNAL(timeout()),this, SLOT(checkUptime()));

    if (showSeconds)
    {
        clockTimer = new QTimer(this);
        clockTimer->setInterval(tickInterval);
        QObject::connect(clockTimer,SIGNAL(timeout()),this, SLOT(tickUptime()));
    }
}

// Start timer and get first data
void Controller::start()
{
    emit updateDisplay(showSeconds, showLabels);
    updateTimer->start();
    this->checkUptime();
}

// Get Uptime data, save it to file and update widget
void Controller::checkUptime()
{
    if (showSeconds)
        clockTimer->stop();

    uptime = myDataGetter->getData();

    if (uptime.days == -1)
        return;

    saveToFile(&uptime);

    emit updateTime(uptime.days, uptime.hours, uptime.mins, uptime.secs);

    if (showSeconds)
        clockTimer->start();
}

void Controller::tickUptime()
{
    uptime.tick();

    emit updateTime(uptime.days, uptime.hours, uptime.mins, uptime.secs);
}

void Controller::setFactory()
{
    // Here should check system type and decide factory based on that
    //this->myFactory = new WindowsDataGetterFactory();
    this->myFactory = new UnixDataGetterFactory();
}

// Get .exe's path and add name of settings file
QString Controller::getFileLocation()
{
    QString location = QApplication::applicationDirPath() + QDir::separator() + "uptime.txt";
    return location;
}

// Format in file x|1:1:1:1|dd.mm.yyyy|hh:mm:ss
// Total in sec, d:h:m:s, date, time
void Controller::saveToFile(UptimeStruct* uptime)
{
    QStringList list;

    // If record data not fetched, get it
    if (recordTotalInSec == 0)
    {
        list = getRecordInfo();
        recordTotalInSec = list[0].toInt();
    }

    // Check if need to save uptime data
    if (recordTotalInSec > (*uptime).totalInSec)
        return;

    recordTotalInSec = (*uptime).totalInSec;

    QString saveString = getSaveString(uptime);
    saveRecordInfo(saveString);
}

// Get info from list
QStringList Controller::getRecordInfo()
{
    QStringList list;

    if (!QFile::exists(fileLocation))
    {
       list.append("0");
       return list;
    }

    QFile file(fileLocation);
    file.open(QIODevice::ReadOnly);

    QTextStream out(&file);
    QString st = out.readAll();

    file.close();

    list = st.split("|");

    return list;
}

// Save info to file
void Controller::saveRecordInfo(QString saveInfo)
{
    QFile file(fileLocation);
    file.open(QIODevice::WriteOnly);

    QTextStream out(&file);
    out << saveInfo;
    out.flush();

    file.close();
}

// Create info string to save
QString Controller::getSaveString(UptimeStruct *uptime)
{
    QString toSave = "";

    toSave.append(QString::number((*uptime).totalInSec) + "|");
    toSave.append(QString::number((*uptime).days) + ":");
    toSave.append(QString::number((*uptime).hours) + ":");
    toSave.append(QString::number((*uptime).mins) + ":");
    toSave.append(QString::number((*uptime).secs) + "|");
    toSave.append((*uptime).saveTime.toString("dd.MM.yyyy") + "|");
    toSave.append((*uptime).saveTime.toString("hh:mm:ss") + "|");

    return toSave;
}
