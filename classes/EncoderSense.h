#ifndef ENCODERSENSE_H
#define ENCODERSENSE_H

class EncoderSense {
public:
	EncoderSense(int pinA, int pinB);
	~EncoderSense();
	int GetDegrees();
	bool GetDirection();
	void Enable();
	void Disable();
	void Reset();
private:
	void Update();
	int _pinA;
	int _pinB;
	int _value;
	bool _lastValue;
};


#endif /* ENCOERSENSE_H */