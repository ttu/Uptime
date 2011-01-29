#include <QtGui/QApplication>
#include "controller.h"

#include <QHBoxLayout>


//#include <X11/extensions/Xrender.h>

int main(int argc, char *argv[])
{
    qWarning("Please make sure you're running a composition manager!");
    Display *dpy = XOpenDisplay(0); // open default display
    if (!dpy) {
        qWarning("Cannot connect to the X server");
        exit(1);
    }

    QApplication a(dpy,argc, argv);

    Widget w;
    Controller c;

    QObject::connect(&c, SIGNAL(updateDisplay(bool,bool)),&w,SLOT(setDisplay(bool,bool)));
    QObject::connect(&c,SIGNAL(updateTime(int,int,int,int)),&w,SLOT(updateTime(int,int,int,int)));

    c.start();
    w.show();

    return a.exec();
}
