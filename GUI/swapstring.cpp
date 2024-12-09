#include "swapstring.h"
#include "mainwindow.h"
#include "ui_swapstring.h"

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

swapstring::swapstring(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::swapstring)
{
    ui->setupUi(this);
}

swapstring::~swapstring()
{
    delete ui;
}

void swapstring::on_pushButton_clicked()
{
    QString st1 = ui->lineSt1->text();
    QString st2 = ui->lineSt2->text();
    QString button = ui->pushButton->text();

    if (button == "↓")
    {
        ui->lineSt2->setText(st2 + st1);
        ui->pushButton->setText("↑");
        ui->lineSt1->setText("");
    }
    else
    {
        ui->lineSt1->setText(st1 + st2);
        ui->pushButton->setText("↓");
        ui->lineSt2->setText("");
    }
}


void swapstring::on_pushButton_2_clicked()
{
    QApplication::quit();
}

