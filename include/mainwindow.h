#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "global.h"
#include "timemanager.h"
#include "map.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    TimeManager *timeManager;
    QTimer *builtInTimer;

    Input *input;

    Scene *scene;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void Control();
    void Render();

protected:
    void paintEvent(QPaintEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
};
#endif // MAINWINDOW_H
