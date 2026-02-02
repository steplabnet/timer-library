#ifndef TIMER_UTILS_H
#define TIMER_UTILS_H

#include <Arduino.h>

typedef enum
{
    TIMER_LED1,
    TIMER_LED2,
    TIMER_UART,
    TIMER_COUNT
} TimerID_t;
// Function declaration
bool isTimerReady(TimerID_t id, unsigned long interval);

#endif