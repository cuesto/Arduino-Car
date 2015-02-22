#define trigPin 13
#define echoPin 12

const int motorPin1 = 9;
const int motorPin2 = 10;
int speed = 0;

void setup()
{
  // Set up the motor pin to be an output:
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // Set up the serial port:
  Serial.begin(9600);
  speed = 255;
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
if (distance < 8) {  // This is where the LED On/Off happens digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off digitalWrite(led2,LOW); } else { digitalWrite(led,LOW); digitalWrite(led2,HIGH); } if (distance >= 200 || distance <= 0){
Serial.println("Out of range");
setMotorSpeed(0);
}
else {
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

