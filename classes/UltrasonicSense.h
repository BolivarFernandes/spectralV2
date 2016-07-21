#ifndef ULTRASONICSENSE_H
#define ULTRASONICSENSE_H

class UltrasonicSense {
public:
	UltrasonicSense(int pinTrig, int pinEcho);
	~UltrasonicSense();
	int getCM();
	int getMM();
	int getRaw();
private:
	int _pinTrig;
	int _pinEcho;
};

#endif