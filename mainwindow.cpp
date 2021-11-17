#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    m_user = new Input(this);
    m_pwd = new Input(this);
    m_loginBtn = new Button(this);
    m_area = new SmoothScrollArea(this);
    m_updateL = new QHBoxLayout;
    m_updatePage = new UpdatePage(this);

    Init();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::Init() {
    ui->userContainer->addWidget(m_user);
    ui->pwdContainer->addWidget(m_pwd);
    ui->loginContainer->addWidget(m_loginBtn);
    m_area->setGeometry(0, 0, 1280, 720);
    m_updateL->setContentsMargins(0, 0, 0, 0);
    m_updateL->addWidget(m_updatePage);
    m_area->SetContentLayout(m_updateL);

    connect(m_user, &Input::Clicked, this, [=]() {
        m_pwd->Rest();
    });
    connect(m_pwd, &Input::Clicked, this, [=]() {
        m_user->Rest();
    });
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_user->Rest();
        m_pwd->Rest();
    }
}

