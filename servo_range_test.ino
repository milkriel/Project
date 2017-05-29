//Tower Pro Micro Servo SG90   
//range: 2 to 180

#include <Servo.h>

// Pin Set-up
const int servo_pin = 4;

Servo servo;

void setup() {
  //Servo Setup
servo.attach(servo_pin);

  //Serial set up at 9600 baud rate
Serial.begin(9600);
}

void loop() {
//sweeps through servo's range, change i value to find servo's correct range (servos will get damaged if over-rotated)
/*
for(int i=2; i  < 181 ; i++) {
  servo.write(i);
  Serial.println(i);
  delay(300);
}
*/

//test individual position
servo.write(180);
}
