#include "EncoderSense.h"
#include "Arduino.h"

EncoderSense::EncoderSense(int pinA, int pinB) {
	_pinA = pinA;
	_pinB = pinB;

	Enable(); // Attach Interrupt
}

EncoderSense::~EncoderSense() {
	Disable();
}

int EncoderSense::GetDegrees() {
	return _value;
}

bool EncoderSense::GetDirection() {
	return _direction;
}

void Enable() {
	attachInterrupt(digitalPinToInterrupt(_pinA), EncoderSense::Update(), FALLING);
}

void Disable() {
	detachInterrupt(digitalPinToInterrupt(_pinA));
}

void Update() {
	if (digitalRead(_pinA) == digitalRead(_pinB)) {
		_direction = true; // Forward
	}
	else {
		_direction = false; // Backwards
	}

	if (lastValue != digitalRead(_pinA)) {
		if (_direction) _value++ else _value--; // Increment
	}
}
