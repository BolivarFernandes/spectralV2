#include "UltrasonicSense.h"
#include "Arduino.h"
UltrasonicSense::UltrasonicSense(int pinTrig, int pinEcho) {
	_pinTrig = pinTrig;
	_pinEcho = pinEcho;
}

UltrasonicSense::~UltrasonicSense() {}

int UltrasonicSense::getCM() {
	return getRaw() / 58;
}

int UltrasonicSense::getMM() {
	return getRaw() / 5.8;
}

int UltrasonicSense::getRaw() {
	digitalWrite(_pinTrig, LOW);			// Set the trigger pingPin to low for 2uS
	delayMicroseconds(2);
	digitalWrite(_pinTrig, HIGH);			// Send a 10uS high to trigger ranging
	delayMicroseconds(10);
	digitalWrite(_pinTrig, LOW);			// Send pingPin low again
	int pulse = pulseIn(_pinEcho, HIGH);	// Read Pulse
	return pulse;							// Return Pulse Length
}