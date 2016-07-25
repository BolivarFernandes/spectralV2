#ifndef LIGHTSENSE_H
#define LIGHTSENSE_H

class LightSense {
public:
	LightSense(int pinInput);
	float Get();
private:
	int _pinInput;
};

#endif /* LIGHTSENSE_H */