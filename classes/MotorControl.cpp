#include "Arduino.h"
#include "MotorControl.h"

MotorControl::MotorControl(int pinChannelA, int pinChannelB) {
	_pinChannelA = pinChannelA; // Move to private variable
	_pinChannelB = pinChannelB; // ''

	pinMode(_pinChannelA, OUTPUT); // Set pin mode to output
	pinMode(_pinChannelB, OUTPUT); // ''
}

void MotorControl::Set(float value) {
	_value = value;
	// Set pin pwm output
	if (value >= 0) {
    	analogWrite(_pinChannelA, value * 255);
    	digitalWrite(_pinChannelB, LOW);
  	}
  	else {
    	analogWrite(_pinChannelA, LOW);
    	digitalWrite(_pinChannelB, fabs(value) * 255); // Absolute speed, no negatives!
  	}
}

float MotorControl::Get() {
	return _value;
}