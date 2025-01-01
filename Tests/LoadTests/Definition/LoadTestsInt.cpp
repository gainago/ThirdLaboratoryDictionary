#include <QVector>
#include <QString>
#include <QPointF>
#include <QPair>
#include <chrono>
#include <QApplication>

#include <unordered_map>

#include "Dictionary.h"
#include "GetHashCode.h"
#include "realtimeplot.h"
#include "SetRandomInt.h"



int LoadTestsInt(int argc, char** argv)
{
    
    
    QApplication app(argc, argv);

    QVector<QString> names;
    names.append("Append(MyDictionary)");
    names.append("Get(MyDictionary)");
    names.append("Remove(MyDictionary)");
    names.append("Append(std::unordered_map)");
    names.append("Get(std::unordered_map)");
    names.append("Remove(std::unordered_map)");

    QVector<QString> colors;
    colors.append("red");
    colors.append("blue");
    colors.append("magenta");
    colors.append("green");
    colors.append("cyan");
    colors.append("yellow");

    RealTimePlot* loadTestsPlot = new RealTimePlot(6, names, colors, "LoadTestsDictionaryInt");

    QVector<QPair<QPointF, bool> > newData(6);

    int smootingFactor = 600; 

    for(int i = 50000; i <=1000000; i+=50000){
        Dictionary<int, int> dictionary(GetHashCodeInt);
        std::unordered_map<int, int> map;
        /*auto start = std::chrono::high_resolution_clock::now();*/
        SetRandomIntMyDictionary(i, dictionary);
        SetRandomIntUnorderedMap(i, map);
        /*auto end = std::chrono::high_resolution_clock::now();        
        std::chrono::duration<double> diff = end - start;
        std::cout << "allocate " << i << " is " << std::chrono::duration<double>(diff).count() << "\n";*/

        double timeAppendMyDictionary = 0;
        double timeGetMyDictionary = 0;
        double timeRemoveMyDictionary = 0;
        double timeAppendunordered_map = 0;
        double timeGetunordered_map = 0;
        double timeRemoveunordered_map = 0;


        {
        auto start = std::chrono::high_resolution_clock::now();

        for(int j = -1; j >=-smootingFactor; j--){
            dictionary.Add(j, i);
        }        
        
        auto end = std::chrono::high_resolution_clock::now();        
        std::chrono::duration<double> diff = end - start;
        timeAppendMyDictionary = std::chrono::duration<double>(diff).count();
        }


        {
        auto start = std::chrono::high_resolution_clock::now();

        for(int j = -1; j >=-smootingFactor; j--){
            //dictionary.Add(j, i);
            map[j] = i;
        }        
        
        auto end = std::chrono::high_resolution_clock::now();        
        std::chrono::duration<double> diff = end - start;
        timeAppendunordered_map = std::chrono::duration<double>(diff).count();
        }

        {
        auto start = std::chrono::high_resolution_clock::now();   
        for(int j = -1; j >=-smootingFactor; j--){
            dictionary.Get(j);
        }        
        //dictionary.Get(-1);
        auto end = std::chrono::high_resolution_clock::now();        
        std::chrono::duration<double> diff = end - start;
        timeGetMyDictionary = std::chrono::duration<double>(diff).count();
        }

        {
        auto start = std::chrono::high_resolution_clock::now();   
        for(int j = -1; j >=-smootingFactor; j--){
            //dictionary.Get(j);
            int tmpValue = map[j];
        }        
        //dictionary.Get(-1);
        auto end = std::chrono::high_resolution_clock::now();        
        std::chrono::duration<double> diff = end - start;
        timeGetunordered_map = std::chrono::duration<double>(diff).count();
        }

        {
        auto start = std::chrono::high_resolution_clock::now();
        for(int j = -1; j >=-smootingFactor; j--){
            dictionary.Remove(j);
        }            
        
        auto end = std::chrono::high_resolution_clock::now();        
        std::chrono::duration<double> diff = end - start;
        timeRemoveMyDictionary = std::chrono::duration<double>(diff).count();
        }

        {
        auto start = std::chrono::high_resolution_clock::now();
        for(int j = -1; j >=-smootingFactor; j--){
            //dictionary.Remove(j);
            map.erase(j);
        }            
        
        auto end = std::chrono::high_resolution_clock::now();        
        std::chrono::duration<double> diff = end - start;
        timeRemoveunordered_map = std::chrono::duration<double>(diff).count();
        }

        /*std::cout << "time Append = " << timeAppend << "\n";
        std::cout << "time Append = " << timeGet << "\n";
        std::cout << "time Append = " << timeRemove << "\n";*/

        newData[0] = QPair<QPointF, bool>(QPointF(i, timeAppendMyDictionary / smootingFactor) , true);
        newData[1] = QPair<QPointF, bool>(QPointF(i, timeGetMyDictionary / smootingFactor), true);
        newData[2] = QPair<QPointF, bool>(QPointF(i, timeRemoveMyDictionary / smootingFactor), true);
        newData[3] = QPair<QPointF, bool>(QPointF(i, timeAppendunordered_map / smootingFactor) , true);
        newData[4] = QPair<QPointF, bool>(QPointF(i, timeGetunordered_map / smootingFactor), true);
        newData[5] = QPair<QPointF, bool>(QPointF(i, timeRemoveunordered_map / smootingFactor), true);

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