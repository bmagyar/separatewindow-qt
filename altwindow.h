#ifndef ALTWINDOW_H
#define ALTWINDOW_H

#include <QMainWindow>
#include "ui_altwindow.h"

namespace Ui{
    class AltWindow;
}

/**
 * Alternative window capable of receiving and returning widgets from
 * an other window. A widget can be returned via explicit call or implicitly
 * upon close of the alternative window.
 * Part of the SeparateWindow project.
 *
 * @author Bence Magyar
 * @email mw.mzperx@gmail.com
 * @date 2011.07.26.
 * License: use it as you like but give credit.
 */
class AltWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit AltWindow(QWidget *parent = 0);
    ~AltWindow();

private:
    Ui::AltWindow *ui;
    QWidget *grabbedWidget;
    void closeEvent(QCloseEvent *);
signals:
    void passWidget(QWidget* widget);

public slots:
    void receiveWidget(QWidget *widget);

};

#endif // ALTWINDOW_H
