#include "StudentDialog.h"
#include "ui_StudentDialog.h"

StudentDialog::StudentDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::StudentDialog) {
    ui->setupUi(this);
}

StudentDialog::~StudentDialog() {
    delete ui;
}

void StudentDialog::on_createButton_clicked() {
    string lastName = ui->lastNameLineEdit->text().toStdString();
    string firstName = ui->firstNameLineEdit->text().toStdString();
    string middleName = ui->middleNameLineEdit->text().toStdString();
    string birthDate = ui->birthDateLineEdit->text().toStdString();
    string phoneNumber = ui->phoneNumberLineEdit->text().toStdString();
    string faculty = ui->facultyLineEdit->text().toStdString();
    int course = ui->courseLineEdit->text().toInt();
    string group = ui->groupLineEdit->text().toStdString();

    Student *student = new Student(lastName, firstName, middleName, birthDate, phoneNumber, faculty, course, group);
    emit studentAdded(student);
    accept();
}
