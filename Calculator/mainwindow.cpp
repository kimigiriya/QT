#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

double firstNumber;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));

    connect(ui->pushButton_plus_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(operations()));

    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    QString result;
    double allNumders;

    if(ui->result_show->text().contains('.') and button->text() == "0") {
        result = ui->result_show->text() + button->text();
    }
    else {
        allNumders = (ui->result_show->text() + button->text()).toDouble();
        result = QString::number(allNumders, 'g', 15);
    }

    ui->result_show->setText(result);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result_show->text().contains('.')))
        ui->result_show->setText(ui->result_show->text() + '.');
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();

    QString result;
    double allNumders;

    if(button->text() == "+/-") {
        allNumders = (ui->result_show->text()).toDouble();
        allNumders = allNumders * -1;
        result = QString::number(allNumders, 'g', 15);

        ui->result_show->setText(result);
    }
    else if(button->text() == "%") {
        allNumders = (ui->result_show->text()).toDouble();
        allNumders = allNumders * 0.01;
        result = QString::number(allNumders, 'g', 15);

        ui->result_show->setText(result);
    }
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();
    firstNumber = ui->result_show->text().toDouble();

    ui->result_show->setText("");
    button->setChecked(true);
}

void MainWindow::on_pushButton_c_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);

    ui->result_show->setText("0");
}

void MainWindow::on_pushButton_equal_clicked()
{
    double resultNumber, secondNumber;
    QString result;

    secondNumber = ui->result_show->text().toDouble();

    if(ui->pushButton_plus->isChecked()) {
        resultNumber = firstNumber + secondNumber;
        result = QString::number(resultNumber, 'g', 15);

        ui->result_show->setText(result);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked()) {
        resultNumber = firstNumber - secondNumber;
        result = QString::number(resultNumber, 'g', 15);

        ui->result_show->setText(result);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_multiply->isChecked()) {
        resultNumber = firstNumber * secondNumber;
        result = QString::number(resultNumber, 'g', 15);

        ui->result_show->setText(result);
        ui->pushButton_multiply->setChecked(false);
    }
    else if(ui->pushButton_divide->isChecked()) {
        if(secondNumber == 0) {
            QMessageBox::warning(this, "Ошибка", "Недьзя делить на ноль!");
        }
        else {
            resultNumber = firstNumber / secondNumber;
            result = QString::number(resultNumber, 'g', 15);

            ui->result_show->setText(result);
            ui->pushButton_divide->setChecked(false);
        }
    }
}

