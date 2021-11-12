#include "mainwindow.h"
#include "component/button.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    Button b;
    b.show();
    return a.exec();
}
