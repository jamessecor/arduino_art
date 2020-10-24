#include <Arduino.h>

class Button {
  private:
    int pin;
  	int state;
  	int lastReading;
  	int lastDebounceTime = 0;
    int debounceDelay = 50;
  public:
    Button(int buttonPin);
  	void init();
  	void off();
  	void on();
    void update();
    int getState();
    bool isPressed();
};
