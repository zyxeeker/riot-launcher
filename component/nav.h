//
// Created by zyx on 2021/11/15.
//

#ifndef LAUNCHER_NAV_H
#define LAUNCHER_NAV_H

#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>

class Nav : public QPushButton{
    Q_OBJECT
    Q_PROPERTY(int radius READ radius WRITE setRadius);
    Q_PROPERTY(int alpha READ alpha WRITE setAlpha);
public:
    Nav(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
private:
    QPixmap GeneratePixmap(const QPixmap &src);
    int alpha() const;
    int radius() const;
    void setAlpha(const int alpha);
    void setRadius(const int radius);
private:
    bool m_isHover = false;
    int m_radius = 20;
    int m_alpha = 180;
    QPixmap m_pix;
    QLabel *m_title;
    QLabel *m_key;
    QPropertyAnimation *m_shadow;
    QPropertyAnimation *m_mask;
    QGraphicsDropShadowEffect *m_effect;
signals:
    void mousePos(bool);
};


#endif //LAUNCHER_NAV_H
