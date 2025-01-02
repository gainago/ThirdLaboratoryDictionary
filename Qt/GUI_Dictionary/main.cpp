#include "uiclass.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UIClass*  obj = new UIClass;
    return a.exec();
}
