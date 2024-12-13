#ifndef REALTIMEPLOT_H
#define REALTIMEPLOT_H

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_directpainter.h>
#include <QPointF>
#include "QScrollBar"
#include "ScrollZoomer.h"
#include <QVector>
#include <QPair>
#include <QString>



class RealTimePlot : public QObject
{
    Q_OBJECT
private:


public:
    RealTimePlot(int countObjects
                , QVector<QString> names
                 , QVector<QString> colors
                 , QString title);
    void AddData(QVector<QPair<QPointF, bool> > newData);
    void EndInput();
    ~RealTimePlot();


private:
    QwtPlot* plot_;
    QWidget* wg_;
    bool IsEndInput_;
    ScrollZoomer *zoomer_;
    QVector<QVector<QPointF > > vectorData_;
    QVector<QwtPlotCurve*> vectorCurve_;

};

#endif // REALTIMEPLOT_H
