#include "Button.h"

Button::Button(int buttonPin) {
	this->pin = buttonPin;
	init();
}

void Button::init() {
	pinMode(pin, INPUT_PULLUP);
  for(int i = 0; i < Button::PRESSES; i++) {
    onTime[i] = (unsigned long) 0;
    offTime[i] = (unsigned long) 0;
  }
	update();
}

int Button::getPin() {
  return pin;  
}

void Button::setUpdatedAt(unsigned long updateTime) {
  updated_at = updateTime;
}
unsigned long Button::getUpdatedAt() {
  return updated_at;
}
    
void Button::update() {

  if((millis() - getUpdatedAt()) > 100) {
    // You can handle the debounce of the button directly
    // in the class, so you don't have to think about it
    // elsewhere in your code
    int newReading = digitalRead(pin);
    
    setUpdatedAt(millis());
    
    if (newReading != lastReading) {
      lastDebounceTime = millis();
    }
    if (millis() - lastDebounceTime > debounceDelay) {
      // Update the 'state' attribute only if debounce is checked
      state = newReading;
    }
    lastReading = newReading;
  }
}

int Button::getState() {
  update();
  return state;
}

int Button::getLastReading() {
  return lastReading;
}

bool Button::isPressed() {
  return (getState() == LOW);
}

int Button::getPresses() {
  return PRESSES;
}

void Button::clearUsedTimes(unsigned long m) {
  unsigned long mPlusDelay = m + getDelayTime();
  for(int i = 0; i < Button::PRESSES; i++) {
    if(onTime[i] > 0 && onTime[i] < mPlusDelay && offTime[i] > 0 && offTime[i] < mPlusDelay) {
      onTime[i] = (unsigned long) 0;
      offTime[i] = (unsigned long) 0;
    }
  }
}
void Button::setOnTime(unsigned long newOnTime) {
  clearUsedTimes(newOnTime);
  for(int i = 0; i < Button::PRESSES; i++) {
    if(onTime[i] == 0) {
      onTime[i] = newOnTime;  
      break;
    }    
  }
}    
void Button::setOffTime(unsigned long newOffTime) {
  clearUsedTimes(newOffTime);
  for(int i = 0; i < Button::PRESSES; i++) {
    if(offTime[i] == 0) {
      offTime[i] = newOffTime;  
      break;
    }    
  }
}

unsigned long Button::getOnTime(int index) {
  return onTime[index];
}
unsigned long Button::getOffTime(int index) {
  return offTime[index];
}

unsigned long Button::getDelayTime() {
  return delayTime;
}
