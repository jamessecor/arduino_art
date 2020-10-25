#include <Arduino.h>

class Button {
  private:
    int pin;
  	int state;
  	int lastReading;
  	unsigned long lastDebounceTime = 0;
    unsigned long debounceDelay = 50;
    unsigned long lastStart = 0;
    unsigned long lastEnd = 0;
    unsigned long duration = 0;
  public:
    Button(int buttonPin);
  	void init();
    int getPin();
  	void off();
  	void on();
    void update();
    int getState();
    int getLastReading();
    void setLastStart(unsigned long start);
    unsigned long getLastStart();
    void setLastEnd(unsigned long endTime);
    unsigned long getLastEnd();
    void setDuration(unsigned long dur);
    unsigned long getDuration();
    bool isPressed();
};
