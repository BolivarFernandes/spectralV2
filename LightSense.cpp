#include "LightSense.h"
#include "Arduino.h"

float fmap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

LightSense::LightSense(int pinInput) {
	_pinInput = pinInput;
}

float LightSense::Get() {
	return  fmap(analogRead(_pinInput), 1023, 0, 0, 1);
}

