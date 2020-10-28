#include <Arduino.h>

class Button {
  private:
    int pin;
  	int state;
  	int lastReading;
    int updated_at;
    const static int PRESSES = 10;
    unsigned long onTime[PRESSES] = {};
    unsigned long offTime[PRESSES] = {};
    unsigned long delayTime = (unsigned long) 5000;
    
  	unsigned long lastDebounceTime = 0;
    unsigned long debounceDelay = 15;
  public:
    Button(int buttonPin);
  	void init();
    int getPin();
    void update();
    void setUpdatedAt(unsigned long updateTime);
    unsigned long getUpdatedAt();
    int getState();
    int getLastReading();
    bool isPressed();

    int getPresses();
    void clearUsedTimes(unsigned long m);
    void setOnTime(unsigned long newOnTime);
    void setOffTime(unsigned long newOffTime);
    unsigned long getOnTime(int index);
    unsigned long getOffTime(int index);
    unsigned long getDelayTime();
};
