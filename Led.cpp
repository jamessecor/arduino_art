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

void Led::setOnTime(unsigned long t) {
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
unsigned long Led::getOnTime() {
  return onTime;
}
    
void Led::setOffTime(unsigned long t) {
  offTime = t;
}
unsigned long Led::getOffTime() {
  return offTime;
}

unsigned long Led::getDelayTime() {
  return delayTime;
}
