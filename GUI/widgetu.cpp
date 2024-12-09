#include "widgetu.h"
#include "mainwindow.h"
#include "ui_widgetu.h"
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

widgetu::widgetu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::widgetu)
{
    ui->setupUi(this);
}

widgetu::~widgetu()
{
    delete ui;
}

void widgetu::on_pushButton_clicked()
{
    QApplication::quit();
}


void widgetu::on_checkBox_stateChanged(int arg1)
{
    ui->label->setVisible(not(arg1 == Qt::Checked));
    ui->lineEdit->setVisible(not(arg1 == Qt::Checked));
    ui->pushButton->setVisible(not(arg1 == Qt::Checked));
}


