#include "mainwindow.h"
#include "component/input.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
//    Input i;
//    i.show();
    MainWindow w;
    w.show();
    return a.exec();
}
