#include "directionControl.h"
#pragma once

int Av = 1;
int notAv = 0;

int leftDir = 0;
int straightDir = 0;
int rightDir = 0;
int backDir = 0;

int indicator = 0;

void availableDir() {
	int L_line = digitalRead(IR_L);
	int R_line = digitalRead(IR_R);
	int C_line = digitalRead(IR_C);

	int CL_read = digitalRead(IR_CL);
	int CR_read = digitalRead(IR_CR);

	if (L_line == A && C_line == A) {
		leftDir = Av;

		rightDir = notAv;
		straightDir = notAv;
		backDir = notAv;

		/*Serial.print("leftDir= ");
		Serial.println(leftDir);*/
		indicator = 1;
	}
	else if (C_line == A || CL_read == A || CR_read == A) {
		straightDir = Av;

		leftDir = notAv;
		rightDir = notAv;
		backDir = notAv;

		/*Serial.print("straightDir= ");
		Serial.println(straightDir);*/
		indicator = 0;
	}
	else if (R_line == A && C_line == A) {
		rightDir = Av;

		leftDir = notAv;
		straightDir = notAv;
		backDir = notAv;

		/*Serial.print("rightDir= ");
		Serial.println(rightDir);*/
		indicator = 1;
	}
	else if (CR_read == NA && CL_read == NA && R_line == NA && L_line == NA && C_line == NA) {
		backDir = Av;

		leftDir = notAv;
		rightDir = notAv;
		straightDir = notAv;

		/*Serial.print("backDir= ");
		Serial.println(backDir);*/
		indicator = 1;
	}
	
	/*Serial.print("leftDir= ");
	Serial.println(leftDir);
	Serial.print("straightDir= ");
	Serial.println(straightDir);
	Serial.print("rightDir= ");
	Serial.println(rightDir);
	Serial.print("backDir= ");
	Serial.println(backDir);*/
	digitalWrite(13, indicator);
}

