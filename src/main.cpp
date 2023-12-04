#include <Arduino.h>
#include <Stepper.h>

#define TRIGGER_PIN_1 2  
#define ECHO_PIN_1 3    

#define TRIGGER_PIN_2 4  
#define ECHO_PIN_2 5     

#define TRIGGER_PIN_3 6  
#define ECHO_PIN_3 7     

#define STEPPER_MOTOR1 8  
#define STEPPER_MOTOR2 9     
#define STEPPER_MOTOR3 10  
#define STEPPER_MOTOR4 11     

const int stepsPerRevolution = 200;  
Stepper Sun(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600);
  Sun.setSpeed(60);

  pinMode(TRIGGER_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);

  pinMode(TRIGGER_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);

  pinMode(TRIGGER_PIN_3, OUTPUT);
  pinMode(ECHO_PIN_3, INPUT);
}

float getDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  return distance;
}

void loop() {
  float distance_1 = getDistance(TRIGGER_PIN_1, ECHO_PIN_1);
  float distance_2 = getDistance(TRIGGER_PIN_2, ECHO_PIN_2);
  float distance_3 = getDistance(TRIGGER_PIN_3, ECHO_PIN_3);

  if (distance_1 < 20) {
    // sol
    Serial.println("2");
  }

  if (distance_2 < 20) {
    // terra
    Serial.println("0");
  }

  if (distance_3 < 20) {
    // lua
    Serial.println("1");
  }

  Sun.step(stepsPerRevolution);
  delay(100);  // Atraso para evitar leituras muito frequentes
}
