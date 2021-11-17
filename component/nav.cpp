//
// Created by zyx on 2021/11/15.
//

#include <QPainter>
#include <QPainterPath>
#include "nav.h"

#define PIX_SIZE 73

Nav::Nav(QWidget *parent):QPushButton(parent){
    m_title = new QLabel(this);
    m_key = new QLabel(this);
    m_effect = new QGraphicsDropShadowEffect(this);

    this->setMinimumSize(100, 100);
    this->setMaximumSize(100, 100);
    this->setCursor(Qt::PointingHandCursor);

    m_effect->setOffset(0, 0);
    m_effect->setColor(Qt::black);
    m_effect->setBlurRadius(m_radius);
    this->setGraphicsEffect(m_effect);

#if 1
    m_key->setGeometry(14, 14, 1, 20);
    m_key->setText("  UPDATE  ");
    m_key->setStyleSheet("border-radius:6px;background:rgba(255,255,255,200);color:black;font-size:12px;");
    m_key->adjustSize();

    m_title->setGeometry(10, 50, 100, 20);
    m_title->setText("TITLE TITLE TITLE TITLE TITLE ");
    m_title->setStyleSheet("color:white;");
    m_title->adjustSize();
#endif

    m_pix.load("D:\\program\\Inn-client\\test.png");
    m_pix = GeneratePixmap(m_pix);

    m_shadow = new QPropertyAnimation(this, "radius");
    m_shadow->setEasingCurve(QEasingCurve::OutExpo);
    m_shadow->setDuration(800);

    m_mask = new QPropertyAnimation(this,"alpha");
    m_shadow->setEasingCurve(QEasingCurve::OutExpo);
    m_shadow->setDuration(800);
}

QPixmap Nav::GeneratePixmap(const QPixmap &src) {
    if (src.isNull())
        return src;
    // 压缩图片
    QPixmap pixmap = src.scaled(PIX_SIZE, PIX_SIZE, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPixmap dest(PIX_SIZE, PIX_SIZE);
    dest.fill(Qt::transparent);
    QPainter painter(&dest);
    // 抗锯齿 + 平滑边缘处理
    painter.setRenderHints(QPainter::Antialiasing, true);
    painter.setRenderHints(QPainter::SmoothPixmapTransform, true);
    // 裁剪
    QPainterPath path;
    path.addRoundedRect(QRectF(0, 0, PIX_SIZE, PIX_SIZE), 8, 8);
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, PIX_SIZE, PIX_SIZE, pixmap);

    return dest;
}

void Nav::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    if (m_isHover) {
        QPainterPath path;
        path.addRoundedRect(QRectF(5, 5, 90, 90), 10, 10);
        QPen pen(QColor(198, 198, 198, 180), 5);
        painter.setPen(pen);
        painter.fillPath(path, Qt::transparent);
        painter.drawPath(path);
    }

    QLinearGradient linear(0, 0, 0, 100);
    linear.setColorAt(0, QColor(0, 0, 0, 0));
    linear.setColorAt(1, QColor(0, 0, 0, m_alpha));
    linear.setSpread(QGradient::PadSpread);

    painter.setPen(Qt::NoPen);
    painter.drawPixmap(14, 14, PIX_SIZE, PIX_SIZE, m_pix);

    painter.setBrush(linear);
    painter.drawRoundedRect(QRect(12, 12, 50, 50), 14, 14);
}

void Nav::enterEvent(QEvent *event) {
    emit mousePos(true);
    m_isHover = true;
    m_shadow->stop();
    m_mask->stop();
    m_shadow->setStartValue(m_radius);
    m_shadow->setEndValue(50);
    m_shadow->start();
    m_mask->setStartValue(m_alpha);
    m_mask->setEndValue(200);
    m_mask->start();
}

void Nav::leaveEvent(QEvent *event) {
    emit mousePos(false);
    m_isHover = false;
    m_shadow->stop();
    m_mask->stop();
    m_shadow->setStartValue(m_radius);
    m_shadow->setEndValue(20);
    m_shadow->start();
    m_mask->setStartValue(m_alpha);
    m_mask->setEndValue(180);
    m_mask->start();
}

int Nav::radius() const {
    return m_radius;
}

void Nav::setRadius(const int radius) {
    m_effect->setBlurRadius(m_radius);
    m_radius = radius;
}

int Nav::alpha() const {
    return m_alpha;
}

void Nav::setAlpha(const int alpha) {
    m_alpha = alpha;
    update();
}