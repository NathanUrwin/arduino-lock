#include <Servo.h>
//
const int SERVO_PIN = 7;
const int A_BUTTON_PIN = 13;
const int B_BUTTON_PIN = 12;
//
boolean debugMode = true;
boolean aButtonSwitch = true;
boolean bButtonSwitch= false;
// 1050 MIN -> 1950 MAX
Servo linearActuator;

void setup()
{
  if (debugMode) {
    Serial.begin(9600);
  }
  //
  pinMode(A_BUTTON_PIN, INPUT);
  pinMode(B_BUTTON_PIN, INPUT);
  //
  linearActuator.attach(SERVO_PIN);
}

void loop()
{
  int aButtonStatus = digitalRead(A_BUTTON_PIN);
  int bButtonStatus = digitalRead(B_BUTTON_PIN);
  //
  if (debugMode) {
    Serial.print("aButtonStatus:");
    Serial.print(aButtonStatus);
    Serial.print(" ");
    Serial.print("bButtonStatus:");
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
  //
  if (debugMode) {
    Serial.print("aButtonSwitch:");
    Serial.print(aButtonSwitch);
    Serial.print(" ");
    Serial.print("bButtonSwitch:");
    Serial.println(bButtonSwitch);
    Serial.println();
  }
  if (aButtonSwitch) {
    linearActuator.writeMicroseconds(1750);
    aButtonSwitch = false;  // still needs to be tested
  }
  if (bButtonSwitch) {
    linearActuator.writeMicroseconds(1050);
    bButtonSwitch = false;  // still needs to be tested
  }
  delay(1500);
}
