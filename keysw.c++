/* ********************************************************
 * keysw.c++
 *
 * (c) 2016 Robert Pascual
 *
 * ********************************************************/
#include <QBoxLayout>
#include <QString>
#include <QPushButton>
#include <QProcess>
#include <stdlib.h>
#include "keysw.h"

KeySwitcher::KeySwitcher(QWidget *parent)
{
    QBoxLayout *app_layout = new QBoxLayout(QBoxLayout::TopToBottom, parent);

    /* Now add the Widgets to the Layout */
    KS_banner = new QLabel("Press Button To Toggle Keyboard");
    app_layout->addWidget(KS_banner);

    current_language = KS_English;

    KS_toggle_switch = new QPushButton("English");
    connect(KS_toggle_switch, SIGNAL(clicked()), 
        this, SLOT(switch_keyboard()));

    app_layout->addWidget(KS_toggle_switch);
}

KeySwitcher::~KeySwitcher(void)
{
    delete KS_banner;
    delete KS_toggle_switch;
}

void KeySwitcher::switch_keyboard(void)
{
    current_language = (current_language + 1) % num_languages;
    QString en_switch_cmd = 
        QString("/usr/bin/setxkbmap "
                "-rules evdev "
                "-model evdev "
                "-layout us "
                "-variant altgr-intl");
    QString ru_switch_cmd = QString("/usr/bin/setxkbmap ru");

    switch (current_language) {
        case KS_English:
            system(qPrintable(en_switch_cmd));
            KS_toggle_switch->setText(QString("English"));
            break;
        case KS_Russian:
            system(qPrintable(ru_switch_cmd));
            KS_toggle_switch->setText(QString("Russian"));
            break;
    }
}

