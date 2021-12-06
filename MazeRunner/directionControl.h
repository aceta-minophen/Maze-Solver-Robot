//#include "IRreading.h"
#pragma once

/*Motor Driver*/
int motorLpin1 = 4;
int motorLpin2 = 5;
int motorRpin1 = 2;
int motorRpin2 = 3;

int speedL = 10;
int speedR = 9;

/*Reading IRs*/
//IR Sensors
int IR_L = 6; //Left
int IR_CL = 7; //Centre left
int IR_C = 8; //Centre
int IR_CR = 11; //Centre right
int IR_R = 12; //Right

int A = 0;
int NA = 1;

int turnR = 0;
int turnL = 0;
int turnB = 0;
int turnS = 0;

int switchL = 0;
int switchR = 0;
int switchB = 0;
int switchS = 0;


/*Turning Left*/
void turnLeft() {
	analogWrite(speedR, 50);
	analogWrite(speedL, 0);
	//Serial.print("Turning Left: ");
	turnL = 1;
	//Serial.println(turnL);
	switchL = 1;
}


/*Turning Right*/
void turnRight() {
	analogWrite(speedR, 0);
	analogWrite(speedL, 50);
	//Serial.print("Turning right: ");
	turnR = 1;
	//Serial.println(turnR);
	switchR = 1;
}


/*Nudging to not stray from path*/
void nudgeLeft() {
	analogWrite(speedR, 48);
	analogWrite(speedL, 30);
	//Serial.print("Nudging Left");
}

void nudgeRight() {
	analogWrite(speedR, 30);
	analogWrite(speedL, 48);
	//Serial.print("Nudging Right");
}

void headStraight() {
	analogWrite(speedR, 55);
	analogWrite(speedL, 55);
	//Serial.println("Heading Straight");
	turnS = 1;
	switchS = 1;
}

void followLine() {
	int CL_read = digitalRead(IR_CL);
	int CR_read = digitalRead(IR_CR);
	int C_read = digitalRead(IR_C);


	if (C_read == A) {
		headStraight();
	}
	else if (CL_read == A && CR_read == NA && C_read == NA) {
		turnLeft();
	}
	else if (CL_read == NA && CR_read == A && C_read == NA) {
		turnRight();
	}
}


/*Turning Back (u-turn)*/
void uTurn() {
	analogWrite(speedL, 50);
	analogWrite(speedR, 0);
	//Serial.print("U turn: ");
	turnB = 1;
	//Serial.println(turnB);
	switchB = 1;
}


/*Stop moving*/
void stopMoving() {
	analogWrite(speedR, 0);
	analogWrite(speedL, 0);
	//Serial.println("Stopped moving");
}