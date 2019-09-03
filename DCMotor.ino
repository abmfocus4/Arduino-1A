int pwmVal = 0;
int pwmPin1 = 3;
int pwmPin2 = 11;
int dirPin1 = 12;
int dirPin2 = 13;
int dirVal1 = 0;
int dirVal2 = 1;

String input;

void setup() 
{
  Serial.begin(9600);
  Serial.println("Reference:");
  Serial.println("  p###: change PWM for motor to '###'");
  Serial.println("  r: reverse motor direction");
  Serial.println();
  Serial.println("Default PWM is 0");
  
  analogWrite(pwmPin1, pwmVal);
  analogWrite(pwmPin2, pwmVal);

  digitalWrite(dirPin1, dirVal1);
  digitalWrite(dirPin2, dirVal2);
}

void loop() 
{
  if(Serial.available())
  {
    input = Serial.readString();

    switch (input[0])
    {
      case 'p':
        pwmVal = input.substring(1).toInt();
        Serial.print("PWM set to ");
        Serial.println(pwmVal);
        break;
        
      case 'r':
        pwmVal = 100;
        dirVal1 = !dirVal1;
        dirVal2 = !dirVal2;
        analogWrite(pwmPin1, pwmVal);
        analogWrite(pwmPin2, pwmVal);
        digitalWrite(dirPin1, dirVal1);
        digitalWrite(dirPin2, dirVal2);
        Serial.println("motor speed set to 0; reversing motor");
        break;
    }
  }

  analogWrite(pwmPin1, pwmVal);
  analogWrite(pwmPin2, pwmVal);
}
