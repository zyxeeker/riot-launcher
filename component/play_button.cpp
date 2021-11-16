//
// Created by zyx on 2021/11/16.
//

#include <QPainter>
#include "play_button.h"

PlayButton::PlayButton(QWidget *parent) : QPushButton(parent) {
    this->setMinimumSize(30, 30);
    this->setMaximumSize(30, 30);
    this->setCheckable(true);

    m_play = QPixmap(":/img/resource/bk_play.svg");
    m_pause = QPixmap(":/img/resource/bk_pause.svg");

    m_hoverAnimation = new QPropertyAnimation(this, "alpha");
    m_hoverAnimation->setEasingCurve(QEasingCurve::OutQuad);
    m_hoverAnimation->setDuration(220);

    m_effect = new QGraphicsDropShadowEffect(this);
    m_effect->setOffset(0, 0);
    m_effect->setColor(QColor(35, 35, 35));
    m_effect->setBlurRadius(20);
    this->setGraphicsEffect(m_effect);

    m_shadow = new QPropertyAnimation(this, "radius");
    m_shadow->setEasingCurve(QEasingCurve::OutExpo);
    m_shadow->setDuration(220);
}

void PlayButton::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QColor bkColor(35, 35, 35, m_alpha);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(bkColor));
    painter.drawRoundedRect(QRect(0, 0, 30, 30), 6, 6);
    if (isChecked())
        painter.drawPixmap(3, 3, m_play);
    else
        painter.drawPixmap(3, 3, m_pause);
}

void PlayButton::enterEvent(QEvent *event) {
    m_hoverAnimation->stop();
    m_shadow->stop();
    m_hoverAnimation->setStartValue(m_alpha);
    m_hoverAnimation->setEndValue(80);
    m_hoverAnimation->start();
    m_shadow->setStartValue(m_radius);
    m_shadow->setEndValue(50);
    m_shadow->start();
}

void PlayButton::leaveEvent(QEvent *event) {
    m_hoverAnimation->stop();
    m_shadow->stop();
    m_hoverAnimation->setStartValue(m_alpha);
    m_hoverAnimation->setEndValue(50);
    m_hoverAnimation->start();
    m_shadow->setStartValue(m_radius);
    m_shadow->setEndValue(20);
    m_shadow->start();
}

void PlayButton::setAlpha(const int alpha) {
    m_alpha = alpha;
    update();
}

int PlayButton::alpha() const {
    return m_alpha;
}

int PlayButton::radius() const {
    return m_radius;
}

void PlayButton::setRadius(const int radius) {
    m_effect->setBlurRadius(m_radius);
    m_radius = radius;
}