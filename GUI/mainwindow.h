#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "swapstring.h"
#include "widgetu.h"
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

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    swapstring *window;
    widgetu *window1;
};
#endif // MAINWINDOW_H
