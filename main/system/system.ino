#include <Servo.h>

#define trigPin 13
#define echoPin 12

const int motorPin1 = 9;
const int motorPin2 = 10;
Servo servo1;

void setup()
{
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo1.attach(6);
  Serial.begin(9600);
}

void loop()
{
  scanDistance();
}

void scanDistance()
{
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  setDirection(distance);
  delay(500);
}

void setMotorSpeed(int speed)
{
  analogWrite(motorPin1,speed);	// set the new speed
  analogWrite(motorPin2,speed);	// set the new speed
}

void setDirection(long distance)
{
  if (distance < 30) 
  {
    if(distance < 20)
    {
      setMotorSpeed(0);
      servo1.write(90);
      return;
    } 
    else
    {
      
      if(random(0,2) == 0)
      {
        servo1.write(70);
      }
      else
      {
        servo1.write(100);
      }
      Serial.println(distance);
      setMotorSpeed(255);
    }
    delay(1000);
  }
  else 
  {
    Serial.print(distance);
    Serial.println(" cm");
    servo1.write(90);
    setMotorSpeed(255);
  }
}


