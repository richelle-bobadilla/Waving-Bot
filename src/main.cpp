#include <Arduino.h>
#include <Servo.h>

Servo myServo;
int servoPin = 11;
int startingPos = 0;

int trigPin = 13;
int echoPin = 12;
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
  
  // restart at starting position
  myServo.write(startingPos);
  
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance <= 60 && distance >= 20) {
    myServo.write(120);
    delay(1000);
    myServo.write(startingPos);
    delay(1000);
    
  }
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(100);
}