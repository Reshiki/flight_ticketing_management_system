#ifndef FLIGHT_H
#define FLIGHT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class Flight {
public:
    int id; // MySQL数据库中的索引
    QString flightNumber;
    QString departure;
    QString destination;
    QString departureTime;
    QString arrivalTime;

    // 通过id来查询航班信息
    Flight findById(int id);
};

#endif // FLIGHT_H
