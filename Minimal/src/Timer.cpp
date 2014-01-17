#include "Timer.h"


Timer::Timer(double fps)
:
    time_point(std::chrono::high_resolution_clock::now()),
    timeToWait(int(1.0 / fps * 1000.0))
{
}

void Timer::waitTick()
{
    auto now_time_point = std::chrono::high_resolution_clock::now();
    while (now_time_point > time_point)
        time_point += timeToWait;
    std::this_thread::sleep_for(time_point - now_time_point);
}
