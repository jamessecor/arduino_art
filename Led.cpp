#include "Led.h"

Led::Led(int ledPin) {
  this->pin = ledPin;
  init();
  this->state = LOW;
}

void Led::init() {
	pinMode(pin, OUTPUT);
	off();
}

void Led::off() {
	digitalWrite(pin, LOW);
  state = LOW;
}

void Led::on() {
	digitalWrite(pin, HIGH);
  state = HIGH;
}

int Led::getPin() {
  return pin;
}

int Led::getState() {
  return state;
}
