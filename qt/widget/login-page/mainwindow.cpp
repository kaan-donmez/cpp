#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(showTime()));
    timer->start();

    QDate date = QDate::currentDate();
    QString dateText = date.toString();
    ui->currentDate->setText(dateText);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTime()
{
    QTime time = QTime::currentTime();
    QString timeText = time.toString("hh : mm : ss");
    ui->currentTime->setText(timeText);
}

