#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "component/input.h"
#include "component/button.h"

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
};
#endif // MAINWINDOW_H
