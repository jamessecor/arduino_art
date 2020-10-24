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
