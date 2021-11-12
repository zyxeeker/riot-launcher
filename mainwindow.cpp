#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    m_user = new Input(this);
    m_pwd = new Input(this);
    m_loginBtn = new Button(this);
    Init();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::Init() {
    ui->userContainer->addWidget(m_user);
    ui->pwdContainer->addWidget(m_pwd);
    ui->loginContainer->addWidget(m_loginBtn);
}

