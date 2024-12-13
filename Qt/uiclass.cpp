
#include "qapplication.h"
#include <QGridLayout>
#include <QRect>
#include <QScreen>
#include <QTabWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QComboBox>
#include <QLineEdit>
#include <QTextDocumentWriter>
#include <QDebug>
#include <QFileSystemModel>
#include <QTreeView>
#include <QFileInfo>
#include <QMessageBox>
#include <iostream>
#include <QRandomGenerator>
#include <chrono>
#include <QVector>
#include <QPair>
#include <QPointF>

#include "syntaxhighlighter.h"
#include "getqstringfromnewwidget.h"
#include "uiclass.h"
#include "QWidget"
//#include "PrintSeq.h"
#include "memberofmodel.h"
//#include "uiclassprintgraphics.h"
#include "gethashqstring.h"
#include "checkqstring.h"
#include "checkqstringkey.h"
#include "realtimeplot.h"


UIClass::UIClass() :
    model_(new DirectoryTableModel(0)),
    viewModel_(new QTableView) {


    //viewModel_->show();

    dictionary_ = new Dictionary<QString, QString>(GetHashQString);
    screen_ = new QRect(QApplication::screens().at(0)->geometry());
//---------------------------------- Main Pages-------------
    mainPageFirst_= new QWidget;
    mainPageSecond_ = new QWidget;

    mainPageFirst_->resize(QSize(screen_->width() / 3, screen_->height() / 2));
    mainPageSecond_->resize(QSize(screen_->width() / 3, screen_->height() / 2));

    mainPageFirst_->move(screen_->width() / 5, screen_->height() / 5);
    mainPageSecond_->move(screen_->width() / 5, screen_->height() / 5);

    QGridLayout* gridLayoutFirst = new QGridLayout;
    QGridLayout* gridLayoutSecond = new QGridLayout;

    QHBoxLayout* hLayoutFirst = new QHBoxLayout;
    QHBoxLayout* hLayoutSecond = new QHBoxLayout;

    QWidget* widgetTopFirst = new QWidget;
    widgetBottomFirst_ = new QWidget;
    QWidget* widgetTopSecond = new QWidget;
    QWidget* widgetBottomSecond = new QWidget;
    QWidget* widgetText = new QWidget;
    QWidget* widgetFileHierarhy = new QWidget;

    QPushButton* pushButtonToFirstFromFirst = new QPushButton("first page");
    QPushButton* pushButtonToSecondFromFirst = new QPushButton("second page");
    QPushButton* pushButtonToFirstFromSecond = new QPushButton("first page");
    QPushButton* pushButtonToSecondFromSecond = new QPushButton("second page");

    connect(pushButtonToFirstFromFirst, SIGNAL(clicked(bool))
            , this, SLOT(slotOpenFirstWindow()));
    connect(pushButtonToSecondFromFirst, SIGNAL(clicked(bool))
            , this, SLOT(slotOpenSecondWindow()));
    connect(pushButtonToFirstFromSecond, SIGNAL(clicked(bool))
            , this, SLOT(slotOpenFirstWindow()));
    connect(pushButtonToSecondFromSecond, SIGNAL(clicked(bool))
            , this, SLOT(slotOpenSecondWindow()));

    hLayoutFirst->addWidget(pushButtonToFirstFromFirst);
    hLayoutFirst->addWidget(pushButtonToSecondFromFirst);

    hLayoutSecond->addWidget(pushButtonToFirstFromSecond);
    hLayoutSecond->addWidget(pushButtonToSecondFromSecond);

    gridLayoutFirst->addWidget(widgetTopFirst, 0, 0);
    gridLayoutFirst->addLayout(hLayoutFirst, 1, 0);
    gridLayoutFirst->addWidget(widgetBottomFirst_, 2, 0);

    gridLayoutSecond->addWidget(widgetTopSecond, 0, 0);
    gridLayoutSecond->addLayout(hLayoutSecond, 1, 0);
    gridLayoutSecond->addWidget(widgetBottomSecond, 2, 0);

    mainPageFirst_->setLayout(gridLayoutFirst);
    mainPageSecond_->setLayout(gridLayoutSecond);


mainPageFirst_->show();
    //mainPageSecond_->show();
//---------------------------------- First Page-------------

    QGridLayout* gridLayoutButtonsFirst = new QGridLayout;
    QGridLayout* gridLayoutTextFirst = new QGridLayout;

    QPushButton* pushButtonAutomaticallyCreateData = new QPushButton("Automatically"
                                                                     "Create Data");
    QPushButton* pushButtonWriteDataToFile = new QPushButton("writeDataToFile");
    pushButtonChooseFileToSort_ = new QPushButton("chooseFile");
    pushButtonChooseFileToSort_->setCheckable(true);

    QPushButton* pushButtonPrintDictionary = new QPushButton("printDictionary");


    connect(pushButtonAutomaticallyCreateData, SIGNAL(clicked(bool))
            , this, SLOT(slotAutomaticallyCreateData()));
    connect(pushButtonChooseFileToSort_, SIGNAL(toggled(bool))
            , this, SLOT(slotChooseFile(bool)));
    connect(pushButtonWriteDataToFile, SIGNAL(clicked(bool))
            , this, SLOT(slotWriteDataToFile()));
    connect(pushButtonPrintDictionary, SIGNAL(clicked(bool))
            , this, SLOT(slotPrintDictionary()));

    gridLayoutButtonsFirst->addWidget(pushButtonWriteDataToFile, 0, 0);
    gridLayoutButtonsFirst->addWidget(pushButtonAutomaticallyCreateData, 0, 1);
    gridLayoutButtonsFirst->addWidget(pushButtonChooseFileToSort_, 1, 0);
    gridLayoutButtonsFirst->addWidget(pushButtonPrintDictionary, 1, 1);

    gridLayoutButtonsFirst->setSpacing(0);
    gridLayoutButtonsFirst->setVerticalSpacing(0);
    gridLayoutButtonsFirst->setHorizontalSpacing(10);

   // widgetTopFirst->setFixedSize(mainPageFirst_->size().rwidth(), mainPageFirst_->size().rheight()/5);
    //QPalette pal(QPalette::Window, Qt::green);
    //widgetTopFirst->setAutoFillBackground(true);
    //widgetTopFirst->setPalette(pal);
   // widgetTopFirst->setContentsMargins(10, 10, 10, 10);

    widgetTopFirst->setLayout(gridLayoutButtonsFirst);
    widgetTopFirst->repaint();

    //widgetBottomFirst->setFixedSize(mainPageFirst_->size().rwidth(), mainPageFirst_->size().rheight() * 3/5);

    textEditFirst_ = new QTextEdit;
    SyntaxHighlighter* pHighlighter = new SyntaxHighlighter(textEditFirst_->document());

    //QPushButton* pushButtonStartSort = new QPushButton("StartSort");
    QPushButton* pushButtonAdd = new QPushButton("Add");
    QPushButton* pushButtonGet = new QPushButton("Get");
    QPushButton* pushButtonRemove = new QPushButton("Remove");

    connect(pushButtonAdd, SIGNAL(clicked(bool))
            , this, SLOT(slotAdd()));
    connect(pushButtonGet, SIGNAL(clicked(bool))
            , this, SLOT(slotGet()));
    connect(pushButtonRemove, SIGNAL(clicked(bool))
            , this, SLOT(slotRemove()));

    QHBoxLayout* hButtonsLayout = new QHBoxLayout;

    hButtonsLayout->addWidget(pushButtonAdd);
    hButtonsLayout->addWidget(pushButtonGet);
    hButtonsLayout->addWidget(pushButtonRemove);

    textEditFirst_->resize(widgetBottomFirst_->size().rwidth(), widgetBottomFirst_->size().rheight() * 4/5);

    fileSystemModel_ = new QFileSystemModel;
    treeViewFileSystemModel_ = new QTreeView;
    fileSystemModel_->setRootPath(QDir::currentPath());
    treeViewFileSystemModel_->setModel(fileSystemModel_);
    treeViewFileSystemModel_->setRootIndex(fileSystemModel_->index(QDir::currentPath()));
    treeViewFileSystemModel_->resize(screen_->width() / 3, screen_->height() / 2);
    treeViewFileSystemModel_->move(screen_->width() * 3/5, screen_->height() / 5);
    fileSystemModel_->setNameFilters(QStringList() << "*.txt");
    fileSystemModel_->setReadOnly(false);

    connect(treeViewFileSystemModel_, SIGNAL(clicked(QModelIndex))
            , this, SLOT(slotOpenFile(QModelIndex)));


    //connect(treeViewFileSystemModel_, SIGNAL()
    //        , this, SLOT(slotSetUncheckedToggleButton()));

    gridLayoutTextFirst->addWidget(textEditFirst_, 0, 0);
    gridLayoutTextFirst->addLayout(hButtonsLayout, 1, 0);


    widgetBottomFirst_->setLayout(gridLayoutTextFirst);

    widgetBottomFirst_->repaint();


//---------------------------------- Second Page-------------


    QGridLayout* gridLayoutButtonsSecond = new QGridLayout;
    QGridLayout* gridLayoutModelSecond = new QGridLayout;

    QPushButton* pushButtonPrintGraphics = new QPushButton("PrintGraphics");

    connect(pushButtonPrintGraphics, SIGNAL(clicked(bool))
            , this, SLOT(slotPrintGraphics()));

    gridLayoutButtonsSecond->addWidget(pushButtonPrintGraphics, 0, 0);

    //gridLayoutButtonsFirst->setRowStretch(0, mainPageFirst_->size().rwidth()/10);
    //gridLayoutButtonsFirst->setColumnStretch(0, mainPageFirst_->size().rheight()/10);
    //gridLayoutButtonsFirst->setHorizontalSpacing(mainPageFirst_->size().rwidth()/20);
    //gridLayoutButtonsFirst->setVerticalSpacing(5);
    //gridLayoutButtonsFirst->rowStretch(10);
    gridLayoutButtonsSecond->setSpacing(0);
    gridLayoutButtonsSecond->setVerticalSpacing(0);
    gridLayoutButtonsSecond->setHorizontalSpacing(10);

    widgetTopSecond->setLayout(gridLayoutButtonsSecond);

    //widgetTopFirst->repaint();
    viewModel_->setModel(model_);

    gridLayoutModelSecond->addWidget(viewModel_, 0, 0);
    //gridLayoutTextFirst->addWidget(pushButtonStartSort, 1, 0);
    widgetBottomSecond->setLayout(gridLayoutModelSecond);



    //widgetBottomSecond->repaint();
    mainPageSecond_->repaint();

}

// void UIClass::slotSetUncheckedToggleButton()
// {
//     qDebug() << "OOO";
//     pushButtonChooseFileToSort_->setChecked(false);
// }

void UIClass::slotOpenFirstWindow()
{
    mainPageSecond_->hide();
    mainPageFirst_->show();
}

void UIClass::slotOpenSecondWindow()
{
    mainPageFirst_->hide();
    mainPageSecond_->show();
}

void UIClass::slotAutomaticallyCreateData()
{
    getQStringFromNewWidget* obj = new getQStringFromNewWidget;
    connect(obj, SIGNAL(ButtonPushed(QString))
            , this, SLOT(slotAutomaticallyCreateDataFinal(QString)));
    obj->getString("Enter number of objects", "append");
}

void UIClass::slotAutomaticallyCreateDataFinal(QString strNumber)
{
    bool isNumber = 1;
    int number;
    number = strNumber.toInt(&isNumber, 10);
    if(!isNumber)
    {
        QWidget* wg = new QWidget;
        QMessageBox::critical(wg, "Pay Attention"
                              , "You have to enter int");
        return;
    }

    for(int i = 0; i < number; i++)
    {
        textEditFirst_->append(GetRandomString() + ' ' + GetRandomString());
    }
}
void UIClass::slotWriteDataToFile()
{
    //mainPageFirst_->setEnabled(false);
    //mainPageSecond_->setEnabled(false);

    getQStringFromNewWidget* obj = new getQStringFromNewWidget;
    connect(obj, SIGNAL(ButtonPushed(QString))
            , this, SLOT(slotWriteDataToFileFinal(QString)));
    obj->getString("Enter file name", "Set");

}

void UIClass::slotWriteDataToFileFinal(QString str)
{
    if(QFile::exists(str + ".txt")){

        QWidget* wg = new QWidget;
        QMessageBox::critical(wg, "Pay Attention"
                             , "You already have file with the same name");
        return;
    }
    QTextDocumentWriter writer;
    writer.setFormat("txt");
    writer.setFileName(str + ".txt");

    writer.write(textEditFirst_->document());

    mainPageFirst_->setEnabled(true);
    mainPageSecond_->setEnabled(true);
}

void UIClass::slotChooseFile(bool arg)
{
    if(arg)
        treeViewFileSystemModel_->show();
    else
        treeViewFileSystemModel_->hide();
}

void UIClass::slotOpenFile(QModelIndex index)
{
    QFileInfo fileInfo = fileSystemModel_->fileInfo(index);
    qDebug() << fileInfo.fileName() << "OOOO";

    textEditFirst_->clear();
    char charBuffer[1024];
    QFile fileToOpen(fileInfo.absoluteFilePath());
    fileToOpen.open(QFile::ReadOnly);


    if(fileToOpen.isOpen()){
        int sizeWritten = fileToOpen.readLine(charBuffer
                                              , sizeof(charBuffer));
        while(sizeWritten != -1)
        {
            qDebug() << charBuffer;
            if(charBuffer[sizeWritten - 1] == '\n'){ //reaffile has '\n'
                                                        //append has '\n'
                charBuffer[sizeWritten - 1]  = '\0';
            }
            textEditFirst_->append(charBuffer);

            sizeWritten = fileToOpen.readLine(charBuffer
                                                  , sizeof(charBuffer));
        }
        textEditFirst_->repaint();
        fileToOpen.close();
    }
    else{
        qDebug() << "could not open file\n" << fileInfo.absoluteFilePath();
    }

}


/*void UIClass::slotStartSort()
{
    /*if((int)currentSorter_ == 0){
        QWidget* wg = new QWidget;
        QMessageBox::critical(wg, "Pay Attention"
                              , "You have to choose Sorter");

        return;
    }

    QString strFullPlaneText = textEditFirst_->toPlainText();
    QStringList strListWithSpace = strFullPlaneText.split('\n');
    QStringList strList;
    for(int i = 0 ; i < strListWithSpace.size(); i++)
    {
        if(!strListWithSpace.at(i).isEmpty())
        {
            strList.append(strListWithSpace.at(i));
        }
    }

    MutableArraySequence<int>* mutArraySeqToSort;

    try{
     mutArraySeqToSort =
        new MutableArraySequence<int>(strList.size());
    }
    catch(...){
        QWidget* wg = new QWidget;
        QMessageBox::critical(wg, "Oops"
                              , "the program can not pick out Sequence");
        delete mutArraySeqToSort;
        return;
    }

    for(int i = 0; i < strList.size(); i++)
    {
        bool isNumber = 1;
        int number = 0;
        number = strList.at(i).toInt(&isNumber, 10);
        if(!isNumber)
        {
            QWidget* wg = new QWidget;
            QMessageBox::critical(wg, "Pay Attention"
                                  , "You data has wrong format");
            delete mutArraySeqToSort;
            return;
        }
        mutArraySeqToSort->Set(i, number);
    }

    //PrintSeq(mutArraySeqToSort);


    ClassToSortInt tmpClass;
    memberOfModel resultSlot(currentSorter_, tmpClass.Sort(mutArraySeqToSort, currentSorter_), mutArraySeqToSort->GetLength());

    int currentRow = model_->rowCount(model_->index(0, 0));
    model_->insertRows(currentRow, 1);

    QModelIndex index(model_->index(currentRow, 0));
    qDebug() << index.row() << "\t" << index.column() << "\n";

    model_->setData(model_->index(currentRow , 0), (int)resultSlot.getSorter(), Qt::EditRole);
    model_->setData(model_->index(currentRow , 1), resultSlot.getTime(), Qt::EditRole);
    model_->setData(model_->index(currentRow , 2), resultSlot.getSize(), Qt::EditRole);


    textEditFirst_->clear();

    for(int i = 0; i < strList.size(); ++i){
        textEditFirst_->append(QString::number(mutArraySeqToSort->Get(i), 10));
    }

    textEditFirst_->repaint();

}*/

void UIClass::slotPrintGraphics()
{
    QVector<QString> colors(3);
    colors[0] = "red"; colors[1] = "blue"; colors[2] = "magenta";

    QVector<QString> names(3);
    names[0] = "Add"; names[1] = "Get"; names[2] = "Remove";
    QVector<QPair<QPointF, bool> > Points(3);

    RealTimePlot* realTimePlot = new RealTimePlot(3, names, colors, "Plot Title");
    for(int i = 0; i < model_->rowCount(model_->index(0, 0)); i++){
        Points[0] = QPair<QPointF, bool>(QPointF(0, 0), false);
        Points[1] = QPair<QPointF, bool>(QPointF(0, 0), false);
        Points[2] = QPair<QPointF, bool>(QPointF(0, 0), false);

        if(model_->data(model_->index(i, 0), Qt::EditRole).value<QString>() == QString("Add")){

            Points[0] = QPair<QPointF, bool>(QPointF(model_->data(model_->index(i, 2), Qt::EditRole).value<int>()
                                                     ,model_->data(model_->index(i, 1), Qt::EditRole).value<double>()), true);

        }

        if(model_->data(model_->index(i, 0), Qt::EditRole).value<QString>() == QString("Get")){

            Points[1] = QPair<QPointF, bool>(QPointF(model_->data(model_->index(i, 2), Qt::EditRole).value<int>()
                                                     ,model_->data(model_->index(i, 1), Qt::EditRole).value<double>()), true);

        }
        if(model_->data(model_->index(i, 0), Qt::EditRole).value<QString>() == QString("Remove")){

            Points[2] = QPair<QPointF, bool>(QPointF(model_->data(model_->index(i, 2), Qt::EditRole).value<int>()
                                                     ,model_->data(model_->index(i, 1), Qt::EditRole).value<double>()), true);

        }
        realTimePlot->AddData(Points);
    }

    realTimePlot->EndInput();

}

QString UIClass::GetRandomString()
{
    const QString
        possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"); // size is 62


    QString randomString;
    QRandomGenerator* randomGenerator = QRandomGenerator::global();
    for(int i=0; i<maxQStringLength; ++i)
    {
        int index = randomGenerator->bounded(0, 61);
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    return randomString;

}

void UIClass::slotPrintDictionary()
{
    for(auto it = dictionary_->begin(); it != dictionary_->end(); ++it){
        QString tmpString = (*it).GetFirst() + " " + (*it).GetSecond();
        textEditFirst_->append(tmpString);
    }
}
void UIClass::slotAdd()
{
    QString strFullPlaneText = textEditFirst_->toPlainText();
    QStringList strList = strFullPlaneText.split('\n');
    for(int i = 0 ; i < strList.size(); i++)
    {
        if(!isNormalQString(strList.at(i)))
        {
            QWidget* wg = new QWidget;
            QMessageBox::critical(wg, "Pay Attention"
                                  , "You data has wrong format");
            return;
        }
    }
    double timeAppend = 0;
    double currentTime = 0;
    for(int i = 0; i < strList.size(); i++){

        QStringList keyAndValue = strList.at(i).split(' ');
        QString key = keyAndValue.at(0);
        QString value = keyAndValue.at(1);

        try{
            auto start = std::chrono::high_resolution_clock::now();

            dictionary_->Add(key, value);

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end - start;
            currentTime = std::chrono::duration<double>(diff).count();

            timeAppend+=currentTime;

        }
        catch(const char* message)
        {
            QWidget* wg = new QWidget;
            QMessageBox::critical(wg, "Pay Attention"
                                  , message);
            return;
        }
    }

    int currentRow = model_->rowCount(model_->index(0, 0));
    model_->insertRows(currentRow, 1);

    model_->setData(model_->index(currentRow , 0), 0, Qt::EditRole);
    model_->setData(model_->index(currentRow , 1), timeAppend / strList.size(), Qt::EditRole);
    model_->setData(model_->index(currentRow , 2), dictionary_->GetLength(), Qt::EditRole);


}
void UIClass::slotGet()
{
    getQStringFromNewWidget* obj = new getQStringFromNewWidget;
    connect(obj, SIGNAL(ButtonPushed(QString))
            , this, SLOT(slotGetSecond(QString)));
    obj->getString("Enter key" , "Find");


}

void UIClass::slotGetSecond(QString key)
{
    if(!dictionary_->isContains(key)){
        QWidget* wg = new QWidget;
        QMessageBox::critical(wg, "Pay Attention"
                              , "You have not an object with this key");
        return;
    }

    QString value = dictionary_->Get(key);
    keyToGet_ = key;
    getQStringFromNewWidget* obj = new getQStringFromNewWidget;
    connect(obj, SIGNAL(ButtonPushed(QString))
            , this, SLOT(slotGetFinal(QString)));
    obj->getString("Enter new value for: <" + key + ", " + value + ">" , "Reset");


}

void UIClass::slotGetFinal(QString newValue)
{
    if(newValue.size() == 0 || newValue.size() > 10){
        QWidget* wg = new QWidget;
        QMessageBox::critical(wg, "Pay Attention"
                              , "new value has invalid format");
        return;
    }
    double currentTime = 0;
    try{
        auto start = std::chrono::high_resolution_clock::now();

        dictionary_->Get(keyToGet_) = newValue;

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        currentTime = std::chrono::duration<double>(diff).count();
    }
    catch(const char* message)
    {
        QWidget* wg = new QWidget;
        QMessageBox::critical(wg, "Pay Attention"
                              , message);
        return;
    }

    int currentRow = model_->rowCount(model_->index(0, 0));
    model_->insertRows(currentRow, 1);

    model_->setData(model_->index(currentRow , 0), 1, Qt::EditRole);
    model_->setData(model_->index(currentRow , 1), currentTime, Qt::EditRole);
    model_->setData(model_->index(currentRow , 2), dictionary_->GetLength(), Qt::EditRole);
}

void UIClass::slotRemove()
{
    QString strFullPlaneText = textEditFirst_->toPlainText();
    if(strFullPlaneText.isEmpty()){
        return;
    }
    QStringList strList = strFullPlaneText.split('\n');
    for(int i = 0 ; i < strList.size(); i++)
    {
        if(!isNormalQString(strList.at(i)) && !isNormalQStringKey(strList.at(i)))
        {
            QWidget* wg = new QWidget;
            QMessageBox::critical(wg, "Pay Attention"
                                  , "You data has wrong format");
            return;
        }
    }

    double timeRemove = 0;
    double currentTime = 0;
    for(int i = 0; i < strList.size(); i++){

        QStringList keyAndValue = strList.at(i).split(' ');
        QString key = keyAndValue.at(0);
        QString value;
        if(keyAndValue.size() == 2){
            value = keyAndValue.at(1);
        }

        try{

            if(!dictionary_->isContains(key)){
                QWidget* wg = new QWidget;
                QMessageBox::critical(wg, "Pay Attention"
                                      , "You have not pointer with this key" + QString("\n number of string:") + QString::number(i));
                return;
            }
            if(value.size() != 0 && dictionary_->Get(key) != value){
                QWidget* wg = new QWidget;
                QMessageBox::critical(wg, "Pay Attention"
                                      , "You have not pointer with this value" + QString("\n number of string:") + QString::number(i));
                return;
            }
            auto start = std::chrono::high_resolution_clock::now();
            dictionary_->Remove(key);

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end - start;
            currentTime = std::chrono::duration<double>(diff).count();

            timeRemove+=currentTime;

        }
        catch(const char* message)
        {
            QWidget* wg = new QWidget;
            QMessageBox::critical(wg, "Pay Attention"
                                  , message);
            return;
        }
    }

    int currentRow = model_->rowCount(model_->index(0, 0));
    model_->insertRows(currentRow, 1);

    model_->setData(model_->index(currentRow , 0), 2, Qt::EditRole);
    model_->setData(model_->index(currentRow , 1), timeRemove / strList.size(), Qt::EditRole);
    model_->setData(model_->index(currentRow , 2), strList.size(), Qt::EditRole);
}

int UIClass::GetMaxLengthQString()
{
    return maxQStringLength;
}
