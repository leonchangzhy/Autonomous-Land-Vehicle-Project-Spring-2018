#include <Servo.h>  // servo library
Servo steering;  // servo control object

int trigPin = 10;
int echoPin = 11;
long duration, cm;

int forward = 8;
int backward =9;
int PWM = 12;
 
void setup() {
  steering.attach(7);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin (9600);
  pinMode(forward, OUTPUT); 
  pinMode(backward, OUTPUT);
  pinMode(PWM, OUTPUT);
}
 
void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
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
    //reverse
    steering.write(90);
    analogWrite(PWM, 240);
    digitalWrite(forward,LOW);
    digitalWrite(backward,HIGH);  
    delay(2000);

    //forward
    steering.write(45);
    analogWrite(PWM, 240);
    digitalWrite(forward,HIGH);
    digitalWrite(backward,LOW);
    delay(2000);

    
    steering.write(90);
  }
  else
  {
    //forward
    steering.write(90);    
    analogWrite(PWM, 240);
    digitalWrite(forward,HIGH);
    digitalWrite(backward,LOW); 
  }
  delay(500);
}
