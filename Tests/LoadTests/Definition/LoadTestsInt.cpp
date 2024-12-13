#include <QVector>
#include <QString>
#include <QPointF>
#include <QPair>
#include <chrono>
#include <QApplication>

#include "Dictionary.h"
#include "GetHashCode.h"
#include "realtimeplot.h"
#include "SetRandomInt.h"


int LoadTestsInt(int argc, char** argv)
{
    QApplication app(argc, argv);

    QVector<QString> names;
    names.append("Append");
    names.append("Get");
    names.append("Remove");

    QVector<QString> colors;
    colors.append("red");
    colors.append("blue");
    colors.append("magenta");

    RealTimePlot* loadTestsPlot = new RealTimePlot(3, names, colors, "LoadTestsDictionaryInt");

    QVector<QPair<QPointF, bool> > newData(3);

    int smootingFactor = 600; 

    for(int i = 50000; i <=1000000; i+=50000){
        Dictionary<int, int> dictionary(GetHashCodeInt);
        /*auto start = std::chrono::high_resolution_clock::now();
        SetRandomInt(i, dictionary);
        auto end = std::chrono::high_resolution_clock::now();        
        std::chrono::duration<double> diff = end - start;
        std::cout << "allocate " << i << " is " << std::chrono::duration<double>(diff).count() << "\n";*/

        double timeAppend = 0;
        double timeGet = 0;
        double timeRemove = 0;


        {
        auto start = std::chrono::high_resolution_clock::now();

        for(int j = -1; j >=-smootingFactor; j--){
            dictionary.Add(j, i);
        }        
        
        auto end = std::chrono::high_resolution_clock::now();        
        std::chrono::duration<double> diff = end - start;
        timeAppend = std::chrono::duration<double>(diff).count();
        }

        {
        auto start = std::chrono::high_resolution_clock::now();   
        for(int j = -1; j >=-smootingFactor; j--){
            dictionary.Get(j);
        }        
        dictionary.Get(-1);
        auto end = std::chrono::high_resolution_clock::now();        
        std::chrono::duration<double> diff = end - start;
        timeGet = std::chrono::duration<double>(diff).count();
        }

        {
        auto start = std::chrono::high_resolution_clock::now();
        for(int j = -1; j >=-smootingFactor; j--){
            dictionary.Remove(j);
        }            
        
        auto end = std::chrono::high_resolution_clock::now();        
        std::chrono::duration<double> diff = end - start;
        timeRemove = std::chrono::duration<double>(diff).count();
        }

        /*std::cout << "time Append = " << timeAppend << "\n";
        std::cout << "time Append = " << timeGet << "\n";
        std::cout << "time Append = " << timeRemove << "\n";*/

        newData[0] = QPair<QPointF, bool>(QPointF(i, timeAppend / smootingFactor) , true);
        newData[1] = QPair<QPointF, bool>(QPointF(i, timeGet / smootingFactor), true);
        newData[2] = QPair<QPointF, bool>(QPointF(i, timeRemove / smootingFactor), true);

        try{
        loadTestsPlot->AddData(newData);
        }
        catch(const char* message)
        {
            std::cout << message << std::endl;
        }
    }

    loadTestsPlot->EndInput();
    return app.exec();

}