#include <Arduino.h>

class Led {
  private:
    int pin;
//    int onTime[100] = {};
//    int offTime[100] = {};
    int onTime = 0;
    int offTime = 0;
    int lastUsedIndex = -1;
    int delayTime = 1400;
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
    int getDelayTime();
};
