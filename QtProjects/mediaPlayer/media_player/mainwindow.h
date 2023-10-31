#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QtMultimediaWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_stop_clicked();

    void on_pause_clicked();

    void on_play_clicked();

private:
    Ui::MainWindow *ui;

    QMediaPlayer * player;
    QAudioOutput * audioOutput;
    QVideoWidget * videoWidget;

};
#endif // MAINWINDOW_H
