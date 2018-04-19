#include <Servo.h>  // servo library
Servo steering;  // servo control object

int trigPin = 10;
int echoPin = 11;
long duration, cm;
 
void setup() {
  steering.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin (9600);
}
 
void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  
  duration = pulseIn(echoPin, HIGH);
 
  cm = (duration/2) / 29.1; 

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if(cm <= 30)
  {
    steering.write(90);  
    //reverse
    delay(1000);
    steering.write(45);
    //forward
    delay(1000);
    steering.write(90);
  }
  if(cm > 30)
  {
    steering.write(90); 
    //forward   
  }
  delay(100);
}
