//
// Created by zyx on 2021/11/15.
//

#include <QPainter>
#include <QPainterPath>
#include "nav.h"

#define PIX_SIZE 100

Nav::Nav(QWidget *parent):QPushButton(parent){
    m_title = new QLabel(this);
    m_key = new QLabel(this);
    m_effect = new QGraphicsDropShadowEffect(this);

    this->setMinimumSize(100,100);
    this->setMaximumSize(100,100);

    m_effect->setOffset(0, 0);
    m_effect->setColor(Qt::black);
    m_effect->setBlurRadius(m_radius);
    this->setGraphicsEffect(m_effect);

#if 0
    m_key->setGeometry(5,5,1,20);
    m_key->setText("  UPDATE  ");
    m_key->setStyleSheet("border-radius:10px;background:rgb(0,255,255);color:white;");
    m_key->adjustSize();

    m_title->setGeometry(5,50,100,20);
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
    path.addRoundedRect(QRectF(0,0,100,100),16,16);
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, PIX_SIZE, PIX_SIZE, pixmap);

    return dest;
}

void Nav::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QLinearGradient linear(0,0,0,100);
    linear.setColorAt(0,QColor(0,0,0,0));
    linear.setColorAt(1,QColor(0,0,0,m_alpha));
    linear.setSpread(QGradient::PadSpread);

    painter.setPen(Qt::NoPen);
    painter.drawPixmap(0, 0, PIX_SIZE, PIX_SIZE, m_pix);

    painter.setBrush(linear);
    painter.drawRoundedRect(rect(), 14, 14);
}

void Nav::enterEvent(QEvent *event) {
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