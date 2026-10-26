Проект №18
Дисплей с одной цифрой 

Код:

// Проект 18 - Дисплей с одной цифрой

#define DATA 6   // к выводу 14 микросхемы 74HC595
#define LATCH 8  // к выводу 12 микросхемы 74HC595
#define CLOCK 10 // к выводу 11 микросхемы 74HC595

// Подготовить массив с комбинациями сегментов
// для цифр 0 - 9 и букв A - F
int digits[] = {
  252, 96, 218, 242, 102, 182, 190, 224, 
  254, 246, 238, 62, 156, 122, 158, 142
};

void setup() {
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
}

void loop() {
  int i;

  // Цикл для вывода символов 0-9, A-F
  for (i = 0; i < 16; i++) {
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, digits[i]);
    digitalWrite(LATCH, HIGH);
    delay(250);
  }

  // Цикл для вывода символов 0-9, A-F с точкой
  for (i = 0; i < 16; i++) {
    digitalWrite(LATCH, LOW);
    // Добавляем +1 к значению, чтобы включить десятичную точку
    shiftOut(DATA, CLOCK, LSBFIRST, digits[i] + 1);
    digitalWrite(LATCH, HIGH);
    delay(250);
  }
}
