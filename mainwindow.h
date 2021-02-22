#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkInterface>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNonSpeaker_triggered();

    void on_actionNetwork_triggered();

    void on_actionSound_triggered();

    void on_actionSensors_triggered();

    void on_actionCamera_triggered();

private:
    Ui::MainWindow *ui;

    const int ABOUT_PAGE = 0;
    const int NETWORK_PAGE = 1;
    const int SOUND_PAGE = 2;
    const int SENSORS_PAGE = 3;
    const int CAMERA_PAGE = 4;

    static const QList<QNetworkInterface> all_interfaces;
    void set_network_page();

};
#endif // MAINWINDOW_H
