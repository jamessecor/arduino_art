#include <Arduino.h>

class Led {
  private:
    int pin;
//    int onTime[100] = {};
//    int offTime[100] = {};
    unsigned long onTime = 0;
    unsigned long offTime = 0;
    int lastUsedIndex = -1;
    unsigned long delayTime = (unsigned long) 1400;
  public:
    Led(int ledPin);
  	
  	void init();
  	
  	void off();
  	void on();
    
    int getPin();
    
    void setOnTime(unsigned long onTime);
    unsigned long getOnTime();
    void setOffTime(unsigned long offTime);
    unsigned long getOffTime();
    unsigned long getDelayTime();
};
