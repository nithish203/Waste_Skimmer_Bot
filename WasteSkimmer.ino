

#include <SoftwareSerial.h>
SoftwareSerial bt(2, 3);
const int IN1 = 5, IN2 = 6, IN3 = 9, IN4 = 11, IN5 = 8;
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;
int b;


void setup() {
  bt.begin(9600);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
}

void loop() {
  if (bt.available()) {
    int a;
    a = bt.read();
    
    if (a == 49) {
      Forward();
    } else if (a == 50) {
      Backward();
    } else if (a == 51) {
      Right();
    } else if (a == 52) {
      Left();
    }
    if (a == 53) {
      Brake();
    }
    
    b = us();
    if(b<20 && b>3){
      digitalWrite(IN5,HIGH);
    }
    else {
      digitalWrite(IN5,LOW);
    }

  }
}

// Input state to rotate 2 motors CW
void Forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
// Input state to rotate 2 motors CCW
void Backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
//Motor Brake
void Left() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Right() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void Brake() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
int us() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return(distance);
}
