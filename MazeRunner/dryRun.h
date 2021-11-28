#include "IRreading.h"
#include "savingDirections.h"
#pragma once


void dryRun() {
	availableDir();

	if (leftDir == Av) {
		turnLeft();
	}
	else if (straightDir == Av) {
		followLine();
	}
	else if (rightDir == Av) {
		turnRight();
	}
	else if (backDir == Av) {
		stopMoving();
	}

	intersectionDetector();

	/*for (int i = 0; i < 50; i++) {
		mazeMap[count] = intDet;
		Serial.print("'");
		Serial.print(mazeMap[count]);
		Serial.print("'");
		Serial.print(", ");
	}*/
}