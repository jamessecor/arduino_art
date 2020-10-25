#include "Led.h"
#include "Button.h"

#define LED_1_PIN 10
#define LED_2_PIN 4
#define BUTTON_1_PIN 12
#define BUTTON_2_PIN 7

#define LED_A_PIN 0
#define LED_B_PIN 3
#define LED_C_PIN 5

Led aLed(LED_1_PIN);
Led bLed(LED_2_PIN);
Button aButton(BUTTON_1_PIN);
Button bButton(BUTTON_2_PIN);

Led firstLed(LED_A_PIN);
Led secondLed(LED_B_PIN);
Led thirdLed(LED_C_PIN);

int brightness = 0;
int brightnessChangeAmt = 1;

void setup() { 
  Serial.begin(9600);
}

void loop() {
  if (aButton.isPressed() || bButton.isPressed()) {
    firstLed.off();
    secondLed.off();
    thirdLed.off();
  } else {
    analogWrite(firstLed.getPin(), brightness);
    analogWrite(secondLed.getPin(), brightness);
    analogWrite(thirdLed.getPin(), brightness);
    if(millis() % 75 == 0) {
      brightness += brightnessChangeAmt;  
      Serial.println(brightness);
    }    
    if(brightness > 254) {
      brightnessChangeAmt = -1;
    } else if(brightness < 1) {
      brightnessChangeAmt = 1;
    }
  }

  if (aButton.isPressed()) {
    aLed.on();
  } else {
    aLed.off();
  }
  if (bButton.isPressed()) {
    bLed.on();
  } else {
    bLed.off();
  } 
}

void setLedOffTime(Led *led, Button *btn) {
  // the button has been just pressed  
  if (btn->getLastReading() == LOW) {
    Serial.println("touched");
      btn->setLastStart(millis());
//      btn->setDuration(0);
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
