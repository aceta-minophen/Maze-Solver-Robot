#pragma once

// Motor Driver
int motorLpin1 = 2;
int motorLpin2 = 3;
int motorRpin1 = 4;
int motorRpin2 = 5;

int speedL = 9;
int speedR = 10;

int A = 0;
int NA = 1;

int speedX = 55;
int switchX = 0;

int switchR = 0;
int switchL = 0;

char intDec;

// IR Sensors
int IR_L = 6; //Left
int IR_CL = 7; //Centre left
int IR_C = 8; //Centre
int IR_CR = 11; //Centre right
int IR_R = 12; //Right

//Indicators
int LED = 13;
int indicator = 0;

int turnR = 0;
int turnL = 0;
int turnB = 0;

void turnRight() {
    analogWrite(speedR, 0);
    analogWrite(speedL, 57);
    Serial.print("Turning right: ");
    turnR = 1;
    Serial.println(turnR);
    switchR = 1;
    turnL = 0;
}

void turnLeft() {
    analogWrite(speedR, 52);
    analogWrite(speedL, 0);
    Serial.print("Turning Left: ");
    turnL = 1;
    Serial.println(turnL);
    switchL = 1;
    //Serial.println(switchX);
    turnR = 0;
}

void headStraight() {
    analogWrite(speedR, 50);
    analogWrite(speedL, 57);
    //Serial.println("Heading Straight");
    //turnL = 0;
}

void stopMoving() {
    analogWrite(speedR, 0);
    analogWrite(speedL, 0);
    Serial.println("Stopped moving");
    turnL = 0;
    turnR = 0;
}

void followLine() {
    int CL_read = digitalRead(IR_CL);
    int CR_read = digitalRead(IR_CR);
    int C_read = digitalRead(IR_C);


    if (C_read == A) {
        headStraight();
        //analogWrite(speedR, 50);
        //analogWrite(speedL, 50);
    }
    else if (CL_read == A && CR_read == NA && C_read == NA) {
        turnLeft();
        //analogWrite(speedR, 55);
        //analogWrite(speedL, 45);
    }
    else if (CL_read == NA && CR_read == A && C_read == NA) {
        turnRight();
        //analogWrite(speedL, 55);
        //analogWrite(speedR, 45);
    }
    Serial.println("Heading Straight");
    turnL = 0;
    turnR = 0;
}

void uTurn() {
    analogWrite(speedL, 57);
    analogWrite(speedR, 0);
    Serial.print("U turn: ");
    turnB = 1;
    Serial.println(turnB);
    turnL = 0;
    turnR = 0;
}