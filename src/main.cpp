#include <Arduino.h>
#include <TimerUtils.h>
// The timer function

// Define the pins
const int ledPin1 = 2; // Often the onboard LED
const int ledPin2 = 4;
const int ledRed = 22;
bool flagLed2 = false;
bool flagRedLed = false;
bool flagled2b = false;

void setup()
{
  Serial.begin(115200);
  // Initialize the pins as outputs
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledRed, OUTPUT);
  for (int i = 0; i < 25; i++)
  {
    digitalWrite(ledRed, !digitalRead(ledRed));
    delay(100);
  }
}

void loop()
{
  // Turn both LEDs ON
  if (isTimerReady(TIMER_LED1, 150))
    digitalWrite(ledPin1, !digitalRead(ledPin1));

  if (isTimerReady(TIMER_LED2, 200, flagLed2))
    digitalWrite(ledPin2, !digitalRead(ledPin2));

  if (isTimerReady(TIMER_UART, 1000))
    Serial.println("every 1 second");
  if (isTimerReady(TIMER_UART5, 5000))
    Serial.println("every 5 seconds");

  if (isTimerReady(TIMER_UART2, 2000))
    Serial.println("every 2 secods");

  if (isTimerReady(TIMER_FLAG_LED2, 5000))
  {
    flagLed2 = !flagLed2;
    flagled2b = true;
    flagRedLed = true;
  }

  if (isTimerActive(TiMER_LED_RED, 3000, flagRedLed))
  {
    digitalWrite(ledRed, HIGH);
  }
  else
  {
    digitalWrite(ledRed, LOW);
  }
  if (isTimerActive(TIMER_FLAG_LED2, 2000, flagled2b))
  {
    digitalWrite(ledPin2, HIGH);
  }
  else
  {
    //digitalWrite(ledPin2, LOW);
  }
  delay(5); // Wait for 500ms

  // Turn both LEDs OFF
}