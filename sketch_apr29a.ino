#include <NewPing.h>
#include <Servo.h>
NewPing sonar (10,11, 40);
Servo Servo1;
int max = 40;
int servoPin = 9;


void setup() {
  // put your setup code here, to run once:
  Servo1.attach(servoPin);
  Serial.begin(9600);
  delay(50);
  pinMode(2,OUTPUT);
  
}

void loop() {
  int distance = sonar.ping_cm();

  if (distance >= (max/2)){
    digitalWrite(2,HIGH);
  } else{
    digitalWrite(2,LOW);
  }
  
  
  Serial.print("The Distance is: ");
  Serial.println(distance);
  int angle = map(distance, 0, 40, 0, 180);
  Servo1.write(angle);
  delay(50);
}
