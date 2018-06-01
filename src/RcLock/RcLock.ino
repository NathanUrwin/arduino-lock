#include <Servo.h>

const int LOOP_DELAY = 1500;
const int A_BUTTON_PIN = 13;
const int B_BUTTON_PIN = 12;
const int SERVO_PIN = 7;

// true for serial output
bool DEBUG_MODE = true;
// change to true if needed
bool L12_R_SERVO = false;

int L12_R_MAX = 1750;
int L12_R_MIN = 1050;
int SERVO_MAX = 170;
int SERVO_MIN = 10;

bool aButtonSwitch = true;
bool bButtonSwitch = false;
Servo linearServo;

void setup() {
  if (DEBUG_MODE) {
    Serial.begin(9600);
  }
  pinMode(A_BUTTON_PIN, INPUT);
  pinMode(B_BUTTON_PIN, INPUT);
  linearServo.attach(SERVO_PIN);
}

void readButtons() {
  int aButtonStatus = digitalRead(A_BUTTON_PIN);
  int bButtonStatus = digitalRead(B_BUTTON_PIN);
  if (DEBUG_MODE) {
    Serial.print("aButtonStatus:");
    Serial.print(aButtonStatus);
    Serial.print(" bButtonStatus:");
    Serial.println(bButtonStatus);
  }
  if (aButtonStatus == HIGH) {
    aButtonSwitch = true;
    bButtonSwitch = false;
  }
  if (bButtonStatus == HIGH) {
    bButtonSwitch = true;
    aButtonSwitch = false;
  }
}

void writeServo() {
  if (DEBUG_MODE) {
    Serial.print("aButtonSwitch:");
    Serial.print(aButtonSwitch);
    Serial.print(" bButtonSwitch:");
    Serial.println(bButtonSwitch);
    Serial.println();
  }
  if (L12_R_SERVO) {
    if (aButtonSwitch) {
      linearServo.writeMicroseconds(L12_R_MAX);
      aButtonSwitch = false;  // still needs to be tested
    }
    if (bButtonSwitch) {
      linearServo.writeMicroseconds(L12_R_MIN);
      bButtonSwitch = false;  // still needs to be tested
    }
  } else {
    if (aButtonSwitch) {
      linearServo.write(SERVO_MAX);
      aButtonSwitch = false;
    }
    if (bButtonSwitch) {
      linearServo.write(SERVO_MIN);
      bButtonSwitch = false;
    }
  }
}

void loop() {
  readButtons();
  writeServo();
  delay(LOOP_DELAY);
}
