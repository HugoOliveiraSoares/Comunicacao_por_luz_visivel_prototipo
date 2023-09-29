#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <wiringPi.h>

#define PIN 3
#define PERIOD 100
#define START 11111111
#define STOP 00000000

bool *get_byte() {
  static bool ret[8];
  for (int i = 0; i < 8; i++) {
    ret[i] = digitalRead(PIN);
    delay(PERIOD);
  }
  return ret;
}

void print_byte(bool *b) {
  for (int i = 0; i < 8; i++) {
    printf("%i", *(b + i));
  }
  printf("\n");
}

int main() {

  wiringPiSetup();

  pinMode(PIN, INPUT);

  printf("RECEPTOR\n");
  while (TRUE) {

    if (digitalRead(PIN) == LOW) {
      delay(PERIOD);
      for (int i = 0; i < 5; i++) {
        print_byte(get_byte());
      }
    }
  }

  return 0;
}
