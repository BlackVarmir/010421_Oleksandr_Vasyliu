#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Створення таймера для оновлення часу кожну секунду
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    timer->start(1000);

    // Оновлення часу при запуску програми
    updateTime();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    // Отримання поточного часу
    QDateTime currentTime = QDateTime::currentDateTime();

    // Відображення часу у вікні програми
    ui->timeLabel->setText(currentTime.toString("hh:mm:ss"));
}
