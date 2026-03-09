#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include <Arduino.h>

class UltrasonicSensor {

private:
    int triggerPin;
    int echoPin;
    bool isInitialized;
    float lastDistance;

public:

    // Constructor
    UltrasonicSensor(int trig, int echo) {
        triggerPin = trig;
        echoPin = echo;
        isInitialized = false;
        lastDistance = 0.0;
    }

    // Initialize sensor
    void init() {
        pinMode(triggerPin, OUTPUT);
        pinMode(echoPin, INPUT);
        isInitialized = true;
    }

    // Read distance from sensor
    float readDistance() {

        if (!isInitialized) {
            return -1; // sensor not initialized
        }

        digitalWrite(triggerPin, LOW);
        delayMicroseconds(2);

        digitalWrite(triggerPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(triggerPin, LOW);

        long duration = pulseIn(echoPin, HIGH, 30000);

        float distance = duration * 0.034 / 2;

        lastDistance = distance;

        return distance;
    }

    // Filter distance using averaged sensor readings
    float readDistanceFiltered() {

        const int samples = 5;
        float sum = 0;

        for(int i = 0; i < samples; i++) {
            sum += readDistance();
            delay(10);
        }

        return sum / samples;
    }

    // Get last measured distance
    float getLastDistance() {
        return lastDistance;
    }
};

#endif