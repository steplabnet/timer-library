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
 * Automatically sets the 'trigger' variable back to false once started.
 *
 * @param trigger: Passed by reference (&), so it resets to false in the main loop.
 */
bool isTimerActive(TimerID_t id, unsigned long duration, bool &trigger)
{
    static unsigned long startTime[TIMER_COUNT] = {0};
    static bool running[TIMER_COUNT] = {false};

    if (id < 0 || id >= TIMER_COUNT)
        return false;

    // If trigger is true, start the timer and IMMEDIATELY reset the trigger
    if (trigger)
    {
        startTime[id] = millis();
        running[id] = true;
        trigger = false; // This changes the variable in the calling code
    }

    if (running[id])
    {
        // Check if we are still within the time window
        if (millis() - startTime[id] < duration)
        {
            return true;
        }
        else
        {
            running[id] = false; // Time's up
        }
    }

    return false;
}