#include "altwindow.h"
#include "mainwindow.h"
#include <QDebug>

AltWindow::AltWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AltWindow)
{
    ui->setupUi(this);
    grabbedWidget = 0;
    connect(ui->backBtn, SIGNAL(clicked()), this, SLOT(close()));
}

AltWindow::~AltWindow()
{
    delete ui;
}

void AltWindow::closeEvent(QCloseEvent *event)
{
    ui->horizontalLayout->removeWidget(grabbedWidget);
    emit passWidget(grabbedWidget);
    grabbedWidget = 0;
    QMainWindow::closeEvent(event);
}

void AltWindow::receiveWidget(QWidget *widget)
{
    if(grabbedWidget != 0)
        qWarning() << "You might have lost a widget just now.";

    grabbedWidget = widget;
    ui->horizontalLayout->addWidget(grabbedWidget);
}

