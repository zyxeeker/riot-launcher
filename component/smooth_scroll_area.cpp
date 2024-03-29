//
// Created by zyx on 2021/8/19.
//

#include "smooth_scroll_area.h"

SmoothScrollArea::SmoothScrollArea(QWidget *parent) : QScrollArea(parent) {
    m_content = new QWidget;
    m_smoothMoveTimer = new QTimer(this);
    m_lastWheelEvent = nullptr;
    m_content->setObjectName("bk");
    m_content->setStyleSheet("#bk{background:#232323;}");
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
#if 0
    this->setObjectName("QScrollArea");
    this->setStyleSheet("QScrollArea {border:none;}"
                        "QScrollBar:vertical {border: none;background: rgb(23,23,23);width: 5px;margin: 0px 0 0px 0;}"
                        "QScrollBar::handle:vertical {background: rgb(61,61,61);min-height: 20px;border-radius: 2px;border: none;}"
                        "QScrollBar::add-line:vertical {border: none;background: rgb(0, 0, 0);height: 0px;subcontrol-position: bottom;subcontrol-origin: margin;}"
                        "QScrollBar::sub-line:vertical {border: none;background: rgb(0, 0, 0);height: 0px;subcontrol-position: top;subcontrol-origin: margin;}"
                        "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background: none;width: 0px;height: 0px;}");
#endif
    this->setWidgetResizable(true);
    this->setWidget(m_content);
    connect(m_smoothMoveTimer, &QTimer::timeout, this, &SmoothScrollArea::SmoothMove);

}

void SmoothScrollArea::SetContentLayout(QLayout *l) {
    m_content->setLayout(l);
}

void SmoothScrollArea::wheelEvent(QWheelEvent *e) {
    static QQueue<qint64> scrollStamps;
    qint64 now = QDateTime::currentDateTime().toMSecsSinceEpoch();
    scrollStamps.enqueue(now);
    while (now - scrollStamps.front() > 500)
        scrollStamps.dequeue();
    double accerationRatio = qMin(scrollStamps.size() / 15.0, 1.0);

    if (!m_lastWheelEvent)
        m_lastWheelEvent = new QWheelEvent(*e);
    else
        *m_lastWheelEvent = *e;

    m_stepsTotal = m_fps * m_duration / 1000;
    double multiplier = 1.0;
    double delta = e->delta() * multiplier;
    if (m_acceleration > 0)
        delta += delta * m_acceleration * accerationRatio;

    m_stepsLeftQueue.push_back(qMakePair(delta, m_stepsTotal));
    m_smoothMoveTimer->start(1000 / m_fps);
}

void SmoothScrollArea::SmoothMove() {
    double totalDelta = 0;

    for (QList<QPair<double, int> >::Iterator it = m_stepsLeftQueue.begin();
         it != m_stepsLeftQueue.end(); ++it) {
        totalDelta += SubDelta(it->first, it->second);
        --(it->second);
    }
    while (!m_stepsLeftQueue.empty() && m_stepsLeftQueue.begin()->second == 0)
        m_stepsLeftQueue.pop_front();

    Qt::Orientation orientation = m_lastWheelEvent->orientation();

    QWheelEvent e(
            m_lastWheelEvent->pos(),
            m_lastWheelEvent->globalPos(),
            qRound(totalDelta),
            m_lastWheelEvent->buttons(),
            0,
            orientation
    );
    if (e.orientation() == Qt::Horizontal)
        QApplication::sendEvent(reinterpret_cast<QObject *>(this->horizontalScrollBar()), &e);
    else
        QApplication::sendEvent(reinterpret_cast<QObject *>(this->verticalScrollBar()), &e);

    if (m_stepsLeftQueue.empty())
        m_smoothMoveTimer->stop();
}

double SmoothScrollArea::SubDelta(double delta, int stepsLeft) {
    double m = m_stepsTotal / 2.0;
    double x = abs(m_stepsTotal - stepsLeft - m);
    return 2.0 * delta / m_stepsTotal * (m - x) / m;
}
