#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(0, Qt::FramelessWindowHint),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QCoreApplication::instance()->setApplicationName("Hildon-Desktop Uptime widget");

    // Get required atoms
    Atom winTypeAtom = XInternAtom(QX11Info::display(), "_NET_WM_WINDOW_TYPE", false);
    Atom homeAppletAto = XInternAtom(QX11Info::display(), "_HILDON_WM_WINDOW_TYPE_HOME_APPLET", false);
    Atom appletIDAtom = XInternAtom(QX11Info::display(), "_HILDON_APPLET_ID", false);
    Atom utf8Atom = XInternAtom(QX11Info::display(), "UTF8_STRING", false);
    Atom appletSettingAtom = XInternAtom(QX11Info::display(), "_HILDON_APPLET_SETTINGS", false);

    // Set correct window type
    XChangeProperty(QX11Info::display(), winId(), winTypeAtom, XA_ATOM, 32,
                    PropModeReplace, (unsigned char *) &homeAppletAto, 1);

    // Use application name to fill AppletID
    QByteArray id (QCoreApplication::instance()->applicationName().remove(' ').toUtf8());
    XChangeProperty(QX11Info::display(), winId(), appletIDAtom, utf8Atom, 8,
                    PropModeReplace, (unsigned char *)id.constData(), id.length());

    // Add setting button. This button is shown when hildon-desktop is in edit mode.
    //int settings = 0;
    //XChangeProperty(QX11Info::display(), winId(), appletSettingAtom, XA_CARDINAL, 32,
    //                PropModeReplace, (unsigned char*)&settings, 1);

    showLabels = true;
    showSeconds = true;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Widget::setDisplay(bool showSeconds, bool showLabels)
{
    this->showSeconds = showSeconds;
    this->showLabels = showLabels;

    setShowSeconds(showSeconds);
    setShowLabels(showLabels);
}

void Widget::thisSlot()
{}

void Widget::setShowSeconds(bool show)
{
    showSeconds = show;

    if (showSeconds)
    {
        if (showLabels)
            ui->lblSeconds->show();
        ui->label_4->show();
    }
    else
    {
        ui->lblSeconds->hide();
        ui->label_4->hide();
    }

    this->adjustSize();
}

void Widget::setShowLabels(bool show)
{
    showLabels = show;

    if (showLabels)
    {
        ui->lblDays->show();
        ui->lblHours->show();
        ui->lblMinutes->show();
        if (showSeconds)
            ui->lblSeconds->show();
    }
    else
    {
        ui->lblDays->hide();
        ui->lblHours->hide();
        ui->lblMinutes->hide();
        ui->lblSeconds->hide();
    }

    this->adjustSize();
}

void Widget::updateTime(int d, int h, int m, int s)
{
        ui->label->setText(QString::number(d));
            ui->label_2->setText(QString::number(h));
                ui->label_3->setText(QString::number(m));
                    ui->label_4->setText(QString::number(s));


}

void Widget::setDay(int i)
{



}

void Widget::setHour(int i)
{

}

void Widget::setMin(int i)
{

}

void Widget::setSec(int i)
{

}

