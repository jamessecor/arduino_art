#include <Arduino.h>

class Led {
  private:
    int pin;
    int state;
  public:
    Led(int ledPin);
  	
  	void init();
  	
  	void off();
  	void on();
    
    int getState();
    int getPin();
};
