#include "EncoderSense.h"

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

void EncoderSense::Enable() {
	attachInterrupt(digitalPinToInterrupt(_pinA), isr_update, FALLING);
}

void EncoderSense::Disable() {
	detachInterrupt(digitalPinToInterrupt(_pinA));
}


