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

char byte_to_char(bool *b, int debug) {
  int c = 0;
  for (int i = 0; i < 8; i++) {
    c += *(b + i) * pow(2, 7 - i);
    if (debug) {
      printf("%i", *(b + i));
    }
  }
  return (char)c;
}

void print_byte(bool *b) {
  int c = 0;
  c = byte_to_char(b, true);
  printf(" - %c", c);
  printf("\n");
}

void print_msg(bool *b[5]) {
  for (int i = 0; i < 5; i++) {
    printf("%c", byte_to_char(b[i], false));
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
