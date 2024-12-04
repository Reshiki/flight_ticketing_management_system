#ifndef ORDER_H
#define ORDER_H

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class Order {
public:
    int id; // MySQL数据库的索引
    int userId;
    int flightId;
    QString orderDate;
    int price;

    // 向数据库加入订单信息
    bool insertToDatabase();

    // 通过id查询订单
    static QList<Order> findByUserId(int id);
};

#endif // ORDER_H
