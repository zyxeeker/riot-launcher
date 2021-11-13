//
// Created by 19047 on 2021/11/13.
//

#ifndef LAUNCHER_UPDATE_H
#define LAUNCHER_UPDATE_H

#include <QPushButton>
#include <QLabel>
#include <QPropertyAnimation>

class UpdateCtrl : public QPushButton {
    Q_OBJECT
    Q_PROPERTY(double scale READ scale WRITE setScale);
public:
    UpdateCtrl(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
//    void mousePressEvent(QMouseEvent *event) override;
//    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    double scale() const;
    void setScale(const double scale);
private:
    double m_scale = 1.0;
    bool m_isPause = false;
    bool m_start = false;
    QLabel *m_title;
    QLabel *m_st;
    QPixmap m_download;
    QPixmap m_pause;
    QPropertyAnimation *m_hover;
};


#endif //LAUNCHER_UPDATE_H
