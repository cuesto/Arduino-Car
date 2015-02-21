// We'll be controlling the motor from pin 9.
// This must be one of the PWM-capable pins.

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
  // Set up the serial port:
  //Serial.begin(9600);
  speed = 255;
}


void loop()
{
  // Here we've used comments to disable some of the examples.
  // To try different things, uncomment one of the following lines
  // and comment the other ones. See the functions below to learn
  // what they do and how they work.

   //motorOnThenOff();
  // motorOnThenOffWithSpeed();
   motorAcceleration();
    // serialSpeed();
}

// This function slowly accelerates the motor to full speed,
// then back down to zero.

void motorAcceleration()
{
  //int speed;

  analogWrite(motorPin1,speed);	// set the new speed
  analogWrite(motorPin2,speed);	// set the new speed
  // decelerate the motor
/*
  for(speed = 255; speed >= 0; speed--)
  {
    analogWrite(motorPin,speed);	// set the new speed
    delay(delayTime);           	// delay between speed steps
  }
  */
}

/*
// This function will let you type a speed into the serial
// monitor window. Open the serial monitor using the magnifying-
// glass icon at the top right of the Arduino window. Then
// type your desired speed into the small text entry bar at the
// top of the window and click "Send" or press return. The motor
// will then operate at that speed. The valid range is 0 to 255.

void serialSpeed()
{
  int speed;
  
  Serial.println("Type a speed (0-255) into the box above,");
  Serial.println("then click [send] or press [return]");
  Serial.println();  // Print a blank line

  // In order to type out the above message only once,
  // we'll run the rest of this function in an infinite loop:

  while(true)  // "true" is always true, so this will loop forever.
  {
    // First we check to see if incoming data is available:
  
    while (Serial.available() > 0)
    {
      // If it is, we'll use parseInt() to pull out any numbers:
      
      speed = Serial.parseInt();
  
      // Because analogWrite() only works with numbers from
      // 0 to 255, we'll be sure the input is in that range:
  
      speed = constrain(speed, 0, 255);
      
      // We'll print out a message to let you know that the
      // number was received:
      
      Serial.print("Setting speed to ");
      Serial.println(speed);
  
      // And finally, we'll set the speed of the motor!
      
      analogWrite(motorPin, speed);
      digitalWrite(motorPin, false);
      digitalWrite(motorPin, true);
      analogWrite(motorPin, speed);
    }
  }
}


*/
