#include "classes/MotorControl.h"

MotorControl ExampleMotor(8, 9);

void setup() {
	Serial.begin(9600);
	ExampleMotor.Set(0.5);
}

void loop() {
	Serial.println(ExampleMotor.Get());
}
