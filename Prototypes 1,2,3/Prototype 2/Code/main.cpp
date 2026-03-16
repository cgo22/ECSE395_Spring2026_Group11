#include <Arduino.h>
// This is required in PlatformIO but hidden in the standard Arduino IDE.

// Define LED output pin (GPIO 33)
#define LED_PIN 33
// Define built-in button switch (SW38)
#define SW38_PIN 38
// Counter initialization
int i = 0;

void setup() {
  // Configure LED as output
  pinMode(LED_PIN, OUTPUT);
  // Configure built-in switch as input
  pinMode(SW38_PIN, INPUT);
}

// Main loop to monitor hall effect sensor (simulated with button)
void loop() {
  
  // Integers used for negative edge detection
  int prev = HIGH;
  int curr = HIGH;

// Loop to count number of pills dispensed (or # of hall effect sensor triggers) - must be 5
  while (i < 5) {

      // Initializes LED to on before user has dispensed any pills
      digitalWrite(LED_PIN, HIGH);
      
      // Reads current state of button (simulates hall effect sensor)
      curr = digitalRead(SW38_PIN);
      // Case 1: Negative edge occurs
      if (curr == LOW && prev == HIGH) {
        // Increase pill counter
        i = i + 1;
        // Update previous value to LOW
        prev = LOW;
      }
      // Case 2: Remains LOW
      else if (curr == LOW) {
        // Update previous value to LOW
        prev = LOW;
      }
      // Case 3: Remains HIGH, or positive edge occurs
      else {
        prev = HIGH;
      }
      // 50 ms delay to prevent timing issues
      delay(50);
  }

  // Turns LED off once all pills are taken (hall effect triggered 5 times)
  digitalWrite(LED_PIN, LOW);

}


  