#include "mainwindow.h"
#include "Student.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonExit_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButtonCreate_clicked()
{
    int id = ui->lineEditId->text().toInt();
    QString lastName = ui->lineEditSecond->text();
    QString firstName = ui->lineEditFirst->text();
    QString middleName = ui->lineEditMidlle->text();
    QString birthDate = ui->lineEditBirth->text();
    QString phoneNumber = ui->lineEditPhone->text();
    QString faculty = ui->lineEditFaculty->text();
    int course = ui->lineEditCourse->text().toInt();
    QString group = ui->lineEditGroup->text();

    Student student(id, lastName.toStdString(), firstName.toStdString(),
                    middleName.toStdString(), birthDate.toStdString(),
                    phoneNumber.toStdString(),
                    faculty.toStdString(), course, group.toStdString());
    this->student = student;
}

void MainWindow::on_pushButtonShow_clicked()
{
        QMessageBox::information(this, "Student Information", QString::fromStdString(student.toString()));
}

