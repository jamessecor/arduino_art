#include "Led.h"

Led::Led(int ledPin) {
  this->pin = ledPin;
  init();
}

void Led::init() {
	pinMode(pin, OUTPUT);
	off();
}

void Led::off() {
	digitalWrite(pin, LOW);
}

void Led::on() {
	digitalWrite(pin, HIGH);
}

int Led::getPin() {
  return pin;
}

void Led::setOnTime(int t) {
//  if(lastUsedIndex >= 0) {
//    for(int i = 0; i < onTime.size /sizeof(int); i++) {
//      onTime[i] = t;
//    }  
//  } else {
//    onTime[0] = t;
//    lastUsedIndex = 0;
//  }  
  onTime = t;
}
int Led::getOnTime() {
  return onTime;
}
    
void Led::setOffTime(int t) {
  offTime = t;
}
int Led::getOffTime() {
  return offTime;
}

int Led::getDelayTime() {
  return delayTime;
}
