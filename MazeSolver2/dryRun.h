#include "direction.h"
#pragma once
void dryRun() {
    int L_line = digitalRead(IR_L);
    int R_line = digitalRead(IR_R);

    int CL_read = digitalRead(IR_CL);
    int CR_read = digitalRead(IR_CR);
    int C_read = digitalRead(IR_C);


    if (L_line == A) {
        turnLeft();
        //delay(200);
        //stopMoving();
        //indicator = 1;
        //intDec = 'l';
        //Serial.println(switchX);

    }
    else if (CL_read == A || CR_read == A || C_read == A) {
        //Serial.println("Straight available");
        followLine();
        //intDec = 's';
        //indicator = 0;
    }
    else if (R_line == A) {
        turnRight();
        delay(200);
        stopMoving();
        //intDec = 'r';
        //indicator = 1;
    }
    else if (CR_read == NA && CL_read == NA && R_line == NA && L_line == NA && C_read == NA) {
        uTurn(); //u-turn
        //stopMoving(); 
        //intDec = 'b';
        //indicator = 1;
    }
    /*else{
      indicator = 0;
    }*/
    //digitalWrite(LED, indicator);
    //intersectionDetector();
    //Serial.println(intDec);

}