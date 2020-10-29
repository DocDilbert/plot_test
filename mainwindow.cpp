#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <noise/noise.h>
#include <noise/module/voronoi.h>
using namespace noise;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto& customPlot = ui->widget;
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100

    module::Voronoi myModule;
    

    for (int i=0; i<101; ++i)
    {
        x[i] = i/50.0 - 1; // x goes from -1 to 1
        y[i] = myModule.GetValue (x[i], 0.75, 0.50);

    }
    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    customPlot->xAxis->setRange(-1, 1);
    customPlot->yAxis->setRange(-1, 1);
    customPlot->setInteraction(QCP::iRangeDrag, true);
    customPlot->setInteraction(QCP::iRangeZoom, true);
    customPlot->setInteraction(QCP::iSelectPlottables, true);
    customPlot->setSelectionRectMode(QCP::srmZoom);
    customPlot->replot();

}

MainWindow::~MainWindow()
{
    delete ui;
}