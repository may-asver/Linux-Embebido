/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *stop;
    QPushButton *pause;
    QPushButton *play;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *video;
    QSlider *horizontalSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stop = new QPushButton(centralwidget);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setGeometry(QRect(150, 460, 89, 51));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/stop.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        stop->setIcon(icon);
        stop->setIconSize(QSize(25, 25));
        pause = new QPushButton(centralwidget);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setGeometry(QRect(300, 460, 89, 51));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/pause.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pause->setIcon(icon1);
        pause->setIconSize(QSize(25, 25));
        play = new QPushButton(centralwidget);
        play->setObjectName(QString::fromUtf8("play"));
        play->setGeometry(QRect(450, 460, 89, 51));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/play.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        play->setIcon(icon2);
        play->setIconSize(QSize(25, 25));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 40, 731, 311));
        video = new QHBoxLayout(horizontalLayoutWidget);
        video->setObjectName(QString::fromUtf8("video"));
        video->setContentsMargins(0, 0, 0, 0);
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(120, 390, 471, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        stop->setText(QString());
        pause->setText(QString());
        play->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
