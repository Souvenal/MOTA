#ifndef TIME_H
#define TIME_H

#include <QObject>

class TimeManager: public QObject
{
    Q_OBJECT
private:
    using Clock = std::chrono::high_resolution_clock;
    using TimePoint = std::chrono::time_point<Clock>;

    TimePoint lastFrameTime;
    TimePoint startTime;
    double deltaTime;
    double elapsedTime;
    double targetFrameTime;

public:
    void start();

    void setTargetTime(int fps);

public slots:
    void update();

signals:
    void timeout();
};

#endif // TIME_H
