/*
#ifndef ENCODERSENSE_H
#define ENCODERSENSE_H

#include "Arduino.h"

class EncoderSense {
public:
  EncoderSense(int pinA, int pinB);
	~EncoderSense();
	int GetDegrees();
	bool GetDirection();
	void Enable();
	void Disable();
	void Reset();

  int readPinA(void) { return digitalRead(_pinA); }
  int readPinB(void) { return digitalRead(_pinB); }
  void setDirection(bool d) { _direction = d; }
  bool getDirection(void) { return _direction; }
  int  getLastValue(void) { return _lastValue; }

  void incValue(void) { ++_value; }
  void decValue(void) { --_value; }
  
private:
	//void Update(void);
	int _pinA;
	int _pinB;
	int _value;
	bool _lastValue;
  bool _direction;
};


EncoderSense es(8,9); // need to make an instance of the class to attach

//---------------------------------------------------------------
// function Update (to attach to an interrupt)

void isr_update() 
  {
  if (es.readPinA() == es.readPinB())
    es.setDirection(true); // Forward
  else 
    es.setDirection(false); // Backwards

  if (es.getLastValue() != es.readPinA()) 
    {
    if (es.getDirection()) 
      es.incValue(); 
    else 
      es.decValue(); // Increment
    }
  }

#endif /* ENCOERSENSE_H */
