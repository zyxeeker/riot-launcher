#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include "component/input.h"
#include "component/button.h"
#include "component/smooth_scroll_area.h"
#include "page/update_page.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void Init();
private:
    Ui::MainWindow *ui;
    Input *m_user;
    Input *m_pwd;
    Button *m_loginBtn;
    SmoothScrollArea *m_area;
    QHBoxLayout *m_updateL;
    UpdatePage *m_updatePage;
};
#endif // MAINWINDOW_H
