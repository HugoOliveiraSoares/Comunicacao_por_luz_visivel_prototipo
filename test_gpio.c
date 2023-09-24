#include <stdbool.h>
#include <stdio.h>
#include <wiringPi.h>

#define PIN 3

int cont = 0;
int in = 0;

void contador(void);

// NOTE: O menor tempo atingido - 100 microsegundos
int main() {

  wiringPiSetup();

  // pinModeAlt(PIN, 2);

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
