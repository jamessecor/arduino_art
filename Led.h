#include <Arduino.h>

class Led {
  private:
    int pin;
  public:
    Led(int ledPin);
  	void init();
  	void off();
  	void on();
    int getPin();
};
