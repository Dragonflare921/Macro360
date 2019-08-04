const char A = 13;
const char B = 12;
const char X = 11;
const char Y = 10;
const char RT = 9;
const char LT = 8;
const char UP = 7;
const char DOWN = 6;
const char LEFT = 5;
const char RIGHT = 4;
const char LB = 3;
const char RB = 2;
const char PRESS_DELAY = 35;

int BUTTON_YXRY = A0;
int BUTTON_RRXYY = A1;
int BUTTON_RXA = A3;
int BUTTON_R = A4;
int BUTTON_BXR = A2;
int BUTTON_YXR = A5;
char comm;
int flyTimer;

// prototypes
void pressButton(char btn);
void debugComm(char c);
void combo_bxb();
void combo_yxr();
void combo_yxry();
void combo_rx();
void combo_rrx();
void combo_rxa();
void combo_rrxyy();
void combo_yy();

void setup() {
  Serial.begin(9600);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(X, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(RT, OUTPUT);
  pinMode(LT, OUTPUT);
  pinMode(UP, OUTPUT);
  pinMode(DOWN, OUTPUT);
  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);

  pinMode(BUTTON_YXRY, INPUT);
  pinMode(BUTTON_RRXYY, INPUT);
  pinMode(BUTTON_RXA, INPUT);
  pinMode(BUTTON_R, INPUT);
  pinMode(BUTTON_BXR, INPUT);
  pinMode(BUTTON_YXR, INPUT);
  comm = 0;
  flyTimer = 0;
}

void loop() {
  //Serial.println(analogRead(A5));
  bool flyFlag = false;
  bool flyRepeatFlag = false;

  if (analogRead(BUTTON_YXRY) == 1023) {
    combo_yxry();
    delay(100);
  }
  if (analogRead(BUTTON_RRXYY) == 1023) {
    combo_rrxyy();
    delay(100);
  }
  if (analogRead(BUTTON_RXA) == 1023) {
    combo_rxa();
    delay(100);
  }
  if (analogRead(BUTTON_R) == 1023) {
    pressButton(RT);
  }
  if (analogRead(BUTTON_BXR) == 1023) {
    combo_bxr();
    delay(100);
  }
  if (analogRead(BUTTON_YXR) == 1023) {
    combo_yxr();
    delay(100);
  }
  
  if (Serial.available() > 0) {
    comm = Serial.read();
    debugComm(comm);
    comm = 0;
  }
}

void combo_bxb() {
  Serial.println("BXB");
  pressButton(B);
  delay(127);
  pressButton(X);
  delay(120);
  pressButton(B);
}

void combo_bxr() {
  Serial.println("BXR");
  pressButton(B);
  delay(170);
  pressButton(X);
  pressButton(RT);
}

void combo_yxr() {
  Serial.println("YXR");
  pressButton(Y);
  pressButton(X);
  pressButton(RT);
}

void combo_yxry() {
  Serial.println("YXRY");
  pressButton(Y);
  pressButton(X);
  pressButton(RT);
  pressButton(Y);
}

void combo_rx() {
  Serial.println("RX");
  pressButton(RT);
  pressButton(X);
}

void combo_rxa() {
  Serial.println("RXA");
  pressButton(RT);
  pressButton(X);
  pressButton(A);
}

void combo_rrx() {
  Serial.println("RRX");
  pressButton(RT);
  delay(130);
  pressButton(RT);
  delay(70);
  pressButton(X);
}

void combo_rrxyy() {
  Serial.println("RRXYY");
  combo_rrx();
  delay(175);
  combo_yy();
}

void combo_yy() {
  pressButton(Y);
  delay(PRESS_DELAY);
  pressButton(Y);
}

void debugComm(char c) {
  if (c == '0') {
    combo_yxr();
  }
  
  else if (c == '1') {
    combo_rx();
  }

  else if (c == '2') {
    combo_rxa();
  }

  else if (c == '3') {
    combo_bxb();
  }

  else if (c == '4') {
    combo_rrx();
  }

  else if (c == '5') {
    combo_rrxyy();
  }

  else if (c == '6') {
    combo_yy();
  }

  else if (c == '7') {
    combo_yxry();
  }
  
  else if (c == 'a') {
    pressButton(A);
  }
  
  else if (c == 'b') {
    pressButton(B);
  }
  
  else if (c == 'x') {
    pressButton(X);
  }

  else if (c == 'y') {
    pressButton(Y);
  }

  else if (c == 'r') {
    pressButton(RT);
  }

  else if (c == 'l') {
    pressButton(LT);
  }

  else if (c == 'U') {
    pressButton(UP);
  }
  
  else if (c == 'D') {
    pressButton(DOWN);
  }

  else if (c == 'L') {
    pressButton(LEFT);
  }

  else if (c == 'R') {
    pressButton(RIGHT);
  }
/*
  else if (c == 'S') {
    pressButton(START);
  }

  else if (c == 'B') {
    pressButton(BACK);
  }

  else if (c == 'G') {
    pressButton(GUIDE);
  }*/
}

// presses a button based on the argument
void pressButton(char btn) {
  switch (btn) {
    case A:
      Serial.println("A");
      digitalWrite(A, HIGH);
      delay(PRESS_DELAY);
      digitalWrite(A, LOW);
      break;
    case B:
      Serial.println("B");
      digitalWrite(B, HIGH);
      delay(PRESS_DELAY);
      digitalWrite(B, LOW);
      break;
    case X:
      Serial.println("X");
      digitalWrite(X, HIGH);
      delay(PRESS_DELAY);
      digitalWrite(X, LOW);
      break;
    case Y:
      Serial.println("Y");
      digitalWrite(Y, HIGH);
      delay(PRESS_DELAY);
      digitalWrite(Y, LOW);
      break;
    case RT:
      Serial.println("RT");
      digitalWrite(RT, HIGH);
      delay(PRESS_DELAY);
      digitalWrite(RT, LOW);
      break;
    case LT:
      Serial.println("LT");
      digitalWrite(LT, HIGH);
      delay(PRESS_DELAY);
      digitalWrite(LT, LOW);
      break;
    case UP:
      Serial.println("UP");
      digitalWrite(UP, HIGH);
      delay(PRESS_DELAY);
      digitalWrite(UP, LOW);
      break;
    case DOWN:
      Serial.println("DOWN");
      digitalWrite(DOWN, HIGH);
      delay(PRESS_DELAY);
      digitalWrite(DOWN, LOW);
      break;
    case LEFT:
      Serial.println("LEFT");
      digitalWrite(LEFT, HIGH);
      delay(PRESS_DELAY);
      digitalWrite(LEFT, LOW);
      break;
    case RIGHT:
      Serial.println("RIGHT");
      digitalWrite(RIGHT, HIGH);
      delay(PRESS_DELAY);
      digitalWrite(RIGHT, LOW);
      break;
    case LB:
      Serial.println("LB");
      digitalWrite(LB, HIGH);
      delay(PRESS_DELAY);
      digitalWrite(LB, LOW);
      break;
    case RB:
      Serial.println("RB");
      digitalWrite(RB, HIGH);
      delay(PRESS_DELAY);
      digitalWrite(RB, LOW);
      break;
    /*case START:
      Serial.println("START");
      digitalWrite(START, HIGH);
      delay(PRESS_DELAY);
      digitalWrite(START, LOW);
      break;
    case BACK:
      Serial.println("BACK");
      digitalWrite(BACK, HIGH);
      delay(PRESS_DELAY);
      digitalWrite(BACK, LOW);
      break;
    case GUIDE:
      Serial.println("GUIDE");
      digitalWrite(GUIDE, HIGH);
      delay(PRESS_DELAY);
      digitalWrite(GUIDE, LOW);
      break;*/
  }
}

