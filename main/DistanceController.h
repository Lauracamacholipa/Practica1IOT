#ifndef DISTANCE_CONTROLLER_H
#define DISTANCE_CONTROLLER_H

const int DIST_NEAR = 30;
const int DIST_MEDIUM = 100;

#include <Arduino.h>
#include "Led.h"
#include "UltrasonicSensor.h"

class DistanceController {

private:

    UltrasonicSensor* sensor;

    Led* redLed;
    Led* yellowLed;
    Led* greenLed;

    float lastDistance;

public:

    // Print measured distance to serial monitor
    void logDistance(float distance) {
        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.println(" cm");
    }

    // Blink selected LED and disable the others
    void blinkLed(Led* activeLed, Led* ledOff1, Led* ledOff2, int delayTime, const char* label) {

        ledOff1->off();
        ledOff2->off();

        Serial.println(label);

        activeLed->toggle();
        delay(delayTime);
    }

    // Select LED behavior based on measured distance
    void updateLeds(float distance) {

        if (distance < DIST_NEAR) {
            blinkLed(redLed, yellowLed, greenLed, 200, "RED LED");
        }
        else if (distance < DIST_MEDIUM) {
            blinkLed(yellowLed, redLed, greenLed, 400, "YELLOW LED");
        }
        else {
            blinkLed(greenLed, redLed, yellowLed, 700, "GREEN LED");
        }
    }

    // Constructor
    DistanceController(UltrasonicSensor* sensor,
                       Led* red,
                       Led* yellow,
                       Led* green) {

        this->sensor = sensor;
        this->redLed = red;
        this->yellowLed = yellow;
        this->greenLed = green;

        lastDistance = 0;
    }

    // Initialize sensor and LED hardware
    void init() {

        sensor->init();

        redLed->init();
        yellowLed->init();
        greenLed->init();
    }

    // Main controller update cycle
    void update() {

        float distance = sensor->readDistance();

        if (distance < 0) {
            return;
        }

        lastDistance = distance;

        logDistance(distance);

        updateLeds(distance);
    }

    // Return last measured distance
    float getLastDistance() {
        return lastDistance;
    }
};

#endif