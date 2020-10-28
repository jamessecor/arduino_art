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
