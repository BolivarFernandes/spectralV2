#include "MotorControl.h"
#include "LightSense.h"
#include "UltrasonicSense.h"
//#include "classes/GyroSense.h"
//#include "EncoderSense.h"

MotorControl MotorLeft(5, 4);
MotorControl MotorRight(7, 6);
//EncoderSense EncLeft(20, 21);
//EncoderSense EncRight(22, 23);
MotorControl MotorLift(8, 9);
MotorControl MotorGrab(10, 11);
MotorControl MotorRotate(2, 3);
LightSense LightLeft(A8);
LightSense LightRight(A10);
UltrasonicSense SonicMain(A9, A9);


// Program and task state enumeration
enum progState_t {STANDBY, BEGIN, LINEFOLLOW, WATERTOWER, CHEMSPILL, NUM_MODES}; // NUM_MODES is always last.
enum taskState_t {START, RUNNING};

progState_t robotState = LINEFOLLOW; // Default Mode

taskState_t WaterTowerState = START;
taskState_t ChemSpillState = START;

// Step
int step;

// Time
long initTime;
long currTime;
long timeDiff;

void setup() {
	Serial.begin(9600);
}

void loop() {
	//Gyro.Update();
	currTime = millis();

	switch(robotState) {
		case STANDBY: 		Standby(); break;
		case BEGIN: 		Begin(); break;
		case LINEFOLLOW: 	LineFollow(); break;
		case WATERTOWER: 	WaterTower(); break;
		case CHEMSPILL:	 	ChemSpill(); break;
		default: 			Standby(); break;
	}
}

void Standby() {
	MotorLeft.Set(0);
	MotorRight.Set(0);
	MotorLift.Set(0);
	MotorGrab.Set(0);
	MotorRotate.Set(0);
	robotState = BEGIN;
}

void Begin() {
	robotState = LINEFOLLOW;
}

void LineFollow() {
	float speed = 0.4;
	float diff = (LightLeft.Get()) - (LightRight.Get());

	diff *= 4;

	MotorLeft.Set(speed + diff);
	MotorRight.Set(speed - diff);

}

void WaterTower() { /*
	if (WaterTowerState == START) {
		initTime = millis();
		step = 0;
		WaterTowerState = RUNNING;
	}

	int encMeanVal = (fabs(EncLeft.GetDegrees()) + fabs(EncRight.GetDegrees())) / 2; // Only use for straight movement.

	// Note: conditions must be in order of last to first.
	// Don't forget to break the statement.
	switch(step) {
		case 0:
			MotorLeft.Set(0);
			MotorRight.Set(0);
			(encMeanVal >= 360) ? nextStep(); : break;
		case 1: 	
			MotorLeft.Set(1);
			MotorRight.Set(1);
			(encMeanVal >= 360) ? nextStep(); : break;
	}*/
}

void ChemSpill() {

}

void nextStep() {/*
	EncLeft.Reset();
	EncRight.Reset();
	step++;*/
}
