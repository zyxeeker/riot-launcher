//
// Created by 19047 on 2021/11/14.
//

#include "update_page.h"

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
    m_logo->setStyleSheet("background:blue;");

    hSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    this->setMaximumSize(1280,720*2);
    this->setMinimumSize(1280,720*2);
    m_w->load(QString("https://liulanmi.com/labs/core.html"));
//    m_w->setUrl(QString("https://lol.secure.dyn.riotcdn.net/channels/public/rccontent/theme/product-details-background.webm"));
    m_w->setGeometry(0,0,1280,720);
    m_w->setStyleSheet("background:transparent;");
    m_mask->setGeometry(0,0,1280,720);

    m_bar->setGeometry(0,0,1280,70);
    m_bar->setStyleSheet("background:transparent;");

    m_dock->setObjectName("dock");
    m_dock->setGeometry(0,620,1280,100);
    m_dock->setStyleSheet("#dock{background:rgba(0,0,0,180);}");

//    m_dLayout->addWidget(m_ctrl);
    m_dLayout->addItem(hSpacer);

    m_nLayout->addWidget(m_n1);
    m_nLayout->addWidget(m_n2);
    m_navDock->setGeometry(750,520,300,200);
}