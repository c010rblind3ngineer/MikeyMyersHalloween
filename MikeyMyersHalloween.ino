/* 'Mikey Myers Halloween' project

    Componenets:
                  - Arduino Nano
                  - Ultrasonic sensor
                  - Servo motor
                  - Breadboard
                  - Some jumper wires

    Created on 7 November 2022 by c010blind3ngineer
*/

#include <Servo.h>

#define trigPin 7
#define echoPin 8

Servo myServo;
const int servoPin = 9;
int servoPos = 90;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58;

  if (distance >= 200 || distance <= 0) {
    Serial.println("Out of range");
  }
  if (distance <= 40) {
    myServo.write(45);
    delay(500);
    myServo.write(servoPos);
  }

  Serial.print(distance);
  Serial.println(" cm");
  delay(250);

}
