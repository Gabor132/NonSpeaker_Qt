#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork/QNetworkInterface>

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

void MainWindow::set_network_page(){
    QList<QNetworkInterface> all_interfaces = QNetworkInterface::allInterfaces();
    foreach(QNetworkInterface item, all_interfaces){
        if(! item.isValid()){
            continue;
        }

        if(item.type() == QNetworkInterface::Ethernet){
            QList<QNetworkAddressEntry> addresses = item.addressEntries();
            this->ui->interface_name_value->setText(item.name());
            this->ui->ethernetBox->setEnabled(item.isValid());
            foreach(QNetworkAddressEntry entry, addresses){
                if(entry.ip().protocol() == QAbstractSocket::IPv4Protocol){
                    this->ui->ip_address_eth4_value->setText(entry.ip().toString());
                }else if(entry.ip().protocol() == QAbstractSocket::IPv6Protocol){
                    this->ui->ip_address_eth6_value->setText(entry.ip().toString());
                }
            }
        }else if(item.type() == QNetworkInterface::Wifi){
            this->ui->interface2_name_value->setText(item.name());
            this->ui->wirelessBox->setEnabled(item.isValid());
            QList<QNetworkAddressEntry> addresses = item.addressEntries();
            foreach(QNetworkAddressEntry entry, addresses){
                if(entry.ip().protocol() == QAbstractSocket::IPv4Protocol){
                    this->ui->ip_address_wifi4_value->setText(entry.ip().toString());
                }else if(entry.ip().protocol() == QAbstractSocket::IPv6Protocol){
                    this->ui->ip_address_wifi6_value->setText(entry.ip().toString());
                }
            }
        }

    }
}

void MainWindow::on_actionNetwork_triggered()
{
    this->set_network_page();
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
