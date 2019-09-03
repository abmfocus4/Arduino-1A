#define D3 10  // Enable Pin for motor 1

#define D11 11  // Enable Pin for motor 2

 

#define I1 8  // Control pin 1 for motor 1

#define I2 9  // Control pin 2 for motor 1

#define I3 12  // Control pin 1 for motor 2

#define I4 13  // Control pin 2 for motor 2

 

void setup() {

 

    pinMode(D3, OUTPUT);

    pinMode(D11, OUTPUT);

 

    pinMode(I1, OUTPUT);

    pinMode(I2, OUTPUT);

    pinMode(I3, OUTPUT);

    pinMode(I4, OUTPUT);

}

 

void loop() {

 

    analogWrite(D3, 153); // Run in half speed

    analogWrite(D11, 255); // Run in full speed

 

    digitalWrite(I1, HIGH);

    digitalWrite(I2, LOW);

    digitalWrite(I3, HIGH);

    digitalWrite(I4, LOW);

 

    delay(10000);

 

    // change direction

 

    digitalWrite(D3, LOW);

    digitalWrite(D11, LOW);

 

    delay(200);

 

    analogWrite(D3, 255);  // Run in full speed

    analogWrite(D11, 153);  // Run in half speed

 

    digitalWrite(I1, LOW);

    digitalWrite(I2, HIGH);

    digitalWrite(I3, LOW);

    digitalWrite(I4, HIGH);

 

    delay(10000);

}
