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
  // Set up the serial port:
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
  if (distance < 8) 
  {
    Serial.println("Out of range");
    setMotorSpeed(0);
    changeDirection(distance);
  }
  else 
  {
    Serial.print(distance);
    Serial.println(" cm");
    setMotorSpeed(255);
  }
  delay(500);
}

void setMotorSpeed(int speed)
{
  analogWrite(motorPin1,speed);	// set the new speed
  analogWrite(motorPin2,speed);	// set the new speed
}

void changeDirection(long distance)
{
  servo1.write(90);    // Tell servo to go to 90 degrees
  
  delay(1000);         // Pause to get it time to move
  
  servo1.write(180);   // Tell servo to go to 180 degrees
  
  delay(1000);         // Pause to get it time to move
  
  servo1.write(0);     // Tell servo to go to 0 degrees
  
  delay(1000);
}  
