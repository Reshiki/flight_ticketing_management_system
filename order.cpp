#include "order.h"
#include "databaseManagement.h"

QList<Order> Order::findByUserId(int userId) {
    QSqlDatabase db = DatabaseManager::instance().getDatabase("OrderDB");
    QSqlQuery query(db);
    query.prepare("SELECT * FROM orders WHERE user_id = :user_id");
    query.bindValue(":user_id", userId);
    QList<Order> orders;
    if (query.exec()) {
        while (query.next()) {
            Order order;
            order.id = query.value("id").toInt();
            order.userId = query.value("user_id").toInt();
            order.flightId = query.value("flight_id").toInt();
            order.orderDate = query.value("order_date").toString();
            order.price = query.value("price").toInt();
            orders.append(order);
        }
    }
    return orders;
}

bool Order::insertToDatabase() {
    QSqlDatabase db = DatabaseManager::instance().getDatabase("OrderDB");
    QSqlQuery query(db);
    query.prepare("INSERT INTO orders (user_id, flight_id, order_date) VALUES (:user_id, :flight_id, :order_date :price)");
    query.bindValue(":user_id", userId);
    query.bindValue(":flight_id", flightId);
    query.bindValue(":order_date", orderDate);
    query.bindValue(":price", price);
    if (!query.exec()) {
        qDebug() << "Insert failed:" << query.lastError().text();
        return false;
    }
    return true;
}
