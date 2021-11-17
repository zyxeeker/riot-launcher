//
// Created by 19047 on 2021/11/14.
//

#include "update_page.h"

UpdatePage::UpdatePage(QWidget *parent) : QWidget(parent) {
    m_w = new QWebEngineView(this);
    m_mask = new QLabel(this);
    m_dock = new QWidget(this);
    m_logo = new QLabel(this);
    m_dockBk = new bk(m_dock);

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
    hSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    m_play = new PlayButton(this);
    m_play->setGeometry(30, 550, 30, 30);

    connect(m_play, &QPushButton::clicked, this, [=]() {
        m_w->page()->runJavaScript("C()");
    });
    connect(m_n1, &Nav::mousePos, m_dockBk, &bk::Change);
    connect(m_n2, &Nav::mousePos, m_dockBk, &bk::Change);

    m_logo->setMinimumSize(140, 60);
    m_logo->setMaximumSize(140, 60);
    m_logo->setPixmap(QPixmap(":/img/resource/game.png"));
    m_logo->setScaledContents(true);

    this->setMaximumSize(1280, 720 * 2);
    this->setMinimumSize(1280, 720 * 2);

    m_w->load(QString("file:///D:/program/un/riot-launcher/index.html"));
//    m_w->setUrl(QString("https://lol.secure.dyn.riotcdn.net/channels/public/rccontent/theme/product-details-background.webm"));
    m_w->setGeometry(0, 0, 1280, 720);
    m_w->page()->setBackgroundColor(QColor(35, 35, 35));
    m_mask->setGeometry(0, 0, 1280, 720);

    m_bar->setGeometry(0, 0, 1280, 70);
    m_bar->setStyleSheet("background:transparent;");

    m_dock->setObjectName("dock");
    m_dock->setGeometry(0, 625, 1280, 95);
    m_dock->setStyleSheet("#dock{background:rgba(32, 28, 29, 220);}");
    m_dockBk->setGeometry(500, 0, 780, 95);

    m_dLayout->addWidget(m_ctrl);
    m_dLayout->addItem(hSpacer);
    m_dLayout->setContentsMargins(80, 0, 0, 0);

    m_nLayout->addWidget(m_n1);
    m_nLayout->addWidget(m_n2);
    m_nLayout->setContentsMargins(0, 0, 0, 0);
    m_navDock->setGeometry(750, 545, 200, 200);

}