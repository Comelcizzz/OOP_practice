#include "MainWindow.h"
#include "StudentDialog.h"
#include "TeacherDialog.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QListWidget>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setupUI();
}

MainWindow::~MainWindow() {
    qDeleteAll(teachers);
    qDeleteAll(students);
}

void MainWindow::setupUI() {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QPushButton *addStudentButton = new QPushButton("Create Student", this);
    QPushButton *addTeacherButton = new QPushButton("Create Teacher", this);
    QPushButton *showStudentListButton = new QPushButton("Show Students List", this);
    QPushButton *showTeacherListButton = new QPushButton("Show Teachers List", this);

    mainLayout->addWidget(addStudentButton);
    mainLayout->addWidget(addTeacherButton);
    mainLayout->addWidget(showStudentListButton);
    mainLayout->addWidget(showTeacherListButton);

    connect(addStudentButton, &QPushButton::clicked, this, &MainWindow::on_addStudentButton_clicked);
    connect(addTeacherButton, &QPushButton::clicked, this, &MainWindow::on_addTeacherButton_clicked);
    connect(showStudentListButton, &QPushButton::clicked, this, &MainWindow::on_showStudentListButton_clicked);
    connect(showTeacherListButton, &QPushButton::clicked, this, &MainWindow::on_showTeacherListButton_clicked);

    mdiArea = new QMdiArea(this);
    mainLayout->addWidget(mdiArea);
}

void MainWindow::on_addStudentButton_clicked() {
    StudentDialog *dialog = new StudentDialog(this);
    connect(dialog, &StudentDialog::studentAdded, this, [=](Student *student) {
        students.append(student);
    });
    dialog->exec();
}

void MainWindow::on_addTeacherButton_clicked() {
    TeacherDialog *dialog = new TeacherDialog(this);
    connect(dialog, &TeacherDialog::teacherAdded, this, [=](Teacher *teacher) {
        teachers.append(teacher);
    });
    dialog->exec();
}

void MainWindow::on_showStudentListButton_clicked() {
    QListWidget *studentListWidget = new QListWidget;
    for (const auto &student : students) {
        studentListWidget->addItem(student->toString().c_str());
    }

    QMdiSubWindow *subWindow = mdiArea->addSubWindow(studentListWidget);
    subWindow->setWindowTitle("Students List");
    subWindow->show();
}

void MainWindow::on_showTeacherListButton_clicked() {
    QListWidget *teacherListWidget = new QListWidget;
    for (const auto &teacher : teachers) {
        teacherListWidget->addItem(teacher->toString().c_str());
    }

    QMdiSubWindow *subWindow = mdiArea->addSubWindow(teacherListWidget);
    subWindow->setWindowTitle("Teachers List");
    subWindow->show();
}
