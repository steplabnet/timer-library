#include <Arduino.h>
#include <TimerUtils.h>
// The timer function

// Define the pins
const int ledPin1 = 2; // Often the onboard LED
const int ledPin2 = 4;

void setup()
{
  Serial.begin(115200);
  // Initialize the pins as outputs
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop()
{
  // Turn both LEDs ON
  if (isTimerReady(TIMER_LED1, 150))
    digitalWrite(ledPin1, !digitalRead(ledPin1));
  if (isTimerReady(TIMER_LED2, 200))
    digitalWrite(ledPin2, !digitalRead(ledPin2));

  if (isTimerReady(TIMER_UART, 1000))
    Serial.println("every 1 second");
  delay(5); // Wait for 500ms

  // Turn both LEDs OFF
}