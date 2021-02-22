#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>


const QString DEVICE_PC = QString("pc");
const QString DEVICE_RASPBERRY = QString("raspberry");

QCommandLineParser* setup_commandline_parser(){
    QCommandLineParser* clp = new QCommandLineParser();
    clp->setApplicationDescription("NonSpeaker QT Project");
    clp->addVersionOption();
    clp->addOption(QCommandLineOption("device", "The device on which the application runs","value","pc"));
    return clp;
}

bool is_raspberry(QStringList args, QCommandLineParser* clp){
    clp->process(args);
    if(clp->isSet("device")){
        QString device_type = clp->value("device");
        return device_type == DEVICE_RASPBERRY;
    }
    return false;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Parse Command Lines
    QCommandLineParser* clp = setup_commandline_parser();
    MainWindow w;

    if(is_raspberry(a.arguments(), clp)){
        w.showFullScreen();
        w.setCursor(Qt::BlankCursor);
    }else{
        w.show();
    }
    return a.exec();
}
