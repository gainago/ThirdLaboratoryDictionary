#include "realtimeplot.h"
#include <qwt_arrow_button.h>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_directpainter.h>
#include <QPointF>
#include <qwt_series_data.h>
#include <QwtPlot>
#include <QwtPlotCurve>
#include <QwtSymbol>
#include <QwtScaleMap>
#include <QwtPlotDirectPainter>
#include <QPen>
#include <QwtPainter>
#include <QTimer>
#include <iostream>
#include <cmath>
#include <QVBoxLayout>
#include <QLabel>




RealTimePlot::RealTimePlot(int countObjects
                           , QVector<QString> names
                           , QVector<QString> colors
                           ,QString title)
{
    if(countObjects != names.size() || names.size() != colors.size()){
        throw "invalid size";
    }

    vectorData_.resize(countObjects);

    plot_ = new QwtPlot;

    //this->setAxisScale(QwtPlot::xBottom, -1, 1000000);
    //plot_->setAxisScale(QwtPlot::yLeft, 0, maxY);

    for(int i = 0; i < countObjects; i++){
        QwtPlotCurve* newCurve = new QwtPlotCurve("y(x)");
        newCurve->setStyle(QwtPlotCurve::Lines);
        newCurve->setPen(QPen(QColor(colors[i])));
        //newCurve->setCurveAttribute(QwtPlotCurve::Fitted);
        newCurve->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, Qt::NoBrush, QPen(QColor(colors[i])), QSize(1, 1)));
        vectorCurve_.append(newCurve);
    }

    wg_ = new QWidget;
    wg_->setWindowTitle(title);

    QString strLabel;

    for(int i = 0; i < countObjects; i++){
        strLabel += names[i] + ": " + colors[i] + "\t";
    }

    QLabel* labelPlotInfo = new QLabel(strLabel);

    QVBoxLayout* vLayout = new QVBoxLayout;
    vLayout->addWidget(labelPlotInfo);
    vLayout->addWidget(plot_);

    wg_->setLayout(vLayout);
    IsEndInput_ = 0;


}

void RealTimePlot::AddData(QVector<QPair<QPointF, bool> > newData)
{
    //std::cout << "newData.size = "<<  newData.size() << std::endl << "vectorData.size = " << vectorData_.size() << std::endl;
    if(IsEndInput_){
        throw "input has been ended";
    }
    if(newData.size() != vectorData_.size()){
        throw "invalid parametr";
    }

    for(int i = 0; i < vectorData_.size(); i++){
        if(newData[i].second == false){
            continue;
        }
        vectorData_[i].append(newData[i].first);
    }
}

RealTimePlot::~RealTimePlot()
{
    for(int i = 0; i < vectorCurve_.size(); i++){
        delete vectorCurve_[i];
    }

    vectorCurve_.resize(0);
}

void RealTimePlot::EndInput()
{
    IsEndInput_ = 1;
    //double xMax = -INFINITY;
    //double yMax = -INFINITY;
    for(int i = 0; i < vectorData_.size(); i++){ // в цикле по данным для всех графиков
        for(int j = 0; j < vectorData_[i].size(); j++){// пузырьковая сортировка

            /*if(xMax < vectorData_[i][j].rx()){      //находим максимальные значения для задания графиков
                xMax = vectorData_[i][j].rx();
            }

            if(yMax < vectorData_[i][j].ry()){
                yMax = vectorData_[i][j].ry();
            }*/

            for(int k = 0; k < vectorData_[i].size() - j - 1; k++){

                if(vectorData_[i][k].rx()
                    >  vectorData_[i][k + 1].rx() ){
                    QPointF tmpPoint;
                    tmpPoint = vectorData_[i][k];
                    vectorData_[i][k] = vectorData_[i][k + 1];
                    vectorData_[i][k + 1] = tmpPoint;

                }
            }
        }
    }
    // for(int i = 0; i < vectorData_[0].size(); i++){
    //     std::cout << "time " << i << ":= " << vectorData_[0][i].ry() << "\n";
    // }
    for(int i = 0; i < vectorCurve_.size(); i++){
        vectorCurve_[i]->setSamples(vectorData_[i]);
        vectorCurve_[i]->attach(plot_);
    }

    //plot_->setAxisScale(QwtPlot::xBottom, 0, xMax);
    //plot_->setAxisScale(QwtPlot::yRight, 0, yMax);
    zoomer_ = new ScrollZoomer(plot_->canvas());
    wg_->show();



}

