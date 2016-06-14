/* *****************************************************
 * keysw.h
 *
 * Contains nothing.
 *
 * ****************************************************/
#include <QtGui>
#include <QObject>
#include <QPushButton>
#include <QLabel>


enum {
    KS_English = 0, KS_Russian, num_languages
};


class KeySwitcher : public QObject
{
    Q_OBJECT

    public slots:
        void switch_keyboard(void);

    public:
        KeySwitcher(QWidget *);   /* This constructor creates the dialog. */
        ~KeySwitcher(void);

    private:
        int current_language;
        QPushButton *KS_toggle_switch;
        QLabel *KS_banner;
        
};


