#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class Person {
public:
    int id;
    QString username;
    QString password;
    QString phone;
    bool role; // 0代表User，1代表Administratro

    // 插入用户到数据库
    bool insertToDatabase();

    // 从数据库中查询用户
    static Person findByUsername(const QString &username);

    // 删除用户
    bool deleteFromDatabase();
};

#endif // PERSON_H
