//
// Created by zyx on 2021/11/12.
//

#include <QPainter>
#include "input.h"

#define RGB_START 236
#define ALPHA_START 255

Input::Input(QWidget *parent) : QWidget(parent) {
    m_lineEdit = new QLineEdit(this);
    m_label = new QLabel(this);
    Init();
}

void Input::Init() {
    this->setMinimumSize(240, 40);
    this->setMaximumSize(240, 40);
    QFont font1;
    font1.setPointSize(6);
    font1.setBold(true);
    m_label->setGeometry(11, 15, 100, 10);
    m_label->setFont(font1);
    m_label->setText(QString::fromUtf8("帐号"));
    m_label->setStyleSheet("color:rgb(155,155,155);background-color: transparent;border:none;");
    QFont font;
    font.setPointSize(10);
    m_lineEdit->setGeometry(6, 15, 240, 18);
    m_lineEdit->setFont(font);
    m_lineEdit->setStyleSheet("background-color: transparent;border:none;");
    m_lineEdit->setEnabled(false);
    m_lineEdit->raise();

    m_bk = new QPropertyAnimation(this, "bkRGB");
    m_bk->setEasingCurve(QEasingCurve::OutExpo);
    m_bk->setDuration(220);

    m_bkBorder = new QPropertyAnimation(this, "borderRGB");
    m_bkBorder->setEasingCurve(QEasingCurve::OutExpo);
    m_bkBorder->setDuration(220);

    m_labelPos = new QPropertyAnimation(m_label, "geometry");
    m_labelPos->setEasingCurve(QEasingCurve::OutExpo);
    m_labelPos->setDuration(180);
}

void Input::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QColor bkColor(m_bkRGB, m_bkRGB, m_bkRGB);
    QColor borderColor(m_borderRGB, m_borderRGB, m_borderRGB);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(borderColor));
    painter.drawRoundedRect(QRect(0, 0, 240, 40), 4, 4);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(bkColor));
    painter.drawRoundedRect(QRect(2, 2, 236, 36), 2, 2);
}

void Input::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_lineEdit->setEnabled(true);
        m_lineEdit->setFocus();
        m_labelPos->setStartValue(m_label->geometry());
        m_labelPos->setEndValue(QRect(7, 5, 100, 10));
        m_bk->setStartValue(m_bkRGB);
        m_bk->setEndValue(249);
        m_bkBorder->setStartValue(m_borderRGB);
        m_bkBorder->setEndValue(50);
        m_labelPos->start();
        m_bk->start();
        m_bkBorder->start();
    }
}

int Input::bkRGB() const {
    return m_bkRGB;
}

void Input::setBkRGB(const int rgb) {
    m_bkRGB = rgb;
    update();
}

int Input::borderRGB() const {
    return m_borderRGB;
}

void Input::setBorderRGB(const int rgb) {
    m_borderRGB = rgb;
    update();
}