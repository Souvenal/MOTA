#include "timemanager.h"

void TimeManager::start()
{
    startTime = Clock::now();
    lastFrameTime = startTime;
    deltaTime = 0.0;
    elapsedTime = 0.0;
}

void TimeManager::setTargetTime(int fps)
{
    if (fps > 0)
        targetFrameTime = 1.0 / fps;
}


void TimeManager::update()
{
    TimePoint curFrameTime = Clock::now();
    std::chrono::duration<double> frameDuration = curFrameTime - lastFrameTime;
    deltaTime = frameDuration.count();

    if (deltaTime >= targetFrameTime) {
        lastFrameTime = curFrameTime;
        deltaTime = 0;
        std::chrono::duration<double> totalDuration = curFrameTime - startTime;
        elapsedTime = totalDuration.count();
        emit timeout();
    }
}
