#include "Led.h"
#include "Button.h"

#define LED_1_PIN 2
#define LED_2_PIN 4
#define BUTTON_1_PIN 12
#define BUTTON_2_PIN 7

#define LED_A_PIN 9
#define LED_B_PIN 3
#define LED_C_PIN 5
#define LED_D_PIN 6
#define LED_E_PIN 11
#define LED_F_PIN 10
#define CONCURRENT_A_PIN 13

Led concurrentLeds[1] = {
  Led(CONCURRENT_A_PIN)
};

Led aLed(LED_1_PIN);
Led bLed(LED_2_PIN);
Button aButton(BUTTON_1_PIN);
Button bButton(BUTTON_2_PIN);

Led transmittingLeds[5] = { 
  Led(LED_A_PIN), 
  Led(LED_B_PIN), 
  //Led(LED_C_PIN),
  Led(LED_D_PIN),
  Led(LED_E_PIN),
  Led(LED_F_PIN) 
};

int brightness = 5;
int brightnessChangeAmt = 1;

bool isTransmitting = false;
int transmittingIndex = 0;
int transmittingDirection = 1;
int counter = 0;
bool aOn = false;
bool bOn = false;
unsigned long millisNow = 0;

void setup() { 
  Serial.begin(9600);
  delay(500);
}

void loop() {
  aOn = false;
  bOn = false;
  isTransmitting = false;
  millisNow = millis();

  for(int i = 0; i < aButton.getPresses(); i++) {
    // Transmitting if any lighting still to happen
    if (aButton.getOnTime(i) > millisNow || bButton.getOnTime(i) > millisNow) {
      isTransmitting = true;
    }
    if (aButton.getOnTime(i) <= millisNow && aButton.getOffTime(i) >= millisNow) {
      aOn = true;
    } 
    if (bButton.getOnTime(i) <= millisNow && bButton.getOffTime(i) >= millisNow) {
      bOn = true;
    } 
  }  
  // Turn on phone lights
  aOn ? aLed.on() : aLed.off();
  bOn ? bLed.on() : bLed.off();

  // Turn on concurrent lights
  if (aButton.getLastReading() == LOW || bButton.getLastReading() == LOW) {
    for(int i = 0; i < (sizeof(concurrentLeds) / sizeof(Led)); i++) {
      concurrentLeds[i].on();
    }
  } else {
    for(int i = 0; i < (sizeof(concurrentLeds) / sizeof(Led)); i++) {
      concurrentLeds[i].off();
    }
  }
  
  counter++;

  if (aOn || bOn) {
    // Turn off all but the two involved
    for(int i = 1; i < sizeof(transmittingLeds) / sizeof(transmittingLeds[0]) - 1; i++) { 
      transmittingLeds[i].off();
    }
    if(counter % 950 == 0) {
      if (transmittingLeds[0].getState()) {
        transmittingLeds[0].off();
        transmittingLeds[(sizeof(transmittingLeds) / sizeof(transmittingLeds[0])) - 1].on();
      } else {
        transmittingLeds[(sizeof(transmittingLeds) / sizeof(transmittingLeds[0])) - 1].off();
        transmittingLeds[0].on();        
      }
    }
  } else if (isTransmitting) {
    // Button has been pressed, not yet transmitting
    if(counter % 550 == 0) {
      transmittingIndex += transmittingDirection;
      if(transmittingIndex <= 0 || transmittingIndex >= (sizeof(transmittingLeds) / sizeof(transmittingLeds[0]) - 1)) {
        transmittingDirection *= -1;
      }
    }
    for(int i = 0; i < sizeof(transmittingLeds) / sizeof(transmittingLeds[0]); i++) { 
      if(i == transmittingIndex) {
        transmittingLeds[i].on();
      } else {
        transmittingLeds[i].off();
      }
    }
    // Reset brightness to 5
    brightness = 5;
    brightnessChangeAmt = 1;
  } else {
    // Fade all in and out
    for(int i = 0; i < sizeof(transmittingLeds) / sizeof(transmittingLeds[0]); i++) {
      analogWrite(transmittingLeds[i].getPin(), brightness);  
    }
    
    if(counter % 35 == 0) {
      brightness += brightnessChangeAmt;      
    }    
    if(brightness >= 254) {
      brightnessChangeAmt = -1;
    } else if(brightness <= 1) {
      brightnessChangeAmt = 1;
    }
  }

  // IF buttonState changes, update onTime and offTime
  if (aButton.getState() != aButton.getLastReading()) {
    setButtonTimes(&aButton);
  } 
  if (bButton.getState() != bButton.getLastReading()) {
	  setButtonTimes(&bButton);
  } 
}

void setButtonTimes(Button *btn) {
  // the button has been just pressed  
  if (btn->getLastReading() == LOW) {
    Serial.println("touched");    
    btn->setOnTime(millis());
  } 
  // the button has been just released
  else {
    Serial.println("released");
    btn->setOffTime(millis()); 
  }


  Serial.println(millis());
  Serial.println(millis() + btn->getDelayTime());
  Serial.print("[");
    Serial.print(btn->getOnTime(0));
  Serial.print(", ");
    Serial.print(btn->getOnTime(1));
    Serial.print(", ");
  Serial.print(btn->getOnTime(2));
    Serial.print(", ");
  Serial.print(btn->getOnTime(3));
    Serial.print(", ");
  Serial.print(btn->getOnTime(4));
    Serial.print(", ");
  Serial.print(btn->getOnTime(5));
    Serial.print(", ");
  Serial.print(btn->getOnTime(6));
    Serial.print(", ");
  Serial.print(btn->getOnTime(7));
    Serial.print(", ");
  Serial.print(btn->getOnTime(8));
    Serial.print(", ");
  Serial.print(btn->getOnTime(9));
  Serial.println("]");

	Serial.print("[");
	Serial.print(btn->getOffTime(0));
	Serial.print(", ");
	Serial.print(btn->getOffTime(1));
	Serial.print(", ");
	Serial.print(btn->getOffTime(2));
	Serial.print(", ");
	Serial.print(btn->getOffTime(3));
	Serial.print(", ");
	Serial.print(btn->getOffTime(4));
	Serial.print(", ");
	Serial.print(btn->getOffTime(5));
	Serial.print(", ");
	Serial.print(btn->getOffTime(6));
	Serial.print(", ");
	Serial.print(btn->getOffTime(7));
	Serial.print(", ");
	Serial.print(btn->getOffTime(8));
	Serial.print(", ");
	Serial.print(btn->getOffTime(9));
	Serial.println("]");
}
