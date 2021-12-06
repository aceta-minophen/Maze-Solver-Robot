#include "dryRun.h"

//Storing map
char maze[100], turnDirection;
int i;

void setup() {
    Serial.begin(9600);

    pinMode(motorLpin1, OUTPUT);
    pinMode(motorLpin2, OUTPUT);
    pinMode(motorRpin1, OUTPUT);
    pinMode(motorRpin2, OUTPUT);

    pinMode(speedL, OUTPUT);
    pinMode(speedR, OUTPUT);

    //IR sensors
    pinMode(IR_L, INPUT);
    pinMode(IR_CL, INPUT);
    pinMode(IR_CR, INPUT);
    pinMode(IR_R, INPUT);
    pinMode(IR_C, INPUT);

    //analogWrite(speedR,0);
    //analogWrite(speedL, 80);

    //anticlockwise
    digitalWrite(motorLpin1, LOW); //left
    digitalWrite(motorLpin2, HIGH); // left
    digitalWrite(motorRpin1, HIGH); //right
    digitalWrite(motorRpin2, LOW); //right

    //Indicators
    pinMode(LED, OUTPUT);
    //digitalWrite(LED, LOW);
}


/*void intersectionDetector() {
    int L_line = digitalRead(IR_L);
    int R_line = digitalRead(IR_R);

    int CL_read = digitalRead(IR_CL);
    int CR_read = digitalRead(IR_CR);
    int C_read = digitalRead(IR_C);

    if (CL_read == A || CR_read == A || C_read == A) {
        indicator = 0;
    }
    if (R_line == A && CR_read == A && C_read == A) {
        indicator = 1;
    }
    if (CR_read == NA && CL_read == NA && R_line == NA && L_line == NA && C_read == NA) {
        indicator = 1;
    }
    if (L_line == A && CL_read == A && C_read == A) {
        indicator = 1;
    }
    digitalWrite(LED, indicator);
    /*if(turnL!=1 && switchX == 1){
      intDec = 'l';
      switchX = 0;
      Serial.println("A");
    }*/
    //Serial.println(intDec);
//}

/*void dryRun() {
    int L_line = digitalRead(IR_L);
    int R_line = digitalRead(IR_R);

    int CL_read = digitalRead(IR_CL);
    int CR_read = digitalRead(IR_CR);
    int C_read = digitalRead(IR_C);

    //followLine();

    if (L_line == A && CL_read == A && C_read == A) {
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
    else if (R_line == A && CR_read == A && C_read == A) {
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

//}

void turning() {
    if (turnR != 1 && switchX == 1) {
        intDec = 'r';
        Serial.println("R");
        switchR = 0;
    }
    /*else if(turnL!=1 && switchX == 1){
      intDec = 'l';
      Serial.println("L");
      switchL = 0;
    }
    //Serial.println(intDec);*/
}

void loop() {
    dryRun();
    //turning();
    if (turnR != 1 && switchR == 1) {
        intDec = 'r';
        Serial.println("R");
        switchR = 0;
    }
}