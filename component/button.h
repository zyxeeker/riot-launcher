//
// Created by zyx on 2021/11/12.
//

#ifndef LAUNCHER_BUTTON_H
#define LAUNCHER_BUTTON_H

#include <QPushButton>

class Button : public QPushButton {
Q_OBJECT
public:
    Button(QWidget *parent);
private:
    void Init();
};


#endif //LAUNCHER_BUTTON_H
