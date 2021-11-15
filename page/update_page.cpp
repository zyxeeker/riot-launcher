//
// Created by 19047 on 2021/11/14.
//

#include "update_page.h"

const QSizeF VideoItemSize(1280, 720);

UpdatePage::UpdatePage(QWidget *parent) : QWidget(parent) {
    m_w = new QWebEngineView(this);
    m_mask = new QLabel(this);
    m_dock = new QWidget(this);
    m_logo = new QLabel(this);

    m_c = new QWidget(this);
    m_dLayout = new QHBoxLayout(m_dock);
    m_ctrl = new UpdateCtrl(m_c);

    m_navDock = new QWidget(this);
    m_nLayout = new QHBoxLayout(m_navDock);
    m_n1 = new Nav(m_navDock);
    m_n2 = new Nav(m_navDock);

    m_bar = new QLabel(this);
    m_bLayout = new QHBoxLayout(m_bar);
    m_bLayout->addWidget(m_logo);
//    m_logo->setStyleSheet("background:blue;");

    hSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

//    m_player = new QMediaPlayer(this);
//    m_v = new QVideoWidget(this);
//    m_playerList = new QMediaPlaylist(this);
    m_logo->setMinimumSize(140, 60);
    m_logo->setMaximumSize(140, 60);
    m_logo->setPixmap(QPixmap(":/img/resource/game.png"));
    m_logo->setScaledContents(true);

    this->setMaximumSize(1280, 720 * 2);
    this->setMinimumSize(1280, 720 * 2);
#if 1
    m_w->setStyleSheet("background:transparent;");
    m_w->load(QString("file:///E:/CProject/riot-launcher/index.html"));
//    m_w->setUrl(QString("https://lol.secure.dyn.riotcdn.net/channels/public/rccontent/theme/product-details-background.webm"));
    m_w->setGeometry(0, 0, 1280, 720);
    m_w->setStyleSheet("background:transparent;");
//    m_mask->setGeometry(0,0,1280,720);
#endif
#if 0
    m_v = new QGraphicsView(this);
    m_scene = new QGraphicsScene(this);
    m_video = new QGraphicsVideoItem;
    m_v->setScene(m_scene);
    m_v->setStyleSheet("border:0px;background:transparent;");
    m_v->lower();
    m_video->setSize(VideoItemSize);
    m_scene->setSceneRect(QRectF(QPointF(-5, -5), VideoItemSize)); // VideoItem full fill the scene
    m_scene->addItem(m_video);
    m_player->setVideoOutput(m_video);

    m_playerList->addMedia(QUrl("https://lol.secure.dyn.riotcdn.net/channels/public/rccontent/theme/product-details-background.webm"));
    m_playerList->setCurrentIndex(1);
    m_playerList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    m_player->setPlaylist(m_playerList);
    m_player->setVolume(0);
    m_player->play();
#endif

    m_bar->setGeometry(0, 0, 1280, 70);
    m_bar->setStyleSheet("background:transparent;");

    m_dock->setObjectName("dock");
    m_dock->setGeometry(0, 625, 1280, 95);
    m_dock->setStyleSheet("#dock{background:rgba(32, 28, 29, 220);}");

    m_dLayout->addWidget(m_ctrl);
    m_dLayout->addItem(hSpacer);
    m_dLayout->setContentsMargins(80, 0, 0, 0);

    m_nLayout->addWidget(m_n1);
    m_nLayout->addWidget(m_n2);
    m_navDock->setGeometry(750, 545, 300, 200);

}