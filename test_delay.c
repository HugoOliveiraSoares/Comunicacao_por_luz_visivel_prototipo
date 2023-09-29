#include <stdbool.h>
#include <stdio.h>
#include <wiringPi.h>

#define PIN 3

int cont = 0;
int in = 0;

// NOTE: O menor tempo atingido -
int main() {

  wiringPiSetup();
  pinMode(PIN, INPUT);

  while (true) {
    in = digitalRead(PIN);
    if (in == HIGH) {
      printf("%d\n", ++cont);
    }
    delay(1);
  }

  return 0;
}
