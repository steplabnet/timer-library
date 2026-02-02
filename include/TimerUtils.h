#ifndef TIMER_UTILS_H
#define TIMER_UTILS_H

#include <Arduino.h>

typedef enum
{
    TIMER_LED1,
    TIMER_LED2,
    TIMER_UART,
    TIMER_UART5,
    TIMER_UART2,
    TIMER_FLAG_LED2,
    TiMER_LED_ROSSO,
    TIMER_COUNT
} TimerID_t;
// Function declaration
bool isTimerReady(TimerID_t id, unsigned long interval, bool);
bool isTimerReady(TimerID_t id, unsigned long interval);
bool isTimerActive(TimerID_t id, unsigned long duration, bool trigger)

#endif