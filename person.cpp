#include "person.h"
#include "databaseManagement.h"

bool Person::insertToDatabase() {
    QSqlDatabase db = DatabaseManager::instance().getDatabase("PersonDB");
    QSqlQuery queryPerson(db);
    queryPerson.prepare("INSERT INTO users (username, password, email, phone) VALUES (:username, :password, :phone, :role)");
    queryPerson.bindValue(":username", username);
    queryPerson.bindValue(":password", password);
    queryPerson.bindValue(":phone", phone);
    queryPerson.bindValue(":role", role);
    if (!queryPerson.exec()) {
        qDebug() << "Insert failed:" << queryPerson.lastError().text();
        return false;
    }
    return true;
}

Person Person::findByUsername(const QString &username) {
    QSqlDatabase db = DatabaseManager::instance().getDatabase("PersonDB");
    QSqlQuery queryPerson(db);
    queryPerson.prepare("SELECT * FROM users WHERE username = :username");
    queryPerson.bindValue(":username", username);
    Person person;
    if (queryPerson.exec() && queryPerson.next()) {
        person.id = queryPerson.value("id").toInt();
        person.username = queryPerson.value("username").toString();
        person.password = queryPerson.value("password").toString();
        person.phone = queryPerson.value("phone").toString();
        person.role = queryPerson.value("role").toBool();
    }
    return person;
}

bool Person::deleteFromDatabase() {
    QSqlDatabase db = DatabaseManager::instance().getDatabase("PersonDB");
    QSqlQuery queryPerson(db);
    queryPerson.prepare("DELETE FROM users WHERE id = :id");
    queryPerson.bindValue(":id", id);
    if (!queryPerson.exec()) {
        qDebug() << "Delete failed:" << queryPerson.lastError().text();
        return false;
    }
    return true;
}
