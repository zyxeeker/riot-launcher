//
// Created by zyx on 2021/11/16.
//

#ifndef LAUNCHER_PLAY_BUTTON_H
#define LAUNCHER_PLAY_BUTTON_H

#include <QPushButton>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>

class PlayButton : public QPushButton {
Q_OBJECT
    Q_PROPERTY(double alpha READ alpha WRITE setAlpha);
    Q_PROPERTY(int radius READ radius WRITE setRadius);
public:
    PlayButton(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
private:
    int alpha() const;
    void setAlpha(int alpha);
    int radius() const;
    void setRadius(const int radius);
private:
    QPixmap m_play;
    QPixmap m_pause;
    int m_alpha = 50;
    int m_radius = 20;
    QPropertyAnimation *m_hoverAnimation;
    QPropertyAnimation *m_shadow;
    QGraphicsDropShadowEffect *m_effect;
};


#endif //LAUNCHER_PLAY_BUTTON_H
