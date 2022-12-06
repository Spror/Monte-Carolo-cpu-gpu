#include "inc/mainwindow.h"
#include "./ui/ui_mainwindow.h"
#include"inc/qcustomplot.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setupView();


}
void MainWindow::setupView()
{

    PrintCircle();
    ui->CPU_button->click();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    unsigned long  samples = ui->Samples->value();
    auto chosenMethod = Method::CPU;
    MonteCarlo obj;

    if(ui->GPU_button->isChecked())
    {
        chosenMethod = Method::GPU;
    }

    obj.calculatePi(samples, chosenMethod);

    printResults(obj);
    printPoints(obj);

}


void MainWindow::printResults(MonteCarlo simMonte)
{
    QString strPi, strTime, strErr;

    QTextStream(&strPi) << simMonte.returnCalculatedPI();
    QTextStream(&strTime) << simMonte.returnTime() << " s";
    QTextStream(&strErr) << simMonte.returnError();

    ui->Value->setText(strPi);
    ui->Time->setText(strTime);
    ui->Error->setText(strErr);
}

void MainWindow::PrintCircle()
{
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


 void MainWindow::printPoints(MonteCarlo simMonte)
 {
    ui->customPlot->clearGraphs();
    PrintCircle();

    ui->customPlot->addGraph();

    auto positivePoints= simMonte.returnPointIn();
    auto negativePoints= simMonte.returnPointOut();
    QVector<double> x ,y;

    for(auto &it: positivePoints)
    {
        x.push_back(it.x);
        y.push_back(it.y);
    }

    QPen pen;
    pen.setStyle(Qt::DotLine);
    pen.setColor(QColor(0,128,0));
    pen.setWidth(5);
    ui->customPlot->addGraph();
    ui->customPlot->graph(2)->setPen(pen);
    ui->customPlot->graph(2)->setData(x,y);

    QVector<double> x2 ,y2;
    for(auto &it: negativePoints)
    {
        x2.push_back(it.x);
        y2.push_back(it.y);
    }
    QPen pen2;
    pen2.setStyle(Qt::DotLine);
    pen2.setWidth(5);
    pen2.setColor(QColor(128,0,0));
    ui->customPlot->addGraph();
    ui->customPlot->graph(3)->setPen(pen2);
    ui->customPlot->graph(3)->setData(x2,y2);
    ui->customPlot->replot();


 }

