#ifndef TEACHERDIALOG_H
#define TEACHERDIALOG_H

#include <QDialog>
#include "Teacher.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TeacherDialog; }
QT_END_NAMESPACE

class TeacherDialog : public QDialog {
    Q_OBJECT

public:
    explicit TeacherDialog(QWidget *parent = nullptr);
    ~TeacherDialog();

signals:
    void teacherAdded(Teacher* teacher);

private slots:
    void on_createButton_clicked();

private:
    Ui::TeacherDialog *ui;
};

#endif // TEACHERDIALOG_H
