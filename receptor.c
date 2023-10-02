#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <wiringPi.h>

#define PIN 3
#define PERIOD 100

void shift_left(bool *b) {
  for (int i = 1; i < 8; i++) {
    b[i - 1] = b[i];
  }
}

bool *get_byte() {
  static bool ret[8];
  for (int i = 0; i < 8; i++) {
    ret[i] = digitalRead(PIN);
    delay(PERIOD - 1);
  }
  shift_left(ret);
  return ret;
}

void print_byte(bool *b) {
  int a = 0;
  for (int i = 0; i < 8; i++) {
    a += *(b + i) * pow(2, 7 - i);
    printf("%i", *(b + i));
  }
  printf(" - %c", a);
  printf("\n");
}

int main() {

  wiringPiSetup();

  pinMode(PIN, INPUT);

  printf("RECEPTOR\n");
  while (TRUE) {

    if (digitalRead(PIN) == LOW) {
      delayMicroseconds(10);
      for (int i = 0; i < 5; i++) {
        print_byte(get_byte());
      }
    }
  }

  return 0;
}
