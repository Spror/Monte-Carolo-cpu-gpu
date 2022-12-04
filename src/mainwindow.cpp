#include "inc/mainwindow.h"
#include "./ui/ui_mainwindow.h"
#include"inc/qcustomplot.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

// add a basic graph before drawing and circle https://www.matmana6.pl/rownanie-okregu-na-plaszczyznie-kartezjanskiej
    auto a = 0, s = 0, radius = 1;

    QVector<double> x(101), y(101), y2(101); // initialize with entries 0..100
    for (auto i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = sqrt(radius*radius - x[i]*x[i]);
      y2[i] = -1*y[i];

    }

    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setData(x, y2);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange( -2.0, 2.0 );
    ui->customPlot->yAxis->setRange( -2.0, 2.0 );
    ui->customPlot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

