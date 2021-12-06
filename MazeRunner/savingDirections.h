#include "IRreading.h"
#pragma once


void intersectionDetector() {
	availableDir();

	if (turnL != 1 && switchL == 1) {
		intDet = 'l';
		//Serial.println(intDet);

		count = count + 1;
		//Serial.println(count);

		mazeMap[count] = intDet;
		Serial.print("'");
		Serial.print(mazeMap[count]);
		Serial.print("'");
		Serial.print(", ");
		switchL = 0;
	}
	if (turnS != 1 && switchS == 1 && turnL != 1 && switchL == 1) {
		//intDet = 's';
		//Serial.println(intDet);

		/*count = count + 1;
		//Serial.println(count);
		mazeMap[count] = intDet;
		Serial.print("'");
		Serial.print(mazeMap[count]);
		Serial.print("'");
		Serial.print(", ");*/
		switchS = 0;
	}
	else if (turnR != 1 && switchR == 1) {
		intDet = 'r';
		//Serial.println(intDet);

		count = count + 1;
		//Serial.println(count);
		mazeMap[count] = intDet;
		Serial.print("'");
		Serial.print(mazeMap[count]);
		Serial.print("'");
		Serial.print(", ");
		switchR = 0;
	}
	else if (turnB != 1 && switchB == 1) {
		intDet = 'b';
		//Serial.println(intDet);

		count = count + 1;
		//Serial.println(count);
		mazeMap[count] = intDet;
		Serial.print("'");
		Serial.print(mazeMap[count]);
		Serial.print("'");
		Serial.print(", ");
		switchB = 0;
	}
	

	turnL = 0;
	turnR = 0;
	turnB = 0;
	turnS = 0;

	/*Serial.print("'");
	Serial.print(mazeMap[count]);
	Serial.print("'");
	Serial.print(", ");*/
}