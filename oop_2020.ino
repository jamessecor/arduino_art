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
  if(aButton.getState() != aButton.getLastReading()) {
    setLedOffTime(&aLed, &aButton);  
  }  
  if(bButton.getState() != bButton.getLastReading()) {
    setLedOffTime(&bLed, &bButton);
  }
  
  if(millis() % 1000 == 0) {
//Serial.println(digitalRead(aButton.getPin()));
//    Serial.println(aButton.getLastReading());
    Serial.println(millis());
  }
  if(bLed.getOnTime() < millis() && millis() < bLed.getOffTime()) {
    bLed.on();
  } else {
    bLed.off();
  }

  if(aLed.getOnTime() < millis() && millis() < aLed.getOffTime()) {
    aLed.on();
  } else {
    aLed.off();
  }
  
}

void setLedOffTime(Led *led, Button *btn) {
  // the button has been just pressed  
  if (btn->getLastReading() == LOW) {
    Serial.println("touched");
      btn->setLastStart(millis());
      btn->setDuration(0);
      led->setOnTime(led->getDelayTime() + millis());
  // the button has been just released
  } else {
    Serial.println("released");
      btn->setLastEnd(millis());
      btn->setDuration(btn->getLastEnd() - btn->getLastStart());
      led->setOffTime(led->getDelayTime() + btn->getDuration() + millis()); 
  }  
  Serial.println(millis());
  
  Serial.println(led->getOffTime());
  
  Serial.println();
  Serial.println();
}
