#include<AFMotor.h>
#define echo A0
#define trig A1

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

long times, distance;

void setup() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  times = pulseIn(echo, HIGH);
  distance = times / 29.1 / 2;

  if(distance < 20)
  {
    Backward();
    delay(500);
    int randNumb = random(2);
    if(randNumb == 0)
      TurnRight();
    else
      TurnLeft();
  }else
    Forward();
   
}

void Forward()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}
void Backward()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}
void TurnRight()
{
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
}
void TurnLeft()
{
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
}
