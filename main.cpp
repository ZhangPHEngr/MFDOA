#include "mainwindow.h"
#include "headSet.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.showFullScreen();  //全屏显示

    return a.exec();
}
