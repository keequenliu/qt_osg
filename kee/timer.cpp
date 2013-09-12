#include "timer.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>


using namespace kee;


Timer* Timer::instance()
{
    static Timer s_timer;
    return &s_timer;
}

Timer::Timer()
{
    m_secsPerTick = (1.0 / (double) 1000000);
    setStartTick();
}

#if defined(_POSIX_TIMERS) && ( _POSIX_TIMERS > 0 ) && defined(_POSIX_MONOTONIC_CLOCK)
#include <time.h>
#include <bits/time.h>

//返回纪元开始至现在的微秒数
Timer_t Timer::tick() const
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ((kee::Timer_t)ts.tv_sec)*1000000+(kee::Timer_t)ts.tv_nsec/1000;
}
#else
#include <sys/time.h>

Timer_t Timer::tick() const
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((kee::Timer_t)tv.tv_sec)*1000000+(kee::Timer_t)tv.tv_usec;
}
#endif


void Timer::setStartTick()
{
    m_startTick = tick();
}

