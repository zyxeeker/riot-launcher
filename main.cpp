#include "mainwindow.h"
#include <QApplication>
#include <QFontDatabase>
#include "component/update.h"
#include "component/nav.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    int fontId = QFontDatabase::addApplicationFont(":/font/resource/font.otf");
    if(fontId>=0){
        auto f = QFontDatabase::applicationFontFamilies(fontId).at(0);
        QFont font(f);
        a.setFont(font);
    }
    MainWindow w;
    w.show();
//    Nav n;
//    n.show();
//UpdateCtrl u;
//    u.show();
    return a.exec();
}
