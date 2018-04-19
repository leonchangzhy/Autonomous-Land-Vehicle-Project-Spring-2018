#include <NewPing.h>

int motor = 13; //motor is pin 15
int i;
int j;
int mdis = 400;
#define trigPin 7
#define echoPin 5
NewPing sonar(trigPin, echoPin, 150);
void setup() 
{
  Serial.begin(9600);
  pinMode(motor, OUTPUT);  //pin is set to output
  pinMode(trigPin, INPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  
/////////////// O.G. Code for running purpose ///////////////
    //48.5 works very well
  long cm, duration, x;
  int distance = 0;
  delay(100);
  distance = sonar.ping_in();
  //digitalWrite(trigPin, LOW);
  //duration = pulseIn(echoPin, HIGH);
  cm = (duration/2)/29.1;
  //delay(2);
  //digitalWrite(trigPin, HIGH);
  if (distance > 5){
    i=48.5;
    digitalWrite(motor, HIGH);
    delay(i); // 8% of 100 microseconds
    digitalWrite(motor, LOW);
    delay(100-i);  //92% of 100 microseconds
  }
  else{
    digitalWrite(motor, LOW);
  }
  //Serial.println(cm);
  //delay(10000);
  Serial.println(sonar.ping_cm());
//////////////// Lakshya developed the code ////////////////

//for(i = 0; i <= 100; i++)
//{
//  Serial.print(i);
//  digitalWrite(motor, HIGH);
//  delay(i); // milliseconds
//  digitalWrite(motor, LOW);
//  delay(100-i);  //milliseconds
//  delay(4000);
//}

///////////////// Final code to be tested /////////////////
// Runs arduino for 4 seconds at a time trying different duty cycles (and therefore voltages)

//for(i = 0; i <= 100; i++)
//{
//Serial.print(i);
//j = 0;
//
//while (j <= 40)
//{
//  digitalWrite(motor, HIGH);
//  delay(i); // milliseconds
//  digitalWrite(motor, LOW);
//  delay(100-i);  //milliseconds
//  j++;
//}
//}

////////////////////////////////////////////////////////////

}


