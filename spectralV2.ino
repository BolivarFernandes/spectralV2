#include "MotorControl.h"
#include "LightSense.h"
#include "UltrasonicSense.h"
//#include "classes/GyroSense.h"
//#include "classes/EncoderSense.h"

MotorControl MotorLeft(5, 4);
MotorControl MotorRight(7, 6);
LightSense LightLeft(A8);
LightSense LightRight(A10);
UltrasonicSense SonicMain(A9);

enum progState_t {STANDBY, BEGIN, LINEFOLLOW, WATERTOWER, CHEMSPILL, NUM_MODES}; // NUM_MODES is always last.

progState_t robotState = STANDBY; // Default Mode

void setup() {
	Serial.begin(9600);
}

void loop() {
	//Gyro.Update();
	//

	switch(robotState) {
		case STANDBY: 		Standby();
		case BEGIN: 		Begin();
		case LINEFOLLOW: 	LineFollow();
		case WATERTOWER: 	WaterTower();
		case CHEMSPILL:	 	ChemSpill();
		default: 			Standby();
	}
}

void Standby() {

}

void Begin() {

}

void LineFollow() {

}

void WaterTower() {

}

void ChemSpill() {

}
