#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

class MotorControl {
public:
	MotorControl(int pinChannelA, int pinChannelB);
	void Set(float value);
	float Get();
private:
	int _pinChannelA;
	int _pinChannelB;
	float _value;
};

#endif /* MOTORCONTROL_H */