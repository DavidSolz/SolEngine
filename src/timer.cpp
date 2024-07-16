#include "timer.h"

#include <stdio.h>

Timer::Timer()
{
    this->m_startTime = Clock::now();
}

double Timer::getElapsed() const
{
    const auto now = Clock::now();
    const Duration elapsed = now - m_startTime;
    return elapsed.count();
}

double Timer::restart()
{
    const auto now = Clock::now();
    const Duration elapsed = now - m_startTime;
    m_startTime = now;
    return elapsed.count();
}

void Timer::sleepForSeconds(const double &time)
{
    std::this_thread::sleep_for(Duration(time));
}
