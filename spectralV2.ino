#include "MotorControl.h"
#include "LightSense.h"
#include "UltrasonicSense.h"
//#include "classes/GyroSense.h"
//#include "classes/EncoderSense.h"

MotorControl MotorLeft(5, 4);
MotorControl MotorRight(7, 6);
MotorControl MotorLift(8, 9);
MotorControl MotorGrab(10, 11);
MotorControl MotorRotate(2, 3);
LightSense LightLeft(A8);
LightSense LightRight(A10);
UltrasonicSense SonicMain(A9);

enum progState_t {STANDBY, BEGIN, LINEFOLLOW, WATERTOWER, CHEMSPILL, NUM_MODES}; // NUM_MODES is always last.
enum taskState_t {START, RUNNING, FINISHED};

progState_t robotState = STANDBY; // Default Mode

taskState_t WaterTowerState = START;
taskState_t ChemSpillState = START;

// Time
long initTime;
long currTime;

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
}

void Begin() {
}

void LineFollow() {
}

void WaterTower() {
	if (WaterTowerState == START) {
		initalTime = millis();
	}

	// Note: conditions must be in order of last to first.
	switch(initalTime - currTime) {
		case > 100: 
			MotorLeft.Set(0.0);
			MotorRight.Set(0.0);
		case > 50:
	}
}

void ChemSpill() {

}
