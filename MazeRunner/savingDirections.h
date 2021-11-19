#include "IRreading.h"
#pragma once

int start = 0;

void intersectionDetector() {
	availableDir();
	//switchL = 0;

	if (turnL != 1 && switchL == 1) {
		Serial.println("L");
		switchL = 0;
	}
	if (turnR != 1 && switchR == 1) {
		Serial.println("R");
		switchR = 0;
	}
	if (turnB != 1 && switchB == 1) {
		Serial.println("B");
		switchB = 0;
	}
	if (turnS != 1 && switchS == 1) {
		Serial.println("S");
		switchS = 0;
	}

	turnL = 0;
	turnR = 0;
	turnB = 0;
	turnS = 0;
}