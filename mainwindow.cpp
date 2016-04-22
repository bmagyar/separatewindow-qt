#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    altw = 0;

    sepAct = new QAction(tr("&Separate"), this);
    sepAct->setStatusTip(tr("Make the red part pop out into another window."));
    connect(sepAct, SIGNAL(triggered()), this, SLOT(on_separateBtn_clicked()));
    widgetAtHome = true;
}

MainWindow::~MainWindow()
{
    if(altw != 0)
        delete altw;
    delete ui;
}

void MainWindow::on_separateBtn_clicked()
{
    ui->separateBtn->setEnabled(false);
    QWidget* red = ui->redWidget;
    ui->horizontalLayout->removeWidget(red);

    if(altw == 0)
    {
        altw = new AltWindow(this);
        connect(altw, SIGNAL(passWidget(QWidget*)), this, SLOT(receiveWidget(QWidget*)));
    }

    altw->receiveWidget(red);
    altw->show();
    widgetAtHome = false;
}

void MainWindow::receiveWidget(QWidget *widget)
{
    ui->horizontalLayout->addWidget(widget);
    ui->separateBtn->setEnabled(true);
    widgetAtHome = true;
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    if(widgetAtHome)
    {
        QMenu menu(this);
        menu.addAction(sepAct);
        menu.exec(event->globalPos());
    }
}

