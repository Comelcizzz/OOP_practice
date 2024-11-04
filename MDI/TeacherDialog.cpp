#include "TeacherDialog.h"
#include "ui_TeacherDialog.h"

TeacherDialog::TeacherDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::TeacherDialog) {
    ui->setupUi(this);
}

TeacherDialog::~TeacherDialog() {
    delete ui;
}

void TeacherDialog::on_createButton_clicked() {
    string lastName = ui->lastNameLineEdit->text().toStdString();
    string firstName = ui->firstNameLineEdit->text().toStdString();
    string middleName = ui->middleNameLineEdit->text().toStdString();
    string birthDate = ui->birthDateLineEdit->text().toStdString();
    string phoneNumber = ui->phoneNumberLineEdit->text().toStdString();
    string cycleCommission = ui->cycleCommissionLineEdit->text().toStdString();

    Teacher *teacher = new Teacher(lastName, firstName, middleName, birthDate, phoneNumber, cycleCommission);
    emit teacherAdded(teacher);
    accept();
}
