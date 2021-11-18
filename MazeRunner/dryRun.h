#include "IRreading.h"

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
		uTurn();
	}
}