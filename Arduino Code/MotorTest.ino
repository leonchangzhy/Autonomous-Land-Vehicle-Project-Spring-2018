int motor = 13; //motor is pin 15
int i;
int j;

void setup() 
{
  Serial.begin(9600);
  pinMode(motor, OUTPUT);  //pin is set to output
}

void loop()
{
  
/////////////// O.G. Code for running purpose ///////////////
 
//  digitalWrite(motor, HIGH);
//  delay(); // 8% of 100 microseconds
//  digitalWrite(motor, LOW);
//  delay();  //92% of 100 microseconds

//////////////// Lakshya developed the code ////////////////

for(i = 0; i <= 100; i++)
{
  Serial.print(i);
  digitalWrite(motor, HIGH);
  delay(i); // milliseconds
  digitalWrite(motor, LOW);
  delay(100-i);  //milliseconds
  delay(4000);
}

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


