#include <NewPing.h>

#define TRIG_PIN A0 // Пин для отправки ультразвукового сигнала
#define ECHO_PIN A1 // Пин для приёма ультразвукового сигнала
#define MAX_DISTANCE 200 // Максимальное расстояние для определения препятствия
#define MOTOR1_PIN1 2 // Пин для управления мотором 1 (вперёд)
#define MOTOR1_PIN2 3 // Пин для управления мотором 1 (назад)
#define MOTOR2_PIN1 4 // Пин для управления мотором 2 (вперёд)
#define MOTOR2_PIN2 5 // Пин для управления мотором 2 (назад)
#define MOTOR3_PIN1 6 // Пин для управления мотором 3 (вперёд)
#define MOTOR3_PIN2 7 // Пин для управления мотором 3 (назад)
#define MOTOR4_PIN1 8 // Пин для управления мотором 4 (вперёд)
#define MOTOR4_PIN2 9 // Пин для управления мотором 4 (назад)

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); // Объект для работы с ультразвуковым датчиком

void setup() {
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);
  pinMode(MOTOR3_PIN1, OUTPUT);
  pinMode(MOTOR3_PIN2, OUTPUT);
  pinMode(MOTOR4_PIN1, OUTPUT);
  pinMode(MOTOR4_PIN2, OUTPUT);
}

void loop() {
  int distance = sonar.ping_cm(); // Получаем расстояние до препятствия в сантиметрах

  if (distance > 0 && distance <= 10) { // Если препятствие на расстоянии до 10 см
    stopRobot();
    delay(1000); // Пауза перед поворотом
    reverseRobot();
    delay(2000); // Время движения назад
    stopRobot();
    delay(1000); // Пауза перед поворотом
    turnRobot();
  } else {
    moveRobot();
  }
}

void moveRobot() {
  digitalWrite(MOTOR1_PIN1, HIGH);
  digitalWrite(MOTOR1_PIN2, LOW);
  digitalWrite(MOTOR2_PIN1, HIGH);
  digitalWrite(MOTOR2_PIN2, LOW);
  digitalWrite(MOTOR3_PIN1, HIGH);
  digitalWrite(MOTOR3_PIN2, LOW);
  digitalWrite(MOTOR4_PIN1, HIGH);
  digitalWrite(MOTOR4_PIN2, LOW);
}

void stopRobot() {
  digitalWrite(MOTOR1_PIN1, LOW);
  digitalWrite(MOTOR1_PIN2, LOW);
  digitalWrite(MOTOR2_PIN1, LOW);
  digitalWrite(MOTOR2_PIN2, LOW);
  digitalWrite(MOTOR3_PIN1, LOW);
  digitalWrite(MOTOR3_PIN2, LOW);
  digitalWrite(MOTOR4_PIN1, LOW);
  digitalWrite(MOTOR4_PIN2, LOW);
}

void reverseRobot() {
  digitalWrite(MOTOR1_PIN1, LOW);
  digitalWrite(MOTOR1_PIN2, HIGH);
  digitalWrite(MOTOR2_PIN1, LOW);
  digitalWrite(MOTOR2_PIN2, HIGH);
  digitalWrite(MOTOR3_PIN1, LOW);
  digitalWrite(MOTOR3_PIN2, HIGH);
  digitalWrite(MOTOR4_PIN1, LOW);
  digitalWrite(MOTOR4_PIN2, HIGH);
}

void turnRobot() {
  digitalWrite(MOTOR1_PIN1, HIGH);
  digitalWrite(MOTOR1_PIN2, LOW);
  digitalWrite(MOTOR2_PIN1, LOW);
  digitalWrite(MOTOR2_PIN2, HIGH);
  digitalWrite(MOTOR3_PIN1, HIGH);
  digitalWrite(MOTOR3_PIN2, LOW);
  digitalWrite(MOTOR4_PIN1, LOW);
  digitalWrite(MOTOR4_PIN2, HIGH);
}
