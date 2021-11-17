//
// Created by zyx on 2021/11/17.
//

#include <QPainter>
#include "bk.h"

bk::bk(QWidget *parent) : QLabel(parent) {
    m_animation = new QPropertyAnimation(this, "alpha");
    m_animation->setEasingCurve(QEasingCurve::OutQuad);
    m_animation->setDuration(220);
}

void bk::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QLinearGradient linearGradient(0, 90, width(), 90);
    linearGradient.setColorAt(0.05, Qt::transparent);
    linearGradient.setColorAt(0.5, QColor(26, 198, 227, m_alpha));
    linearGradient.setColorAt(0.95, Qt::transparent);

    painter.setPen(Qt::transparent);
    painter.setBrush(linearGradient);
    painter.drawRect(0, 0, width(), height());
}

int bk::alpha() const {
    return m_alpha;
}

void bk::setAlpha(int alpha) {
    m_alpha = alpha;
    update();
}

void bk::Change(bool st) {
    m_animation->stop();
    if (st) {
        m_animation->setStartValue(m_alpha);
        m_animation->setEndValue(180);
        m_animation->start();
    } else {
        m_animation->setStartValue(m_alpha);
        m_animation->setEndValue(0);
        m_animation->start();
    }
}