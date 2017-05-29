#include <Servo.h> 

  // Pin Set-up
const int SW_pin = 2; // digital pin connected to switch output - pressing joystick down
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
const int Servo1_pin = 4; //pwm pin connected to servo1
const int Servo2_pin = 6; //pwm pin connected to servo2

Servo Servo1;
Servo Servo2;


void setup() {
    //Servo Set-up
  Servo1.attach(Servo1_pin);
  Servo2.attach(Servo2_pin);

    //Sets up switch using internal pull up resistor
  pinMode(SW_pin, INPUT); 
  digitalWrite(SW_pin, HIGH);

    //Set up serial monitor at 9600 baud rate
  Serial.begin(9600);
  
  delay(500);
  
}

void loop() {
    //Moves servo to scaled value of joystick's x position 
    //jostick position 0 = servo 2 degrees (minimum)
    //joystick position 512 = servo 87 degrees (middle)
    //joystick position 1024 = servo 173 degrees (maximum)
  Servo1.write( analogRead(X_pin) / 6 + 2);

    //Serial displays servo position in degrees
  Serial.print("Servo: "); Serial.print(analogRead(X_pin) / 6 + 2); Serial.print("\n");

    //Serial displays whether joystick is pressed    0=not pressed    1=pressed
  Serial.print("Switch:  "); Serial.print(digitalRead(SW_pin)); Serial.print("\n");

    //Serial displays joystick x position
  Serial.print("X-axis: "); Serial.print(analogRead(X_pin)); Serial.print("\n");

    //Serial displays joystick y position
  Serial.print("Y-axis: "); Serial.println(analogRead(Y_pin)); Serial.print("\n\n");
  
  delay(500);
  
}
