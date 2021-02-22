#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNonSpeaker_triggered()
{
    this->ui->stackedWidget->setCurrentIndex(ABOUT_PAGE);
}

void MainWindow::on_actionNetwork_triggered()
{
    this->ui->stackedWidget->setCurrentIndex(NETWORK_PAGE);
}

void MainWindow::on_actionSound_triggered()
{
    this->ui->stackedWidget->setCurrentIndex(SOUND_PAGE);
}

void MainWindow::on_actionSensors_triggered()
{
    this->ui->stackedWidget->setCurrentIndex(SENSORS_PAGE);
}

void MainWindow::on_actionCamera_triggered()
{
    this->ui->stackedWidget->setCurrentIndex(CAMERA_PAGE);
}
