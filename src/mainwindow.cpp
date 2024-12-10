#include "mainwindow.h"

#include <QPainter>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    sceneManager(SceneManager::GetSceneManager())
{
    resize(WINDOW_SIZE_W, WINDOW_SIZE_H);

    frameUpdateTimer = new QTimer;
    frameUpdateTimer->setInterval(1000 / FRAME_RATE);
    connect(frameUpdateTimer, &QTimer::timeout, this, &MainWindow::Update);
    connect(frameUpdateTimer, &QTimer::timeout, this, &MainWindow::Render);
    frameUpdateTimer->start();

    fixedUpdateTimer = new QTimer;
    fixedUpdateTimer->setInterval(1000 / FIXED_UPDATE_RATE);
    connect(fixedUpdateTimer, &QTimer::timeout, this, &MainWindow::FixedUpdate);
    fixedUpdateTimer->start();

    input = new Input();

    sceneManager.LoadScene();

    connect(&sceneManager, &SceneManager::GameOver, this, &MainWindow::GameOver);
}

MainWindow::~MainWindow()
{
    // delete timeManager;
    // delete builtInTimer;

    delete input;

    // delete scene;
}

void MainWindow::Update()
{
    input->Update();
    sceneManager.Update();
}

void MainWindow::FixedUpdate()
{
    input->Update();
    sceneManager.FixedUpdate();
}

void MainWindow::Render()
{
    // rerender the window, by triggering paintEvent
    QMainWindow::update();
}

void MainWindow::GameOver(int coins)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("GameOver");
    msgBox.setText("Total coins: " + QString::number(coins));
    msgBox.setStandardButtons(QMessageBox::Ok);

    connect(&msgBox, &QMessageBox::accepted, this, &MainWindow::close);

    msgBox.exec();
}

void MainWindow::paintEvent(QPaintEvent *event) {
    // static int counter = 0;
    // qDebug() << "frame: " << ++counter;

    QPainter painter(this);
    sceneManager.Render(&painter);

    QMainWindow::paintEvent(event);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // qDebug() << "key press";
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
