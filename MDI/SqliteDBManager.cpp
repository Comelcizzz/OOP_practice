#include <SqliteDBManager.h>
#include <QDebug>
#include <QFile>
#include <QDateTime>

SqliteDBManager* SqliteDBManager::instance = nullptr;

SqliteDBManager::SqliteDBManager(const QString &dbName) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
}

SqliteDBManager* SqliteDBManager::getInstance(const QString &dbName) {
    if (instance == nullptr) {
        instance = new SqliteDBManager(dbName);
    }
    return instance;
}

void SqliteDBManager::connectToDataBase() {
    try {
        logError("Connecting to the database...");
        if (db.isOpen()) {
            logError("Database is already open.");
            return;
        }

        if (!db.open()) {
            QString errorMsg = "Failed to open database: " + db.lastError().text();
            logError(errorMsg);
            qCritical() << errorMsg;
            return;
        }
        logError("Database opened successfully.");
        this->createTables();
    } catch (const std::exception &e) {
        QString errorMsg = "Exception in connectToDataBase: " + QString::fromStdString(e.what());
        logError(errorMsg);
        qCritical() << errorMsg;
    }
}

QSqlDatabase& SqliteDBManager::getDB() {
    return db;
}

void SqliteDBManager::closeDataBase() {
    try {
        if (db.isOpen()) {
            db.close();
            logError("Database closed successfully.");
        }
    } catch (const std::exception &e) {
        QString errorMsg = "Exception in closeDataBase: " + QString::fromStdString(e.what());
        logError(errorMsg);
        qCritical() << errorMsg;
    }
}

bool SqliteDBManager::createTables() {
    try {
        QSqlQuery query;

        if (!query.exec("CREATE TABLE IF NOT EXISTS students ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                        "lastName TEXT NOT NULL, "
                        "firstName TEXT NOT NULL, "
                        "middleName TEXT NOT NULL, "
                        "birthDate TEXT NOT NULL, "
                        "phoneNumber TEXT NOT NULL, "
                        "faculty TEXT NOT NULL, "
                        "course INTEGER NOT NULL, "
                        "student_group TEXT NOT NULL)")) {
            QString errorMsg = "Error creating students table: " + query.lastError().text();
            logError(errorMsg);
            qCritical() << errorMsg;
            return false;
        }

        if (!query.exec("CREATE TABLE IF NOT EXISTS teachers ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                        "lastName TEXT NOT NULL, "
                        "firstName TEXT NOT NULL, "
                        "middleName TEXT NOT NULL, "
                        "birthDate TEXT NOT NULL, "
                        "phoneNumber TEXT NOT NULL, "
                        "cycleCommission TEXT NOT NULL)")) {
            QString errorMsg = "Failed to create teachers table: " + query.lastError().text();
            logError(errorMsg);
            qCritical() << errorMsg;
            return false;
        }

        logError("Tables created successfully.");
        return true;
    } catch (const std::exception &e) {
        QString errorMsg = "Exception in createTables: " + QString::fromStdString(e.what());
        logError(errorMsg);
        qCritical() << errorMsg;
        return false;
    }
}

bool SqliteDBManager::insertIntoTable(const Teacher& teacher) {
    try {
        QSqlQuery query;
        query.prepare("INSERT INTO teachers (lastName, firstName, middleName, birthDate, phoneNumber, cycleCommission) VALUES (:lastName, :firstName, :middleName, :birthDate, :phoneNumber, :cycleCommission)");

        query.bindValue(":lastName", QString::fromStdString(teacher.getLastName()));
        query.bindValue(":firstName", QString::fromStdString(teacher.getFirstName()));
        query.bindValue(":middleName", QString::fromStdString(teacher.getMiddleName()));
        query.bindValue(":birthDate", QString::fromStdString(teacher.getBirthDate()));
        query.bindValue(":phoneNumber", QString::fromStdString(teacher.getPhoneNumber()));
        query.bindValue(":cycleCommission", QString::fromStdString(teacher.getCycleCommission()));

        if (!query.exec()) {
            QString errorMsg = "Failed to insert teacher into table: " + query.lastError().text();
            logError(errorMsg);
            qCritical() << errorMsg;
            return false;
        }

        logError("Teacher inserted successfully.");
        return true;
    } catch (const std::exception &e) {
        QString errorMsg = "Exception in insertIntoTable (Teacher): " + QString::fromStdString(e.what());
        logError(errorMsg);
        qCritical() << errorMsg;
        return false;
    }
}

bool SqliteDBManager::insertIntoTable(const Student& student) {
    try {
        QSqlQuery query;
        query.prepare("INSERT INTO students (lastName, firstName, middleName, birthDate, phoneNumber, faculty, course, student_group) VALUES (:lastName, :firstName, :middleName, :birthDate, :phoneNumber, :faculty, :course, :student_group)"); // Changed "group" to "student_group"

        query.bindValue(":lastName", QString::fromStdString(student.getLastName()));
        query.bindValue(":firstName", QString::fromStdString(student.getFirstName()));
        query.bindValue(":middleName", QString::fromStdString(student.getMiddleName()));
        query.bindValue(":birthDate", QString::fromStdString(student.getBirthDate()));
        query.bindValue(":phoneNumber", QString::fromStdString(student.getPhoneNumber()));
        query.bindValue(":faculty", QString::fromStdString(student.getFaculty()));
        query.bindValue(":course", student.getCourse());
        query.bindValue(":student_group", QString::fromStdString(student.getGroup()));

        if (!query.exec()) {
            QString errorMsg = "Error inserting student: " + query.lastError().text();
            logError(errorMsg);
            qCritical() << errorMsg;
            return false;
        }

        logError("Student inserted successfully.");
        return true;
    } catch (const std::exception &e) {
        QString errorMsg = "Exception in insertIntoTable (Student): " + QString::fromStdString(e.what());
        logError(errorMsg);
        qCritical() << errorMsg;
        return false;
    }
}

void SqliteDBManager::logError(const QString &message) {
    QString logFilePath = "logfile.txt";
    QFile file(logFilePath);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qCritical() << "Could not open log file for writing: " << file.errorString();
        return;
    }

    QTextStream out(&file);
    out << QDateTime::currentDateTime().toString() << ": " << message << "\n";
    file.close();
    qDebug() << "Logged message to file:" << message;
}

SqliteDBManager::~SqliteDBManager() {
    closeDataBase();
}
