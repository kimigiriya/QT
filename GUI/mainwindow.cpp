#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QtWidgets>
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QIcon>
#include <QPixmap>
#include <QString>

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

void MainWindow::on_pushButton_clicked()
{
    QApplication::quit();
}


void MainWindow::on_pushButton_3_clicked()
{
    hide();
    window = new swapstring(this);
    window->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    hide();
    window1 = new widgetu(this);
    window1->show();
}

