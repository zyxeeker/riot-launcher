//
// Created by 19047 on 2021/11/14.
//

#ifndef LAUNCHER_UPDATE_PAGE_H
#define LAUNCHER_UPDATE_PAGE_H

#include <QWidget>
#include <QtWebEngineWidgets/QWebEngineView>

class UpdatePage : public QWidget{
Q_OBJECT
public:
    UpdatePage(QWidget *parent = nullptr);
private:
    QWebEngineView *m_w;
};


#endif //LAUNCHER_UPDATE_PAGE_H
