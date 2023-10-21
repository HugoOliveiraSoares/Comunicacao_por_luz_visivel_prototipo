#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define PIN 3
#define PERIOD 100

void shift_left(bool *b) {
  for (int i = 1; i < 8; i++) {
    b[i - 1] = b[i];
  }
}

bool *get_byte() {
  bool *p = malloc(sizeof(bool) * 8);
  for (int i = 0; i < 8; i++) {
    *(p + i) = digitalRead(PIN);
    delay(PERIOD);
  }
  return p;
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

void print_msg(bool *b[5]) {
  shift_left(b[0]);
  for (int i = 1; i < 5; i++) {
    shift_left(b[i]);
    b[i - 1][7] = b[i][0];
  }

  int a = 0;
  for (int i = 0; i < 5; i++) {
    a = 0;
    for (int y = 0; y < 8; y++) {
      a += b[i][y] * pow(2, 7 - y);
    }
    printf("%c", a);
  }
  printf("\n");
}

int main() {

  wiringPiSetup();

  pinMode(PIN, INPUT);

  printf("RECEPTOR\n");
  while (TRUE) {

    bool *p[5];
    if (digitalRead(PIN) == HIGH) {
      delay(PERIOD + 10);
      for (int i = 0; i < 5; i++) {
        p[i] = get_byte();
        print_byte(p[i]);
      }
      print_msg(p);
      for (int i = 0; i < 5; i++) {
        free(p[i]);
      }
    }
  }

  return 0;
}
