#include "TimerUtils.h"


bool isTimerReady(TimerID_t id, unsigned long interval)
{

    // static ensures this array persists in memory between function calls
    static unsigned long lastTime[TIMER_COUNT] = {0};

    // Safety check to prevent array out-of-bounds errors
    if (id < 0 || id >= TIMER_COUNT)
        return false;

    if (millis() - lastTime[id] >= interval)
    {
        lastTime[id] += interval;
        return true;
    }
    return false;
}