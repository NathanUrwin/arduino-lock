#include <Servo.h>
//
const int SERVO_PIN = 7;
const int A_BUTTON_PIN = 13;
const int B_BUTTON_PIN = 12;
//
boolean debugMode = true;
boolean aButtonSwitch = true;
boolean bButtonSwitch= false;
// 10 MIN -> 170 MAX
Servo linearServo;

void setup() 
{ 
  if (debugMode) {
    Serial.begin(9600);
  }
  //
  pinMode(A_BUTTON_PIN, INPUT);
  pinMode(B_BUTTON_PIN, INPUT);
  //
  linearServo.attach(SERVO_PIN);
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
    linearServo.write(170);
    aButtonSwitch = false;
  }
  if (bButtonSwitch) {
    linearServo.write(10);
    bButtonSwitch = false;
  }
  delay(1500);
}