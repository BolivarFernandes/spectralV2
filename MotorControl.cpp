#include "MotorControl.h"
#include "Arduino.h"

MotorControl::MotorControl(int pinA, int pinB) {
	_pinA = pinA; // Move to private variable
	_pinB = pinB; // ''

	pinMode(_pinA, OUTPUT); // Set pin mode to output
	pinMode(_pinB, OUTPUT); // ''
}

MotorControl::~MotorControl() {
	digitalWrite(_pinA, LOW);
	digitalWrite(_pinB, LOW);
}

void MotorControl::Set(float value) {
	_value = value;
	// Set pin pwm output
	if (value > 0) {
    	analogWrite(_pinA, value * 255);
    	digitalWrite(_pinB, HIGH);
  	}
  	else if (value < 0) {
    	analogWrite(_pinA, HIGH);
    	digitalWrite(_pinB, fabs(value) * 255); // Absolute speed, no negatives!
  	}
  	else {
  		digitalWrite(_pinA, LOW);
  		digitalWrite(_pinB, LOW);
  	}
}

float MotorControl::Get() {
	return _value;
}