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

    // Initialize system
    void init() {

        sensor->init();

        redLed->init();
        yellowLed->init();
        greenLed->init();
    }

    // Update system state
    void update() {

        float distance = sensor->readDistance();

        if (distance < 0) {
            return;
        }

        lastDistance = distance;

        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.println(" cm");

        // Turn off all LEDs first
        redLed->off();
        yellowLed->off();
        greenLed->off();

        if (distance < DIST_NEAR) {
            Serial.println("RED LED");

            redLed->toggle();
            delay(200);
        }
        else if (distance >= DIST_NEAR && distance < DIST_MEDIUM) {

            Serial.println("YELLOW LED");

            yellowLed->toggle();
            delay(400);

        }
        else {

            Serial.println("GREEN LED");

            greenLed->toggle();
            delay(700);
        }
    }

    float getLastDistance() {
        return lastDistance;
    }
};

#endif