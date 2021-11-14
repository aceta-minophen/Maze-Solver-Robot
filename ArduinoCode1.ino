// Motor Driver
int motorLpin1 = 2;
int motorLpin2 = 3;
int motorRpin1 = 4;
int motorRpin2 = 5;

int speedL = 9;
int speedR = 10;

int A = 0;
int NA = 1;

int speedX =55;
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

void turnRight(){
  analogWrite(speedR, 0);
  analogWrite(speedL, 57);
  Serial.print("Turning right: ");
  turnR = 1;
  Serial.println(turnR);
  switchR = 1;
  turnL = 0;
}

void turnLeft(){
  analogWrite(speedR, 52);
  analogWrite(speedL, 0);
  Serial.print("Turning Left: ");
  turnL = 1;
  Serial.println(turnL);
  switchL = 1;
  //Serial.println(switchX);
  turnR = 0;
}

void headStraight(){
  analogWrite(speedR, 50);
  analogWrite(speedL, 57);
  //Serial.println("Heading Straight");
  //turnL = 0;
}

void stopMoving(){
  analogWrite(speedR, 0);
  analogWrite(speedL, 0);
  Serial.println("Stopped moving");
  turnL = 0;
  turnR = 0;
}

void followLine(){
  int CL_read = digitalRead(IR_CL);
  int CR_read = digitalRead(IR_CR);
  int C_read = digitalRead(IR_C);


  if(C_read==A){
    headStraight();
    //analogWrite(speedR, 50);
    //analogWrite(speedL, 50);
  }
  else if(CL_read==A && CR_read==NA  && C_read==NA){
    turnLeft();
    //analogWrite(speedR, 55);
    //analogWrite(speedL, 45);
  }
  else if(CL_read==NA && CR_read==A && C_read==NA){
    turnRight();
    //analogWrite(speedL, 55);
    //analogWrite(speedR, 45);
  }
  Serial.println("Heading Straight");
  turnL = 0;
  turnR = 0;
}

void uTurn(){
    analogWrite(speedL, 57);
    analogWrite(speedR, 0);
    Serial.print("U turn: ");
    turnB = 1;
    Serial.println(turnB);
    turnL = 0;
    turnR = 0;
}

void intersectionDetector(){
  int L_line = digitalRead(IR_L);
  int R_line = digitalRead(IR_R);

  int CL_read = digitalRead(IR_CL);
  int CR_read = digitalRead(IR_CR);
  int C_read = digitalRead(IR_C);

  if(CL_read == A || CR_read==A || C_read==A){
    indicator = 0;
  }
  if(R_line == A && CR_read==A && C_read==A){
    indicator = 1;
  }
  if (CR_read == NA && CL_read == NA && R_line == NA && L_line == NA && C_read == NA){
    indicator = 1;
  }
  if(L_line == A && CL_read==A && C_read==A){
    indicator = 1;
  }
  digitalWrite(LED, indicator);
  /*if(turnL!=1 && switchX == 1){
    intDec = 'l';
    switchX = 0;
    Serial.println("A");
  }*/
  //Serial.println(intDec);
}

void dryRun(){
  int L_line = digitalRead(IR_L);
  int R_line = digitalRead(IR_R);

  int CL_read = digitalRead(IR_CL);
  int CR_read = digitalRead(IR_CR);
  int C_read = digitalRead(IR_C);
  
  //followLine();
  
  if(L_line == A && CL_read==A && C_read == A){
    turnLeft();
    //delay(200);
    //stopMoving();
    //indicator = 1;
    //intDec = 'l';
    //Serial.println(switchX);
    
  }
  else if(CL_read == A || CR_read==A || C_read==A){
    //Serial.println("Straight available");
    followLine();
    //intDec = 's';
    //indicator = 0;
  }
  else if(R_line == A && CR_read==A && C_read == A){
    turnRight();
    delay(200);
    stopMoving();
    //intDec = 'r';
    //indicator = 1;
  }
  else if (CR_read == NA && CL_read == NA && R_line == NA && L_line == NA && C_read == NA){
    uTurn(); //u-turn
    //stopMoving(); 
    //intDec = 'b';
    //indicator = 1;
  }
  /*else{
    indicator = 0;
  }*/
  //digitalWrite(LED, indicator);
  intersectionDetector();
  //Serial.println(intDec);
  
}

void turning(){
  if(turnR!=1 && switchX == 1){
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
  if(turnR!=1 && switchR == 1){
    intDec = 'r';
    Serial.println("R");
    switchR = 0;
  }
}
