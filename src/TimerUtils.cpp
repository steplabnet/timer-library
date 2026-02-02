#include "TimerUtils.h"

/**
 * Periodically returns true every 'interval' milliseconds.
 * Useful for tasks like blinking an LED or reading a sensor at a set rate.
 */
bool isTimerReady(TimerID_t id, unsigned long interval, bool active)
{
    if (active == false)
        return false;

    static unsigned long lastTime[TIMER_COUNT] = {0};

    if (id < 0 || id >= TIMER_COUNT)
        return false;

    if (millis() - lastTime[id] >= interval)
    {
        lastTime[id] += interval;
        return true;
    }
    return false;
}

bool isTimerReady(TimerID_t id, unsigned long interval)
{
    return isTimerReady(id, interval, true);
}

/**
 * Returns true for the duration of 'duration' once 'trigger' is activated.
 * Useful for running code FOR a specific amount of time (e.g., running a pump for 10s).
 */
bool isTimerActive(TimerID_t id, unsigned long duration, bool trigger)
{
    static unsigned long startTime[TIMER_COUNT] = {0};
    static bool running[TIMER_COUNT] = {false};

    if (id < 0 || id >= TIMER_COUNT)
        return false;

    // If trigger is hit, record start time and set state to running
    if (trigger)
    {
        startTime[id] = millis();
        running[id] = true;
    }

    // Check if the timer is still within the duration
    if (running[id])
    {
        if (millis() - startTime[id] < duration)
        {
            return true;
        }
        else
        {
            running[id] = false; // Duration expired
        }
    }

    return false;
}