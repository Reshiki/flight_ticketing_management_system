#include "mainwindow.h"
#include "databaseManagement.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DatabaseManager &dbManager = DatabaseManager::instance();
    if(dbManager.addDatabase("PersonDB", "QODBC", "127.0.0.1", 3306, "persondb", "root", "741456963")){
        qDebug() << "成功打开PersonDB数据库";
    } else{
        qDebug() <<  "打开PersonDB数据库失败";
    };
    if(dbManager.addDatabase("FlightDB", "QODBC", "127.0.0.1", 3306, "flightdb", "root", "741456963")){
        qDebug() << "成功打开FlightDB数据库";
    } else{
        qDebug() << "打开FlightDB数据库失败";
    };
    if(dbManager.addDatabase("OrderDB", "QODBC", "127.0.0.1", 3306, "orderdb", "root", "741456963")){
        qDebug() << "成功打开OrderDB数据库";
    } else{
        qDebug() << "打开OrderDB数据库失败";
    }
    MainWindow w;
    w.show();
    return a.exec();
}
