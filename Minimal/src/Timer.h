#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <thread>


class Timer
{
public:
    Timer(double fps);
    void waitTick();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> time_point;
    std::chrono::milliseconds timeToWait;
    int fps;
};


#endif // TIMER_H
