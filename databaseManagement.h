#ifndef DATABASEMANAGEMENT_H
#define DATABASEMANAGEMENT_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QMap>
#include <QString>
#include <QDebug>

class DatabaseManager {
public:
    // 获取单例实例
    static DatabaseManager& instance() {
        static DatabaseManager instance;
        return instance;
    }

    // 添加数据库连接
    bool addDatabase(const QString &dbIdentifier, const QString &driver, const QString &host, int port,
                     const QString &dbName, const QString &user, const QString &password) {
        if (connections.contains(dbIdentifier)) {
            qDebug() << "Database connection with identifier" << dbIdentifier << "already exists.";
            return true; // 已经存在，无需重复添加
        }

        QSqlDatabase db = QSqlDatabase::addDatabase(driver, dbIdentifier);
        db.setHostName(host);
        db.setPort(port);
        db.setDatabaseName(dbName);
        db.setUserName(user);
        db.setPassword(password);

        if (!db.open()) {
            qDebug() << "Error: Unable to connect to database" << dbIdentifier << "!" << db.lastError();
            return false;
        }

        connections[dbIdentifier] = db;
        qDebug() << "Database connection" << dbIdentifier << "established!";
        return true;
    }

    // 获取数据库连接
    QSqlDatabase getDatabase(const QString &dbIdentifier) {
        if (connections.contains(dbIdentifier)) {
            return connections[dbIdentifier];
        }
        qDebug() << "Error: No database connection with identifier" << dbIdentifier;
        return QSqlDatabase();
    }

    // 关闭所有数据库连接
    void closeAllDatabases() {
        for (auto it = connections.begin(); it != connections.end(); ++it) {
            if (it.value().isOpen()) {
                it.value().close();
            }
        }
        connections.clear();
    }

private:
    QMap<QString, QSqlDatabase> connections;

    // 私有构造函数和析构函数，禁止拷贝和赋值
    DatabaseManager() {}
    ~DatabaseManager() { closeAllDatabases(); }
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;
};

#endif // DATABASEMANAGEMENT_H
