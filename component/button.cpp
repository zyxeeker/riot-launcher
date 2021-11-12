//
// Created by zyx on 2021/11/12.
//

#include "button.h"
#include <QPainter>
#include <QDebug>

Button::Button(QWidget *parent) : QPushButton(parent) {
    m_icon = QPixmap(":/img/resource/_login.svg");
    m_startAnimation = new QPropertyAnimation(this, "gb");
    m_startAnimation1 = new QPropertyAnimation(this, "alpha");
    m_hoverAnimation = new QPropertyAnimation(this, "r");

    m_startAnimation->setEasingCurve(QEasingCurve::OutExpo);
    m_startAnimation->setDuration(180);
    m_startAnimation1->setEasingCurve(QEasingCurve::OutExpo);
    m_startAnimation1->setDuration(180);
    m_hoverAnimation->setEasingCurve(QEasingCurve::OutQuad);
    m_hoverAnimation->setDuration(220);

    m_startAnimation->setStartValue(m_gb);
    m_startAnimation->setEndValue(70);
    m_startAnimation->start();
    m_startAnimation1->setStartValue(m_alpha);
    m_startAnimation1->setEndValue(0);
    m_startAnimation1->start();

    this->setMinimumSize(60, 60);
    this->setMaximumSize(60, 60);
}

void Button::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QColor bkColor(255, 255, 255, m_alpha);
    QColor borderColor;
    borderColor = QColor(m_r, m_gb, m_gb);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(borderColor));
    painter.drawRoundedRect(QRect(0, 0, 60, 60), 16, 16);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(bkColor));
    painter.drawRoundedRect(QRect(3, 3, 54, 54), 14, 14);

    painter.drawPixmap(18, 18, m_icon);
}

void Button::enterEvent(QEvent *event) {
    m_isHover = true;
    m_hoverAnimation->setStartValue(m_r);
    m_hoverAnimation->setEndValue(255);
    m_hoverAnimation->start();
    QPushButton::enterEvent(event);
}

void Button::leaveEvent(QEvent *event) {
    m_isHover = false;
    m_hoverAnimation->stop();
    m_hoverAnimation->setStartValue(m_r);
    m_hoverAnimation->setEndValue(232);
    m_hoverAnimation->start();
    QPushButton::leaveEvent(event);

}

void Button::mousePressEvent(QMouseEvent *event) {
    m_isPressed = true;
    QPushButton::mousePressEvent(event);
}

void Button::mouseReleaseEvent(QMouseEvent *event) {
    m_isPressed = false;
    QPushButton::mouseReleaseEvent(event);
}

void Button::setAlpha(const int alpha) {
    m_alpha = alpha;
    update();
}

int Button::alpha() const {
    return m_alpha;
}

int Button::gb() const {
    return m_gb;
}

void Button::setGB(const int gb) {
    m_gb = gb;
    update();
}

int Button::r() const {
    return m_r;
}

void Button::setR(const int r) {
    m_r = r;
    update();
}

