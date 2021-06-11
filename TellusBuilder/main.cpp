#include "tellusbuilder.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TellusBuilder w;
    w.show();
    return a.exec();
}
