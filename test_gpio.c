#include <stdbool.h>
#include <stdio.h>
#include <wiringPi.h>

#define PIN 3

int cont = 0;
int in = 0;

void contador(void);

int main() {

  wiringPiSetup();

  // pinMode(PIN, INPUT);

  wiringPiISR(PIN, INT_EDGE_RISING, &contador);

  while (true) {
    // in = digitalRead(PIN);
    // printf("%d\n", in);
    // delay(500);
  }

  return 0;
}

void contador(void) {

  cont++;
  printf("INTERRUPSSÃO: %d\n", cont);
}
