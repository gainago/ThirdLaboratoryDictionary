#include <QApplication>

#include "UIClass.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UIClass example;

    return a.exec();
}
