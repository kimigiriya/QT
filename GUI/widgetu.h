#ifndef WIDGETU_H
#define WIDGETU_H

#include <QDialog>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QMap>

namespace Ui {
class widgetu;
}



class widgetu : public QDialog
{
    Q_OBJECT

public:
    explicit widgetu(QWidget *parent = nullptr);
    ~widgetu();

private slots:
    void on_pushButton_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::widgetu *ui;
};

#endif // WIDGETU_H
