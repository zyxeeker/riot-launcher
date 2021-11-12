//
// Created by zyx on 2021/11/12.
//

#ifndef LAUNCHER_BUTTON_H
#define LAUNCHER_BUTTON_H

#include <QPushButton>
#include <QPropertyAnimation>

class Button : public QPushButton {
Q_OBJECT
    Q_PROPERTY(double alpha READ alpha WRITE setAlpha);
    Q_PROPERTY(int gb READ gb WRITE setGB);
    Q_PROPERTY(int r READ r WRITE setR);
public:
    Button(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    int alpha() const;
    int gb() const;
    int r() const;
    void setAlpha(int alpha);
    void setGB(const int gb);
    void setR(const int r);
private:
    bool m_isHover = false;
    bool m_isPressed = false;
    int m_r = 232;
    int m_gb = 232;
    int m_alpha = 255;
    QPixmap m_icon;
    QPropertyAnimation *m_upAnimation;
    QPropertyAnimation *m_downAnimation;
    QPropertyAnimation *m_startAnimation;
    QPropertyAnimation *m_startAnimation1;
    QPropertyAnimation *m_hoverAnimation;
    QPropertyAnimation *m_leaveAnimation;
};


#endif //LAUNCHER_BUTTON_H
