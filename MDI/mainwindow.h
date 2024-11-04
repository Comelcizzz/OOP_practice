#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QSqlTableModel>
#include "SqliteDBManager.h"
#include "Student.h"
#include "Teacher.h"
#include "StudentDialog.h"
#include "TeacherDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addStudentButton_clicked();
    void on_addTeacherButton_clicked();
    void refreshStudentTable();
    void refreshTeacherTable();
    void showStudentDialog();
    void showTeacherDialog();
    void addStudent(Student* student);
    void addTeacher(Teacher* teacher);

private:
    Ui::MainWindow *ui;
    SqliteDBManager *dbManager;
    QSqlTableModel *studentModel;
    QSqlTableModel *teacherModel;
    StudentDialog *studentDialog;
    TeacherDialog *teacherDialog;
};

#endif // MAINWINDOW_H
