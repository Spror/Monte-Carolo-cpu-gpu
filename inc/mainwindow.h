#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "inc/MonteCarlo.hpp"
#include <QString>
#include <QPen>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void printResults(MonteCarlo simMonte);
    void printPoints(MonteCarlo simMonte);
    void PrintCircle();
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void setupView();
};




#endif // MAINWINDOW_H
