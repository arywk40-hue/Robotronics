#include <Arduino.h>

//  SENSOR & MOTOR PINS 
const int sensorPins[5] = {2, 3, 4, 5, 6};   // IR sensors
const int leftForward = 9;
const int leftBackward = 10;
const int rightForward = 11;
const int rightBackward = 12;

//  PID PARAMETERS  value them accordingkly first increase kp then ki and kd
float Kp = 0;   
float Ki = 0;   
float Kd = 0;   

float error = 0, prevError = 0, P = 0, I = 0, D = 0, PIDvalue = 0;
int baseSpeed = 150;   // speed can be increased or decreased according to requirement

void setup() {
  
  for (int i = 0; i < 5; i++) pinMode(sensorPins[i], INPUT);

  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);
  pinMode(rightForward, OUTPUT);
  pinMode(rightBackward, OUTPUT);
}

void loop() {
  int sensor[5];
  int position = 0;
  int activeSensors = 0;

  for (int i = 0; i < 5; i++) {
    sensor[i] = digitalRead(sensorPins[i]);
    if (sensor[i]) {
      position += (i - 2);   // Weighted offset: [-2, -1, 0, +1, +2] 0 is center -2 is leftmost 2 is rightmost 
      activeSensors++;
    }
  }

 
  if (activeSensors > 0) {
    error = position / (float)activeSensors;  
  } else {
    // If line is lost, decide direction based on previous error
    if (prevError < 0) error = -2;
    else if (prevError > 0) error = 2;
    else stopMotors();  
  }


  I += error;
  D = error - prevError;
  PIDvalue = Kp * P + Ki * I + Kd * D;
  prevError = error;


  int leftSpeed = baseSpeed - PIDvalue; //this can not be written as leftSpeed = -baseSpeed +PIDvalue as it will reverse the motor
  int rightSpeed = baseSpeed + PIDvalue;

  // the speed can be changed according to requirement the greater the speed the more is the error the lesser the speed the lesser is the error and more steadier the robot will be
  leftSpeed = constrain(leftSpeed, 0, 255);
  rightSpeed = constrain(rightSpeed, 0, 255);

 
  moveMotors(leftSpeed, rightSpeed);
}


void moveMotors(int leftSpeed, int rightSpeed) {
  analogWrite(leftForward, leftSpeed);
  analogWrite(rightForward, rightSpeed);
  analogWrite(leftBackward, 0);
  analogWrite(rightBackward, 0);
}


void stopMotors() {
  analogWrite(leftForward, 0);
  analogWrite(rightForward, 0);
  analogWrite(leftBackward, 0);
  analogWrite(rightBackward, 0);
}
