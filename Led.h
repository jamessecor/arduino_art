#include <Arduino.h>

class Led {
  private:
    int pin;
    int onTime = 0;
    int offTime = 0;
  public:
    Led(int ledPin);
  	
  	void init();
  	
  	void off();
  	void on();
    
    int getPin();
    
    void setOnTime(int onTime);
    int getOnTime();
    void setOffTime(int offTime);
    int getOffTime();
};
