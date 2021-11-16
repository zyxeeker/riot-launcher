#include "mainwindow.h"
#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    int fontId = QFontDatabase::addApplicationFont(":/font/resource/font.otf");
    if (fontId >= 0) {
        auto f = QFontDatabase::applicationFontFamilies(fontId).at(0);
        QFont font(f);
        a.setFont(font);
    }
    MainWindow w;
    w.show();
    return a.exec();
}
