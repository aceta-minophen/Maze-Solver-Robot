#include "IRreading.h"
#pragma once


int start = 0;

void intersectionDetector() {
	availableDir();
	char intDet;

	if (turnL != 1 && switchL == 1) {
		//Serial.println("L");
		intDet = 'l';
		Serial.println(intDet);
		switchL = 0;
	}
	if (turnS != 1 && switchS == 1 && turnL != 1 && switchL == 1) {
		//Serial.println("S");
		intDet = 's';
		Serial.println(intDet); 
		switchS = 0;
	}
	/*if (turnR != 1 && indicator == 1 && switchS == 1) {
		//Serial.println("S");
		intDet = 's';
		Serial.println(intDet); WHAT DO I DOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
		switchS = 0;
	}*/
	while(indicator==0){
		if(turnR != 1 && switchR == 1){
			intDet = 's';
			Serial.println(intDet);
			switchR = 0;
		}
	}
	else if (turnR != 1 && switchR == 1) {
		//Serial.println("B");
		intDet = 'r';
		Serial.println(intDet);
		switchR = 0;
	}
	else if (turnB != 1 && switchB == 1) {
		//Serial.println("B");
		intDet = 'b';
		Serial.println(intDet);
		switchB = 0;
	}


	turnL = 0;
	turnR = 0;
	turnB = 0;
	turnS = 0;
}
