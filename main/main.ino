#include "Led.h"
#include "UltrasonicSensor.h"
#include "DistanceController.h"

UltrasonicSensor sensor(26, 27);

Led redLed(5);
Led yellowLed(17);
Led greenLed(16);

DistanceController controller(&sensor, &redLed, &yellowLed, &greenLed);

void setup() {

    Serial.begin(9600);

    controller.init();

    Serial.println("System initialized");
}

void loop() {

    controller.update();

}