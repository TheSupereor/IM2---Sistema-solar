#include <Arduino.h>

#define TRIGGER_PIN_1 2  // Pino de trigger do sensor ultrassônico 1
#define ECHO_PIN_1 3     // Pino de eco do sensor ultrassônico 1

#define TRIGGER_PIN_2 4  // Pino de trigger do sensor ultrassônico 2
#define ECHO_PIN_2 5     // Pino de eco do sensor ultrassônico 2

#define TRIGGER_PIN_3 6  // Pino de trigger do sensor ultrassônico 3
#define ECHO_PIN_3 7     // Pino de eco do sensor ultrassônico 3

void setup() {
  Serial.begin(9600);
  
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
    Serial.println("Objeto detectado no sensor 1!");
  }

  if (distance_2 < 20) {
    Serial.println("Objeto detectado no sensor 2!");
  }

  if (distance_3 < 20) {
    Serial.println("Objeto detectado no sensor 3!");
  }

  delay(100);  // Atraso para evitar leituras muito frequentes
}
