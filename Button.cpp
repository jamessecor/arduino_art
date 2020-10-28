#include "Button.h"

Button::Button(int buttonPin) {
	this->pin = buttonPin;
	init();
}

void Button::init() {
	pinMode(pin, INPUT_PULLUP);
  for(int i = 0; i < Button::PRESSES; i++) {
    onTime[i] = (unsigned long) -1;
    offTime[i] = (unsigned long) -1;
  }
	update();
}

int Button::getPin() {
  return pin;  
}

void Button::update() {
    // You can handle the debounce of the button directly
    // in the class, so you don't have to think about it
    // elsewhere in your code
    int newReading = digitalRead(pin);
    
    if (newReading != lastReading) {
      lastDebounceTime = millis();
    }
    if (millis() - lastDebounceTime > debounceDelay) {
      // Update the 'state' attribute only if debounce is checked
      state = newReading;
    }
    lastReading = newReading;
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
  for(int i = 0; i < Button::PRESSES; i++) {
    if(offTime[i] < m) {
      onTime[i] = (unsigned long) -1;
      offTime[i] = (unsigned long) -1;
    }
  }
}
void Button::setOnTime(unsigned long newOnTime) {
  clearUsedTimes(newOnTime);
  for(int i = 0; i < Button::PRESSES; i++) {
    if(onTime[i] < 0) {
      onTime[i] = newOnTime;  
      break;
    }    
  }
}    
void Button::setOffTime(unsigned long newOffTime) {
  clearUsedTimes(newOffTime);
  for(int i = 0; i < Button::PRESSES; i++) {
    if(offTime[i] < 0) {
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
