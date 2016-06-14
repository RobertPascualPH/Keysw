/* **********************************************************
 * app.c++
 *
 * Main application source unit for the Keysw utility.
 * 
 * (c) Robert Pascual 2016
 *
 * *********************************************************/
#include <QtGui>
#include <QBoxLayout>
#include <QApplication>
#include <QString>
#include "keysw.h"


int main (int argc, char *argv[])
{
    QApplication keyswapp(argc, argv);

    QWidget    *app_parent = new QWidget();
    KeySwitcher *ks = new KeySwitcher(app_parent);

    app_parent->show();
    return keyswapp.exec();
}

