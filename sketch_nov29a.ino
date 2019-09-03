
int pot2=A1;
const int motor_IN1=11; // MOTOR input 1(L293)
const int motor_IN2=4; // motor input 2(L293)
const int motor_ENA=9; //enable pin(L293) 
double speed_Level; //variable of speed level
int Percent;
void setup() {
  Serial.begin(9600);
 pinMode(motor_IN1,OUTPUT);
 pinMode(motor_IN2,OUTPUT);
pinMode(11,OUTPUT);
TCCR2B=(TCCR2B&0xF8) | 2;

}

void loop() {
 analogWrite(motor_IN1,speed_Level); 
 analogWrite(motor_IN2,LOW);

speed_Level=analogRead(pot2);  
speed_Level=constrain(speed_Level,0,255);

Percent =(speed_Level/255)*100;

Serial.print("PWM LEVEL= ");
Serial.print(speed_Level);
Serial.print("  , ");
Serial.print(" speed level in Percent= %");
Serial.print(Percent);
Serial.print("\n");
}
