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

int main (int argc, char *argv[])
{
    QApplication keyswapp(argc, argv);

    QWidget    *app_parent = new QWidget();
    QBoxLayout *app_layout = new QBoxLayout(QBoxLayout::TopToBottom, app_parent);


    /* Now add the Widgets to the Layout */
    QLabel *banner = new QLabel("Simple Keyboard Switching Utility");
    app_layout->addWidget(banner);

    QPushButton *toggle_switch = new QPushButton("Toggle");
    app_layout->addWidget(toggle_switch);

    app_parent->show();
    return keyswapp.exec();
}

