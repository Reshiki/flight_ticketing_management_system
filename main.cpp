#include "mainwindow.h"

#include <QApplication>

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

bool openDatabase() {
    // 连接数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("persondb");
    db.setUserName("root");
    db.setPassword("741456963");

    if (!db.open()) {
        qDebug() << "Error: Unable to connect to database!" << db.lastError();
        return false;
    }
    qDebug() << "Database connection established!";
    return true;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    openDatabase();
    MainWindow w;
    w.show();
    return a.exec();
}
