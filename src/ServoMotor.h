class ServoMotor {
  Servo motor; //variable to control the servomotor
  int angle; //current angle of the motor
  int rotationDelay; //delay in milliseconds after every movement

public:
  void Move2(int toAngle){
    angle = toAngle;
    motor.write(toAngle);
  }

  void Set(int Pin, int Angle, int RotDelay){
    motor.attach(Pin);
    angle = Angle;
    motor.write(Angle);
    rotationDelay = RotDelay;
  }

  //Moves the motor from angle to toAngle by dividing the diference in 
  //multiple steps and performing a short delay after every step for 
  //a smoother movement
  void Move(int toAngle){
    //set the direction of the rotation
    int d = toAngle > angle ? 1 : -1;
    //number degrees to reach toAngle
    int steps = (toAngle - angle)*d;
    //move and delay at every step
    for (int i = 0; i < steps; i++){
      angle += d;
      motor.write(angle);
      delay(rotationDelay);
    }
  }

  int getAngle()
  {
    return angle;
  }

  int getDelay()
  {
    return rotationDelay;
  }
};