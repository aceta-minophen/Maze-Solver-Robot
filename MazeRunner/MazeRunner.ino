/*
 Name:		MazeRunner.ino
 Created:	11/15/2021 11:35:36 AM
 Author:	suk
*/
#include "IRreading.h"
#include "directionControl.h"
//#include "dryRun.h"


/*Indicators*/
int LED = 13;
int indicator = 0;



void setup() {
	Serial.begin(9600);


	/*Motor Driver*/
	pinMode(motorLpin1, OUTPUT);
	pinMode(motorLpin2, OUTPUT);
	pinMode(motorRpin1, OUTPUT);
	pinMode(motorRpin2, OUTPUT);

	pinMode(speedL, OUTPUT);
	pinMode(speedR, OUTPUT);

	//anticlockwise
	digitalWrite(motorLpin1, LOW); //left
	digitalWrite(motorLpin2, HIGH); // left
	digitalWrite(motorRpin1, HIGH); //right
	digitalWrite(motorRpin2, LOW); //right


	/*IR sensors*/
	pinMode(IR_L, INPUT);
	pinMode(IR_CL, INPUT);
	pinMode(IR_CR, INPUT);
	pinMode(IR_R, INPUT);
	pinMode(IR_C, INPUT);


	/*Indicators*/
	pinMode(LED, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	//dryRun();

	//availableDir();
	/*if (leftDir == Av) {
		turnLeft();
	}
	else if (straightDir == Av) {
		followLine();
	}
	else if (rightDir == Av) {
		turnRight();
	}
	else if (backDir == Av) {
		uTurn();
	}*/

	if (L_line == A) {
		turnLeft();
	}
	else if (C_line == A || CL_read == A || CR_read == A) {
		followLine();
	}
	else if (R_line == A) {
		turnRight();
	}
	else if (CR_read == NA && CL_read == NA && R_line == NA && L_line == NA && C_line == NA) {
		uTurn();
	}
}
