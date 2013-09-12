#ifndef TIMER_H
#define TIMER_H

namespace kee
{

#if defined(_MSC_VER)
typedef __int64 Timer_t;
#else
typedef unsigned long long Timer_t;
#endif

/**
 * 记录时间的时刻,可以转化为s,ms,us,ns
 **/
class Timer
{
public :
    Timer();
    ~Timer(){};

    static Timer* instance();

    Timer_t tick() const;
    void setStartTick();
    void setStartTick(Timer_t t) { m_startTick = t; }
    Timer_t getStartTick() const { return m_startTick; }


    /** Get elapsed time in seconds.*/
    inline double time_s() const { return delta_s(m_startTick, tick()); }

    /** Get elapsed time in milliseconds.*/
    inline double time_m() const { return delta_m(m_startTick, tick()); }

    /** Get elapsed time in microseconds.*/
    inline double time_u() const { return delta_u(m_startTick, tick()); }

    /** Get elapsed time in nanoseconds.*/
    inline double time_n() const { return delta_n(m_startTick, tick()); }

    /** Get the time in seconds between timer ticks t1 and t2.*/
    inline double delta_s( Timer_t t1, Timer_t t2 ) const { return (double)(t2 - t1)*m_secsPerTick; }

    /** Get the time in milliseconds between timer ticks t1 and t2.*/
    inline double delta_m( Timer_t t1, Timer_t t2 ) const { return delta_s(t1,t2)*1e3; }

    /** Get the time in microseconds between timer ticks t1 and t2.*/
    inline double delta_u( Timer_t t1, Timer_t t2 ) const { return delta_s(t1,t2)*1e6; }

    /** Get the time in nanoseconds between timer ticks t1 and t2.*/
    inline double delta_n( Timer_t t1, Timer_t t2 ) const { return delta_s(t1,t2)*1e9; }

private:
    Timer_t m_startTick;
    double  m_secsPerTick;
};


}
#endif // TIMER_H
