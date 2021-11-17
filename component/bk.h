//
// Created by zyx on 2021/11/17.
//

#ifndef LAUNCHER_BK_H
#define LAUNCHER_BK_H

#include <QLabel>
#include <QPropertyAnimation>

class bk : public QLabel {
Q_OBJECT
    Q_PROPERTY(double alpha READ alpha WRITE setAlpha);
public:
    bk(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    int alpha() const;
    void setAlpha(int alpha);
private:
    int m_alpha = 0;
    QPropertyAnimation *m_animation;
public slots:
    void Change(bool st);
};


#endif //LAUNCHER_BK_H
