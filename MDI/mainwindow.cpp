#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    dbManager = SqliteDBManager::getInstance("database.db");
    dbManager->connectToDataBase();

    studentModel = new QSqlTableModel(this, dbManager->getDB());
    studentModel->setTable("students");
    studentModel->select();
    ui->studentTableView->setModel(studentModel);

    teacherModel = new QSqlTableModel(this, dbManager->getDB());
    teacherModel->setTable("teachers");
    teacherModel->select();
    ui->teacherTableView->setModel(teacherModel);

    studentDialog = new StudentDialog(this);
    teacherDialog = new TeacherDialog(this);

    connect(studentDialog, &StudentDialog::studentAdded, this, &MainWindow::addStudent);
    connect(teacherDialog, &TeacherDialog::teacherAdded, this, &MainWindow::addTeacher);
}

MainWindow::~MainWindow() {
    dbManager->closeDataBase();
    delete ui;
    delete studentDialog;
    delete teacherDialog;
}

void MainWindow::on_addStudentButton_clicked() {
    showStudentDialog();
}

void MainWindow::on_addTeacherButton_clicked() {
    showTeacherDialog();
}

void MainWindow::showStudentDialog() {
    studentDialog->show();
}

void MainWindow::showTeacherDialog() {
    teacherDialog->show();
}

void MainWindow::addStudent(Student* student) {
    if (dbManager->insertIntoTable(*student)) {
        refreshStudentTable();
    }
}

void MainWindow::addTeacher(Teacher* teacher) {
    if (dbManager->insertIntoTable(*teacher)) {
        refreshTeacherTable();
    }
}

void MainWindow::refreshStudentTable() {
    studentModel->select();
}

void MainWindow::refreshTeacherTable() {
    teacherModel->select();
}
