#include "Led.h"
#include "Button.h"

#define LED_1_PIN 10
#define LED_2_PIN 4
#define BUTTON_1_PIN 12
#define BUTTON_2_PIN 3

Led aLed(LED_1_PIN);
Led bLed(LED_2_PIN);
Button aButton(BUTTON_1_PIN);
Button bButton(BUTTON_2_PIN);

void setup() { Serial.begin(9600); }

void loop() {
  if (bButton.isPressed() || aButton.isPressed()) {
    aLed.on();
	  bLed.off();
  }
  else {
    bLed.on();
	  aLed.off();
  }
}
