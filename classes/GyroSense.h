#ifndef GYROSENSE_H
#define GYROSENSE_H

class GyroSense {
public:
	GyroSense(int pinAnalog);
	int GetAngle();
	void Update();
	void SetVoltage(float value);
	void SetZeroVoltage(float value);
	void SetSensitivity(float value);
	void SetRotationThreshhold(float value);
private:
	int _currentTime;
	int _previousTime;
	int _pinAnalog;					// Analog pin
	int _currentAngle;				// Current Angle
	float _votage = 5;				// Volatage
	float _zeroVoltage = 2.49;   	// Gyro is zeroed at 2.5V
	float _sensitivity = 0.007;  	// mV/deg/seck (0.007 = 7mV)
	float _rotationThreshold = 3;   // Minimum deg/sec to keep track of - helps with gyro drifting
};

#endif /* GYROSENSE_H */