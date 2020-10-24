#include "Button.h"

Button::Button(int buttonPin) {
	this->pin = buttonPin;	
  init();
}

void Button::init() {
	pinMode(pin, INPUT_PULLUP);
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

void Button::setLastStart(int start) {
  lastStart = start;
}
int Button::getLastStart() {
  return lastStart;
}

void Button::setLastEnd(int endTime) {
  lastEnd = endTime;
}
int Button::getLastEnd() {
  return lastEnd;
}

void Button::setDuration(int dur) {
  duration = dur;
}
int Button::getDuration() {
  return duration;
}

bool Button::isPressed() {
  return (getState() == LOW);
}
