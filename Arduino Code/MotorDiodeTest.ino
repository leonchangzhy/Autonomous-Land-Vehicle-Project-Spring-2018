int motorPin = 3;
 
void setup() 
{ 
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  //while (! Serial);
  //Serial.println("Speed 0 to 255");
} 
 
 
void loop() 
{ 
 
    int speed = 150;
    if (speed >= 0 && speed <= 255)
    {
      analogWrite(motorPin, speed);
    }
  
} 
