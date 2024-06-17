// Подключение библиотек
#include <AFMotor.h>

// Инициализация моторов
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

// Задание скорости движения
int speed = 150;

void setup() {
  // Настройка моторов
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);
}

void loop() {
  // Задаем расстояние, на которое робот должен ехать (в миллиметрах)
  int distance = 1000;
  
  // Приводим расстояние в количество шагов двигателей
  int steps = distance * 2;

  // Запуск двигателей вперед
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

  // Движение на заданное расстояние
  for (int i = 0; i < steps; i++) {
    delay(10);
  }

  // Остановка двигателей
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

  // Задержка перед следующим движением
  delay(1000);
}