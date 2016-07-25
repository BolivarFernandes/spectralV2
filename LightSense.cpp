#include "LightSense.h"
#include "Arduino.h"

LightSense::LightSense(int pinInput) {
	_pinInput = pinInput;
}

float LightSense::Get() {
	return 1 - (analogRead(_pinInput) / 1023); 
}