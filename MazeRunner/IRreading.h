#include "directionControl.h"
#pragma once

int Av = 1;
int notAv = 0;

int leftDir = 0;
int straightDir = 0;
int rightDir = 0;
int backDir = 0;


void availableDir() {
	int L_line = digitalRead(IR_L);
	int R_line = digitalRead(IR_R);
	int C_line = digitalRead(IR_C);

	int CL_read = digitalRead(IR_CL);
	int CR_read = digitalRead(IR_CR);

	if (L_line == A) {
		//turnLeft();
		leftDir = Av;

		rightDir == notAv;
		straightDir == notAv;
		backDir == notAv;

		Serial.print("leftDir= ");
		Serial.println(leftDir);
	}
	else if (C_line == A || CL_read == A || CR_read == A) {
		//followLine();


		straightDir = Av;

		leftDir == notAv;
		rightDir == notAv;
		backDir == notAv;

		Serial.print("straightDir= ");
		Serial.println(straightDir);
	}
	else if (R_line == A) {
		//turnRight();


		rightDir = Av;

		leftDir == notAv;
		straightDir == notAv;
		backDir == notAv;

		Serial.print("rightDir= ");
		Serial.println(rightDir);
	}
	else if (CR_read == NA && CL_read == NA && R_line == NA && L_line == NA && C_line == NA) {
		//uTurn();

		
		backDir = Av;

		leftDir == notAv;
		rightDir == notAv;
		straightDir == notAv;

		Serial.print("backDir= ");
		Serial.println(backDir);
	}

	
	
}

