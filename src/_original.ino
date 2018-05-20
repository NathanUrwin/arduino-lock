#include <Servo.h>


#define LINEARACTUATORPIN 9 // Linear Actuator digital pin


const int receiver1Pin = 2;
const int receiver2Pin = 3;


const int greenledPin = 5;


const int redledPin = 6;


int button1State = 0; // variable for reading button one status


int button2State = 0; // variable for reading button two status


Servo LINEARACTUATOR;


int linearValue = 1100; // current positional value being sent to the actuator

void setup()
{


LINEARACTUATOR.attach(LINEARACTUATORPIN, 1050, 2000);


pinMode(receiver1Pin, INPUT); //Pin Definition
pinMode(receiver2Pin, INPUT);
pinMode(greenledPin, OUTPUT);
pinMode(redledPin, OUTPUT);


LINEARACTUATOR.writeMicroseconds(linearValue);


}


void loop()
{


// if button on fob is pressed, set the linear value


button1State = digitalRead(receiver1Pin);

if(button1State == HIGH)
{
linearValue = 1100; //set position value
LINEARACTUATOR.writeMicroseconds(linearValue);


digitalWrite(greenledPin, LOW); //Turn on green led
digitalWrite(redledPin, HIGH); //Turn off red led
delay(200);
digitalWrite(redledPin,LOW);
delay(200);
digitalWrite(redledPin, HIGH);
delay(200);
digitalWrite(redledPin, LOW);
delay(200);
digitalWrite(redledPin, HIGH);
delay(200);
digitalWrite(redledPin,LOW);
delay(200);
digitalWrite(redledPin, HIGH);
delay(200);
digitalWrite(redledPin, LOW);
delay(200);
digitalWrite(redledPin, HIGH);
}



button2State = digitalRead(receiver2Pin);

if(button2State == HIGH)
{
linearValue = 1700;

LINEARACTUATOR.writeMicroseconds(linearValue);


digitalWrite(greenledPin, HIGH); //Turn off green led
digitalWrite(redledPin, LOW); //Turn on red led
delay(200);
digitalWrite(greenledPin,LOW);
delay(200);
digitalWrite(greenledPin, HIGH);
delay(200);
digitalWrite(greenledPin, LOW);
delay(200);
digitalWrite(greenledPin, HIGH);
delay(200);
digitalWrite(greenledPin,LOW);
delay(200);
digitalWrite(greenledPin, HIGH);
delay(200);
digitalWrite(greenledPin, LOW);
delay(200);
digitalWrite(greenledPin, HIGH);
}


LINEARACTUATOR.writeMicroseconds(linearValue);


}
