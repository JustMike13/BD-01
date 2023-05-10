#include <Arduino.h>
#include <Servo.h>
#include <ServoMotor.h>
#include <ButtonControl.h>
#include <BuzzerControl.h>

ServoMotor twistServo;
ServoMotor tiltServo;
BuzzerControl buzzControl;
ButtonControl buttonControl;

void twistHead(){
  // Serial.println("        Start adding movement");
  const int twistDelay = 500;
  const int neutralPosition = 90;
  const int twistAngle = 30;
  const int tiltAngle = 10;
  // twist form 90 to 120
  twistServo.Move(neutralPosition - 5 + twistAngle);
  delay(twistDelay);
  // twist from 120 to 60
  twistServo.Move(neutralPosition- 5 - twistAngle);
  delay(twistDelay);
  // twist from 60 to 90
  twistServo.Move(neutralPosition- 5);
  delay(twistDelay);
  // tilt from 90 to 110
  tiltServo.Move(neutralPosition + tiltAngle);
  delay(twistDelay);
  // sound
  buzzControl.Beep();
  // tilt from 110 to 90
  tiltServo.Move(neutralPosition);
  // Serial.println("        Finished adding movement");
}

void setup() {
  Serial.begin(9600);
  twistServo.Set(9, 90-5, 4);  // attaches the servo on pin 9 to the servo object
  tiltServo.Set(10, 90, 4);  // attaches the servo on pin 9 to the servo object
  buzzControl.Set(6); // set pin 6 for the buzzer
  buttonControl.Set(3); // set pin 3 for the button
}

void loop() {
  if(buttonControl.ButtonPressed()){
    twistHead();
  }
}