#include "admin.h"
#include "databaseManagement.h"

bool Administrator::addPerson(const Person &person) {
    QSqlDatabase db = DatabaseManager::instance().getDatabase("PersonDB");
    QSqlQuery queryPerson(db);
    queryPerson.prepare("INSERT INTO users (username, password, email, phone) VALUES (:username, :password, :phone, :role)");
    queryPerson.bindValue(":username", person.username);
    queryPerson.bindValue(":password", person.password);
    queryPerson.bindValue(":phone", person.phone);
    queryPerson.bindValue(":role", person.role);
    if (!queryPerson.exec()) {
        qDebug() << "Insert failed:" << queryPerson.lastError().text();
        return false;
    }
    return true;
}

bool Administrator::removePerson(int personId) {
    QSqlDatabase db = DatabaseManager::instance().getDatabase("PersonDB");
    QSqlQuery queryPerson(db);
    queryPerson.prepare("DELETE FROM users WHERE id = :id");
    queryPerson.bindValue(":id", personId);
    if (!queryPerson.exec()) {
        qDebug() << "Delete failed:" << queryPerson.lastError().text();
        return false;
    }
    return true;
}

bool Administrator::addFlight(const QString &flightNumber, const QString &destination, const QString &departureTime) {
    QSqlDatabase db = DatabaseManager::instance().getDatabase("PersonDB");
    QSqlQuery queryFlight(db);
    queryFlight.prepare("INSERT INTO flights (flight_number, destination, departure_time) VALUES (:flight_number, :destination, :departure_time)");
    queryFlight.bindValue(":flight_number", flightNumber);
    queryFlight.bindValue(":destination", destination);
    queryFlight.bindValue(":departure_time", departureTime);
    if (!queryFlight.exec()) {
        qDebug() << "Insert failed:" << queryFlight.lastError().text();
        return false;
    }
    return true;
}

bool Administrator::removeFlight(int flightId) {
    QSqlDatabase db = DatabaseManager::instance().getDatabase("PersonDB");
    QSqlQuery queryFlight(db);
    queryFlight.prepare("DELETE FROM flights WHERE id = :id");
    queryFlight.bindValue(":id", flightId);
    if (!queryFlight.exec()) {
        qDebug() << "Delete failed:" << queryFlight.lastError().text();
        return false;
    }
    return true;
}

bool Administrator::addOrder(int userId, int flightId, const QString &orderDate) {
    QSqlDatabase db = DatabaseManager::instance().getDatabase("PersonDB");
    QSqlQuery queryOrder(db);
    queryOrder.prepare("INSERT INTO orders (user_id, flight_id, order_date) VALUES (:user_id, :flight_id, :order_date)");
    queryOrder.bindValue(":user_id", userId);
    queryOrder.bindValue(":flight_id", flightId);
    queryOrder.bindValue(":order_date", orderDate);
    if (!queryOrder.exec()) {
        qDebug() << "Insert failed:" << queryOrder.lastError().text();
        return false;
    }
    return true;
}

bool Administrator::removeOrder(int orderId) {
    QSqlDatabase db = DatabaseManager::instance().getDatabase("PersonDB");
    QSqlQuery queryOrder(db);
    queryOrder.prepare("DELETE FROM orders WHERE id = :id");
    queryOrder.bindValue(":id", orderId);
    if (!queryOrder.exec()) {
        qDebug() << "Delete failed:" << queryOrder.lastError().text();
        return false;
    }
    return true;
}
