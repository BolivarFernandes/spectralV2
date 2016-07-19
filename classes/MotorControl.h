#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

class MotorControl {
public:
	MotorControl(int pinA, int pinB);
	~MotorControl();
	void Set(float value);
	float Get();
private:
	int _pinA;
	int _pinB;
	float _value;
};

#endif /* MOTORCONTROL_H */