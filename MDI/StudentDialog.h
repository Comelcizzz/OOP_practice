#ifndef STUDENTDIALOG_H
#define STUDENTDIALOG_H

#include <QDialog>
#include "Student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class StudentDialog; }
QT_END_NAMESPACE

class StudentDialog : public QDialog {
    Q_OBJECT

public:
    explicit StudentDialog(QWidget *parent = nullptr);
    ~StudentDialog();

signals:
    void studentAdded(Student* student);

private slots:
    void on_createButton_clicked();

private:
    Ui::StudentDialog *ui;
};

#endif // STUDENTDIALOG_H
