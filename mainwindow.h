#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
#include "altwindow.h"

namespace Ui {
    class MainWindow;
}

/**
 * Main window capable of passing and receiving widgets from
 * an alternative window. A widget can be passed via signal.
 * Part of the SeparateWindow project.
 *
 * A context menu is also available for try.
 *
 * @author Bence Magyar
 * @email mw.mzperx@gmail.com
 * @date 2011.07.26.
 * License: use it as you like but give credit.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void passWidget(QWidget *widget);

private slots:
    void on_separateBtn_clicked();
    void receiveWidget(QWidget *widget);

private:
    Ui::MainWindow *ui;
    AltWindow *altw;

    QAction *sepAct;
    bool widgetAtHome;

protected:
    void contextMenuEvent(QContextMenuEvent *event);

};

#endif // MAINWINDOW_H
