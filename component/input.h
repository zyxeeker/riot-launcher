//
// Created by zyx on 2021/11/12.
//

#ifndef LAUNCHER_INPUT_H
#define LAUNCHER_INPUT_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QMouseEvent>
#include <QPropertyAnimation>

class Input : public QWidget {
Q_OBJECT
    Q_PROPERTY(int bkRGB READ bkRGB WRITE setBkRGB);
    Q_PROPERTY(int borderRGB READ borderRGB WRITE setBorderRGB);
public:
    Input(QWidget *parent);
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
private:
    void Init();
    int bkRGB() const;
    void setBkRGB(const int rgb);
    int borderRGB() const;
    void setBorderRGB(const int rgb);
private:
    int m_bkRGB = 236;
    int m_borderRGB = 236;
private:
    QLineEdit *m_lineEdit;
    QLabel *m_label;
    QPropertyAnimation *m_bk;
    QPropertyAnimation *m_bkBorder;
    QPropertyAnimation *m_labelPos;
};


#endif //LAUNCHER_INPUT_H