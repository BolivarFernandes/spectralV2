#ifndef GYROSENSE_H
#define GYROSENSE_H

#include "Arduino.h"

class GyroSense {
public:
	GyroSense(int pinAnalog);
	int GetAngle();
	void Update();
	void SetVoltage(float value);
	void SetZeroVoltage(float value);
	void SetSensitivity(float value);
	void SetRotationThreshold(float value);
private:
	long _currentTime;
	long _previousTime;
	long _timeDifference;
	int _pinAnalog;					// Analog pin
	int _currentAngle;				// Current Angle
	float _votage = 5.0;				// Volatage
	float _zeroVoltage = 2.49;   	// Gyro is zeroed at 2.5V
	float _sensitivity = 0.007;  	// mV/deg/seck (0.007 = 7mV)
	float _rotationThreshold = 3;   // Minimum deg/sec to keep track of - helps with gyro drifting
};

#endif /* GYROSENSE_H */