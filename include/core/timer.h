#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>
#include <chrono>
#include <thread>

class Timer
{

private:
    using Clock = std::chrono::high_resolution_clock;
    using Timepoint = Clock::time_point;
    using Duration = std::chrono::duration<double>;

    Timepoint m_startTime;

public:
    Timer();

    double getElapsed() const;

    double restart();

    void sleepForSeconds(const double &time);
};

#endif
