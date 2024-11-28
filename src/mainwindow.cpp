#include "mainwindow.h"

#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(WINDOW_SIZE_W, WINDOW_SIZE_H);

    timeManager = new TimeManager;
    timeManager->setTargetTime(30);
    builtInTimer = new QTimer;
    builtInTimer->start(0); // timeout every event loop

    connect(builtInTimer, &QTimer::timeout,
            timeManager, &TimeManager::update);
    // connect(builtInTimer, &QTimer::timeout,
    //         this, &MainWindow::Control);

    connect(timeManager, &TimeManager::timeout,
            this, &MainWindow::Render);

    input = new Input();

    scene = CreateMap1();
}

MainWindow::~MainWindow()
{
    delete timeManager;
    delete builtInTimer;

    delete input;

    delete scene;
}

void MainWindow::Control()
{
    input->SetKeyIdle();
}

void MainWindow::Render()
{
    // rerender the window
    // qDebug() << "Window is rendering.";
    QMainWindow::update();
    input->Update();
}

void MainWindow::paintEvent(QPaintEvent *event) {
    // static int counter = 0;
    // qDebug() << "frame: " << ++counter;

    scene->Update();

    QPainter painter(this);

    scene->Render(&painter);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    Qt::Key key = static_cast<Qt::Key>(event->key());
    if (event->isAutoRepeat()) {
        input->SetKey(key);
    }
    else {
        input->SetKeyDown(key);
    }
    QMainWindow::keyPressEvent(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    Qt::Key key = static_cast<Qt::Key>(event->key());
    input->SetKeyUp(key);
    QMainWindow::keyPressEvent(event);
}
