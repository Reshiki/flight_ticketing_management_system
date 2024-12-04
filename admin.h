#ifndef ADMIN_H
#define ADMIN_H

#include "person.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class Administrator : public Person {
public:
    // 管理人员信息
    bool addPerson(const Person &person);
    bool removePerson(int personId);

    // 管理航班信息
    bool addFlight(const QString &flightNumber, const QString &destination, const QString &departureTime);
    bool removeFlight(int flightId);

    // 管理订单信息
    bool addOrder(int userId, int flightId, const QString &orderDate);
    bool removeOrder(int orderId);
};

#endif // ADMIN_H
