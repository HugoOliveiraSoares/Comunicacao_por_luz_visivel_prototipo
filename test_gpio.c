#include <stdbool.h>
#include <stdio.h>
#include <wiringPi.h>

#define PIN 3
#define LED 4
#define LEDA 6

int cont = 0;
int in = 0;

void contador(void);

// NOTE: O menor tempo atingido - 100 microsegundos
int main() {

  wiringPiSetup();
  wiringPiISR(PIN, INT_EDGE_RISING, contador);
  pinModeAlt(PIN, 6);
  pinMode(LED, OUTPUT);
  pinMode(LEDA, OUTPUT);

  while (true) {
    printf("Pisca led Amarelo\n");
    waitForInterrupt(PIN, 1000);
    digitalWrite(LEDA, HIGH);
    delay(1000);
    digitalWrite(LEDA, LOW);
    delay(1000);
  }

  return 0;
}

void contador(void) {

  cont++;
  printf("Pisca led Verde\n");
  for (int i = 0; i < 10; i++) {
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
  }
}
