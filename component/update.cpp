//
// Created by 19047 on 2021/11/13.
//

#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include "update.h"

UpdateCtrl::UpdateCtrl(QWidget *parent) {
    m_title = new QLabel(this);
    m_st = new QLabel(this);
    m_effect = new QGraphicsDropShadowEffect(this);

    this->setMaximumSize(155,50);
    this->setMinimumSize(155,50);
    this->setCursor(Qt::PointingHandCursor);

    m_effect->setOffset(0, 0);
    m_effect->setColor(QColor(26, 198, 227));
    m_effect->setBlurRadius(20);
    this->setGraphicsEffect(m_effect);

    m_download = QPixmap(":/img/resource/download.svg");
    m_pause = QPixmap(":/img/resource/pause.svg");

    m_title->setStyleSheet("color:white;");
    m_title->setGeometry(54,8,100,20);
//    m_title->setText(QString::fromUtf8("更新"));

    QFont font;
    font.setPointSize(8);
    m_st->setStyleSheet("color:rgb(159, 213, 231);");
    m_st->setGeometry(54,28,100,12);
//    m_st->setText(QString::fromUtf8("暂停"));
    m_st->setFont(font);

    m_hover = new QPropertyAnimation(this, "scale");
    m_hover->setEasingCurve(QEasingCurve::OutExpo);
    m_hover->setDuration(800);

    m_shadow = new QPropertyAnimation(this, "radius");
    m_shadow->setEasingCurve(QEasingCurve::OutExpo);
    m_shadow->setDuration(800);
}

void UpdateCtrl::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QColor circleColor(18, 53, 59);
    QColor updateColor(11, 196, 226);

    QLinearGradient linear(0,0,155,50);
    linear.setColorAt(0,QColor(68, 158, 203));
    linear.setColorAt(1,QColor(26, 198, 227));
    linear.setSpread(QGradient::PadSpread);

    painter.setPen(Qt::NoPen);
    painter.setBrush(linear);
    painter.drawRoundedRect(QRect(0, 0, 155, 50), 14, 14);

    painter.setBrush(Qt::black);
    painter.scale(m_scale,m_scale);
    painter.drawRoundedRect(QRect(8, 8, 34, 34),17, 17);

    painter.setBrush(circleColor);
    painter.drawRoundedRect(QRect(10, 10, 30, 30),15, 15);

    painter.setBrush(updateColor);
    painter.drawPie(QRect(10,10,30,30),90*16,-120*16);

    painter.setBrush(Qt::black);
    painter.drawRoundedRect(QRect(13, 13, 24, 24),12, 12);
    painter.scale(1.0,1.0);

    painter.drawPixmap(17, 17, m_download);

}

void UpdateCtrl::enterEvent(QEvent *event) {
    m_hover->stop();
    m_shadow->stop();
    m_hover->setStartValue(m_scale);
    m_hover->setEndValue(1.02);
    m_hover->start();
    m_shadow->setStartValue(m_radius);
    m_shadow->setEndValue(50);
    m_shadow->start();
}

void UpdateCtrl::leaveEvent(QEvent *event) {
    m_hover->stop();
    m_shadow->stop();
    m_hover->setStartValue(m_scale);
    m_hover->setEndValue(1.0);
    m_hover->start();
    m_shadow->setStartValue(m_radius);
    m_shadow->setEndValue(20);
    m_shadow->start();
}

double UpdateCtrl::scale() const {
    return m_scale;
}

void UpdateCtrl::setScale(const double scale) {
    m_scale = scale;
    update();
}

int UpdateCtrl::radius() const {
    return m_radius;
}

void UpdateCtrl::setRadius(const int radius) {
    m_effect->setBlurRadius(m_radius);
    m_radius = radius;
}