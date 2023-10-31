#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile("/home/root/Metallica_Enter_Sandman.mp4"));
    audioOutput->setVolume(0.3);
    // Play mp4
    videoWidget = new QVideoWidget(this);
    videoWidget->resize(640,480);
    videoWidget->show();
    player->setVideoOutput(videoWidget);

    ui->video->addWidget(videoWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_stop_clicked()
{
    player->stop();
}


void MainWindow::on_pause_clicked()
{
    player->pause();
}


void MainWindow::on_play_clicked()
{
    player->play();
}

