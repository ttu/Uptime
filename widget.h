#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QPaintEvent>

#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <QtGui/QX11Info>

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void changeEvent(QEvent *e);

private:
    void setShowSeconds(bool showSeconds);
    void setShowLabels(bool showLabels);
    bool showLabels;
    bool showSeconds;
public slots:
    void thisSlot();
    void setDisplay(bool showSeconds, bool showLabels);
    void updateTime(int d, int h, int m, int s);
    void setDay(int i);
    void setHour(int i);
    void setMin(int i);
    void setSec(int i);
private:
    Ui::Widget *ui;
};



#endif // WIDGET_H
