#include <stdio.h>
#include <stdlib.h>
int PWM;
String l;
void setup() {
  
  //A
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT); 

  //B
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);

  Serial.begin(9600);
  while(!Serial);
  Serial.println("Enter the PWM value for two motors.");
}

void loop(){
  if (Serial.available()>0){
  l=Serial.readString();
  PWM=l.toInt();
  
  Serial.println(l);
  //A
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  analogWrite(3, PWM);

  //B
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH); 
  analogWrite(11, PWM); 

  }

}
