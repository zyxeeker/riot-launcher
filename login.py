# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'login.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1281, 720)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setStyleSheet("QWidget{\n"
"    background-color:white;\n"
"}")
        self.centralwidget.setObjectName("centralwidget")
        self.downloading = QtWidgets.QProgressBar(self.centralwidget)
        self.downloading.setGeometry(QtCore.QRect(640, 650, 531, 20))
        self.downloading.setProperty("value", 24)
        self.downloading.setObjectName("downloading")
        self.area = QtWidgets.QComboBox(self.centralwidget)
        self.area.setEnabled(True)
        self.area.setGeometry(QtCore.QRect(60, 190, 264, 32))
        font = QtGui.QFont()
        font.setFamily("微软雅黑")
        font.setBold(True)
        font.setWeight(75)
        self.area.setFont(font)
        self.area.setStyleSheet("QComboBox#area{\n"
"padding-left:20px;\n"
"    background-color:#EDEDED;\n"
"    border-radius:5px;\n"
"}\n"
"\n"
"QComboBox#area::hover{\n"
"    background-color:#E7E7E7;\n"
"}\n"
"\n"
"QComboBox#area::on{\n"
"color:white;\n"
"    padding-left: 20px;\n"
"    background-color:#111111;\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"width: 40px;\n"
"border-radius:10px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"border:1px solid #dddddd;\n"
"outline:0px;\n"
"height:63px;\n"
"\n"
"} \n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"height: 90px;\n"
"background:#111111;\n"
"color:#C7C7C7;\n"
"}\n"
"\n"
"\n"
"QComboBox QAbstractItemView::item:hover\n"
"{    \n"
"background-color:#111111;\n"
"    color:white;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item:selected\n"
"{    \n"
"background-color:#111111;\n"
"    color:white;\n"
"}")
        self.area.setObjectName("area")
        self.area.addItem("")
        self.area.addItem("")
        self.login = QtWidgets.QPushButton(self.centralwidget)
        self.login.setGeometry(QtCore.QRect(140, 360, 63, 63))
        palette = QtGui.QPalette()
        brush = QtGui.QBrush(QtGui.QColor(255, 255, 255))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Active, QtGui.QPalette.WindowText, brush)
        brush = QtGui.QBrush(QtGui.QColor(209, 54, 57))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Active, QtGui.QPalette.Button, brush)
        brush = QtGui.QBrush(QtGui.QColor(255, 255, 255))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Active, QtGui.QPalette.Text, brush)
        brush = QtGui.QBrush(QtGui.QColor(255, 255, 255))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Active, QtGui.QPalette.ButtonText, brush)
        brush = QtGui.QBrush(QtGui.QColor(209, 54, 57))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Active, QtGui.QPalette.Base, brush)
        brush = QtGui.QBrush(QtGui.QColor(209, 54, 57))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Active, QtGui.QPalette.Window, brush)
        brush = QtGui.QBrush(QtGui.QColor(255, 255, 255, 128))
        brush.setStyle(QtCore.Qt.NoBrush)
        palette.setBrush(QtGui.QPalette.Active, QtGui.QPalette.PlaceholderText, brush)
        brush = QtGui.QBrush(QtGui.QColor(255, 255, 255))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Inactive, QtGui.QPalette.WindowText, brush)
        brush = QtGui.QBrush(QtGui.QColor(209, 54, 57))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Inactive, QtGui.QPalette.Button, brush)
        brush = QtGui.QBrush(QtGui.QColor(255, 255, 255))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Inactive, QtGui.QPalette.Text, brush)
        brush = QtGui.QBrush(QtGui.QColor(255, 255, 255))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Inactive, QtGui.QPalette.ButtonText, brush)
        brush = QtGui.QBrush(QtGui.QColor(209, 54, 57))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Inactive, QtGui.QPalette.Base, brush)
        brush = QtGui.QBrush(QtGui.QColor(209, 54, 57))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Inactive, QtGui.QPalette.Window, brush)
        brush = QtGui.QBrush(QtGui.QColor(255, 255, 255, 128))
        brush.setStyle(QtCore.Qt.NoBrush)
        palette.setBrush(QtGui.QPalette.Inactive, QtGui.QPalette.PlaceholderText, brush)
        brush = QtGui.QBrush(QtGui.QColor(255, 255, 255))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Disabled, QtGui.QPalette.WindowText, brush)
        brush = QtGui.QBrush(QtGui.QColor(209, 54, 57))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Disabled, QtGui.QPalette.Button, brush)
        brush = QtGui.QBrush(QtGui.QColor(255, 255, 255))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Disabled, QtGui.QPalette.Text, brush)
        brush = QtGui.QBrush(QtGui.QColor(255, 255, 255))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Disabled, QtGui.QPalette.ButtonText, brush)
        brush = QtGui.QBrush(QtGui.QColor(209, 54, 57))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Disabled, QtGui.QPalette.Base, brush)
        brush = QtGui.QBrush(QtGui.QColor(209, 54, 57))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Disabled, QtGui.QPalette.Window, brush)
        brush = QtGui.QBrush(QtGui.QColor(255, 255, 255, 128))
        brush.setStyle(QtCore.Qt.NoBrush)
        palette.setBrush(QtGui.QPalette.Disabled, QtGui.QPalette.PlaceholderText, brush)
        self.login.setPalette(palette)
        font = QtGui.QFont()
        font.setFamily("System")
        font.setPointSize(15)
        font.setBold(True)
        font.setWeight(75)
        self.login.setFont(font)
        self.login.setStyleSheet("QPushButton#login\n"
"{\n"
"    background-color:#D13639;\n"
"    color:white;\n"
"    border-radius:20px;\n"
"}\n"
"QPushButton#login::hover{\n"
"    background-color:#D13639;\n"
"}")
        self.login.setProperty("UI_AnimateCombo", False)
        self.login.setObjectName("login")
        self.pushButton = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton.setGeometry(QtCore.QRect(1160, 0, 61, 41))
        self.pushButton.setObjectName("pushButton")
        self.pushButton_2 = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_2.setGeometry(QtCore.QRect(1220, 0, 61, 41))
        self.pushButton_2.setObjectName("pushButton_2")
        self.pushButton_3 = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_3.setGeometry(QtCore.QRect(1100, 0, 61, 41))
        self.pushButton_3.setObjectName("pushButton_3")
        self.background = QtWidgets.QGraphicsView(self.centralwidget)
        self.background.setGeometry(QtCore.QRect(395, 0, 891, 721))
        self.background.setObjectName("background")
        self.icon = QtWidgets.QGraphicsView(self.centralwidget)
        self.icon.setGeometry(QtCore.QRect(130, 60, 131, 111))
        self.icon.setObjectName("icon")
        self.textBrowser = QtWidgets.QTextBrowser(self.centralwidget)
        self.textBrowser.setGeometry(QtCore.QRect(60, 240, 261, 41))
        self.textBrowser.setObjectName("textBrowser")
        self.area.raise_()
        self.login.raise_()
        self.background.raise_()
        self.downloading.raise_()
        self.icon.raise_()
        self.textBrowser.raise_()
        self.pushButton_3.raise_()
        self.pushButton.raise_()
        self.pushButton_2.raise_()
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.area.setItemText(0, _translate("MainWindow", "1"))
        self.area.setItemText(1, _translate("MainWindow", "2"))
        self.login.setText(_translate("MainWindow", "→"))
        self.pushButton.setText(_translate("MainWindow", "口"))
        self.pushButton_2.setText(_translate("MainWindow", "×"))
        self.pushButton_3.setText(_translate("MainWindow", "-"))
