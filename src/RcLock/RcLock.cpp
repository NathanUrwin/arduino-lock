#include "Arduino.h"
#include "Servo.h"
#include "RcLock.h"

RcLock::RcLock() {
  if (DEBUG_MODE) {
    Serial.begin(9600);
  }
  pinMode(A_BUTTON_PIN, INPUT);
  pinMode(B_BUTTON_PIN, INPUT);

  linearServo.attach(SERVO_PIN);
}

void RcLock::read() {
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

void RcLock::write() {
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
