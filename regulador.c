#include <stdbool.h>
#include <stdio.h>
#include <wiringPi.h>

#define PIN 3

int main() {

  wiringPiSetup();

  pinMode(PIN, INPUT);

  while (TRUE) {
    printf("%d\n", digitalRead(PIN));
    delay(100);
  }

  return 0;
}
