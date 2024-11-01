#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "Student.h"
#include "Teacher.h"

class QMdiArea;
class QListWidget;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addStudentButton_clicked();
    void on_addTeacherButton_clicked();
    void on_showStudentListButton_clicked();
    void on_showTeacherListButton_clicked();

private:
    void setupUI();
    QMdiArea *mdiArea;
    QList<Student*> students;
    QList<Teacher*> teachers;
};

#endif // MAINWINDOW_H
