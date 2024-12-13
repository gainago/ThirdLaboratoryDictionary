#ifndef UICLASS_H
#define UICLASS_H

#include <QObject>
#include <QWidget>

#include <QRect>
#include <QGridLayout>
#include <QTextEdit>
#include <QFileSystemModel>
#include <QTreeView>
#include <QPushButton>

#include "directorytablemodel.h"
#include "QTableView"
#include "Dictionary.h"

class UIClass : QObject
{
    Q_OBJECT
private:
    static int const maxQStringLength = 10;
    DirectoryTableModel* model_;
    QTableView* viewModel_;
    QRect* screen_;
    QWidget* mainPageFirst_;
    QWidget* mainPageSecond_;
    QTextEdit* textEditFirst_;
    QWidget* widgetBottomFirst_;
    QGridLayout* gridLayoutTextFirst_;
    QTreeView* treeViewFileSystemModel_;
    QFileSystemModel* fileSystemModel_;
    QPushButton* pushButtonChooseFileToSort_ ;
    Dictionary<QString, QString>* dictionary_;
    QString keyToGet_;
    QString GetRandomString();


public:
    UIClass();

    static int GetMaxLengthQString();

private slots:
    void slotOpenFirstWindow();
    void slotOpenSecondWindow();
    void slotAutomaticallyCreateData();
    void slotAutomaticallyCreateDataFinal(QString strNumber);
    void slotWriteDataToFile();
    void slotWriteDataToFileFinal(QString strName);
    void slotChooseFile(bool);
    void slotPrintDictionary();
    void slotOpenFile(QModelIndex);
    void slotAdd();
    void slotGet();
    void slotGetSecond(QString key);
    void slotGetFinal(QString newValue);
    void slotRemove();
    //void slotStartSort();
    void slotPrintGraphics();



};

#endif // UICLASS_H
