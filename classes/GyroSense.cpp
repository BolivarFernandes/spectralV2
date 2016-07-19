#include "Arduino.h"
#include "GyroSense.h"

GyroSense::GyroSense(int pinAnalog) {
	_pinAnalog = pinAnalog;
}

void GyroSense::Update() {
	_currentTime = millis();

	_timeDifference = _currentTime - _previousTime;

	if (_timeDifference > 10) {
		//This line converts the 0-1023 signal to 0-5V
		float gyroRate = (analogRead(_pinAnalog) * _voltage) / 1023;

		//This line finds the voltage offset from sitting still
		gyroRate -= _zeroVoltge;

		//This line divides the voltage we found by the gyro's sensitivity
		gyroRate /= _sensitivity;

		//Ignore the gyro if our angular velocity does not meet our threshold
		if (gyroRate >= _rotationThreshold or gyroRate <= -_rotationThreshold) {
		//This line divides the value by 100 since we are running in a 10ms loop (1000ms/10ms)
		gyroRate /= 1000 / _timeDifference;
		_currentAngle += gyroRate;
		}

		//Keep our angle between 0-359 degrees
		if (_currentAngle < 0)
		_currentAngle += 360;
		else if (_currentAngle > 359)
		_currentAngle -= 360;

		_previousTime = _currentTime; // Get ready for next update
	}
}

int GyroSense::GetAngle() {
	return _currentAngle;
}

void GyroSense::SetVoltage(float value) {
	_voltage = value;
}

void GyroSense::SetZeroVoltage(float value) {
	_zeroVoltge = value;
}

void GyroSense::SetSensitivity(float value) {
	_sensitivity = value;
}

void GyroSense::SetRotationThreshold(float value) {
	_rotationThreshold = value;
}