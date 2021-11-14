//
// Created by 19047 on 2021/11/14.
//

#include "update_page.h"

UpdatePage::UpdatePage(QWidget *parent) : QWidget(parent) {
    this->setMaximumSize(1274,720*2);
    this->setMinimumSize(1274,720*2);
    m_w = new QWebEngineView(this);
    m_w->load(QString("file:///E:/CProject/riot-launcher/index.html"));
//    m_w->setUrl(QString("https://lol.secure.dyn.riotcdn.net/channels/public/rccontent/theme/product-details-background.webm"));
    m_w->setGeometry(0,0,1274,720);
}