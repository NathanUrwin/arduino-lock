#ifndef RcLock_h
#define RcLock_h

#include "Arduino.h"
#include "Servo.h"

class RcLock {
  public:
    RcLock();
    void read();
    void write();

    const bool DEBUG_MODE = true;
    const bool L12_R_SERVO = false;
    const int A_BUTTON_PIN = 13;
    const int B_BUTTON_PIN = 12;
    const int SERVO_PIN = 7;
    const int DELAY = 1500;
    const int L12_R_MAX = 1750;
    const int L12_R_MIN = 1050;
    const int SERVO_MAX = 170;
    const int SERVO_MIN = 10;

    bool aButtonSwitch = true;
    bool bButtonSwitch = false;
    Servo linearServo;
};

#endif
