#ifndef SQLITEDBMANAGER_H
#define SQLITEDBMANAGER_H

#include <QFile>
#include <QTextStream>
#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QDateTime>
#include <QSqlError>
#include "Teacher.h"
#include "Student.h"

class SqliteDBManager {
public:
    static SqliteDBManager* getInstance(const QString &dbName);
    void connectToDataBase();
    QSqlDatabase& getDB();
    void closeDataBase();
    bool createTables();
    bool insertIntoTable(const Teacher& teacher);
    bool insertIntoTable(const Student& Studnet);
    ~SqliteDBManager();

private:
    SqliteDBManager(const QString &dbName);
    static SqliteDBManager* instance;
    QSqlDatabase db;
    void logError(const QString &message);
};

#endif // SQLITEDBMANAGER_H
