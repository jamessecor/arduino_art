#include <Arduino.h>

class Button {
  private:
    int pin;
  	int state;
  	int lastReading;
  	int lastDebounceTime = 0;
    int debounceDelay = 50;
    int lastStart = 0;
    int lastEnd = 0;
    int duration = 0;
  public:
    Button(int buttonPin);
  	void init();
    int getPin();
  	void off();
  	void on();
    void update();
    int getState();
    int getLastReading();
    void setLastStart(int start);
    int getLastStart();
    void setLastEnd(int endTime);
    int getLastEnd();
    void setDuration(int dur);
    int getDuration();
    bool isPressed();
};
