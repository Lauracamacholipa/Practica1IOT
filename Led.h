#include <Arduino.h>

class Led {
private:
    int pin;
    bool state;

public:
    // Constructor: receives the pin number where the LED is connected
    Led(int pin) {
        this->pin = pin;
        this->state = false;
    }

    // Initializes the pin as OUTPUT
    void init() {
        pinMode(pin, OUTPUT);
        state = false;
        digitalWrite(pin, LOW);
    }

    // Turns the LED on
    void on() {
        state = true;
        digitalWrite(pin, HIGH);
    }

    // Turns the LED off
    void off() {
        state = false;
        digitalWrite(pin, LOW);
    }

    // Toggles the LED state
    void toggle() {
        state = !state;
        digitalWrite(pin, state ? HIGH : LOW);
    }

    // Returns true if the LED is on
    bool isOn() {
        return state;
    }
};
