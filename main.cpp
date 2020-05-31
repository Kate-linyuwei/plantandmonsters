#include "mwin.h"
#include <QApplication>
#include<icon.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mwin w;
    w.show();

    return a.exec();
}
