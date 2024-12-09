#ifndef SWAPSTRING_H
#define SWAPSTRING_H

#include <QDialog>
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

namespace Ui {
class swapstring;
}

class swapstring : public QDialog
{
    Q_OBJECT

public:
    explicit swapstring(QWidget *parent = nullptr);
    ~swapstring();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::swapstring *ui;
};

#endif // SWAPSTRING_H
