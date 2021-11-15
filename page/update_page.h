//
// Created by 19047 on 2021/11/14.
//

#ifndef LAUNCHER_UPDATE_PAGE_H
#define LAUNCHER_UPDATE_PAGE_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QGraphicsView>
#include <QGraphicsVideoItem>
#include <QGraphicsProxyWidget>
#include "component/update.h"
#include "component/nav.h"

class UpdatePage : public QWidget {
Q_OBJECT
public:
    UpdatePage(QWidget *parent = nullptr);
private:
//    QWebEngineView *m_w;
    QLabel *m_mask;
    QWidget *m_dock;
    QWidget *m_navDock;
    QLabel *m_bar;
    QLabel *m_logo;
    QWidget *m_c;
    QHBoxLayout *m_dLayout;
    QHBoxLayout *m_nLayout;
    QHBoxLayout *m_bLayout;
    QSpacerItem *hSpacer;
    UpdateCtrl *m_ctrl;
    Nav *m_n1;
    Nav *m_n2;

//    QVideoWidget *m_v;
    QMediaPlayer *m_player;
    QMediaPlaylist *m_playerList;
    QGraphicsScene *m_scene;
    QGraphicsView *m_v;
    QGraphicsVideoItem *m_video;
};


#endif //LAUNCHER_UPDATE_PAGE_H
