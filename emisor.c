#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <wiringPi.h>

#define PERIOD 100
#define LED_PIN 3

void send_byte(bool *byte);
bool *convert(int n);

int main() {

  wiringPiSetup();

  pinMode(LED_PIN, OUTPUT);

  char msg[5] = "Hello";

  printf("EMISSOR\n");
  digitalWrite(LED_PIN, LOW);
  delay(5000);
  while (TRUE) {
    // START CODE
    digitalWrite(LED_PIN, HIGH);
    delay(PERIOD);

    // SEND BYTES
    for (int i = 0; i < 5; i++) {
      bool *byte = convert((int)msg[i]);
      send_byte(byte);
      printf(" - %c\n", msg[i]);
    }
    printf("%s\n", msg);

    // STOP CODE
    digitalWrite(LED_PIN, LOW);
    delay(5000);
  }

  return 0;
}

void send_byte(bool *byte) {

  for (int i = 0; i < 8; i++) {
    printf("%i", *(byte + i));
    digitalWrite(LED_PIN, *(byte + i));
    delay(PERIOD);
  }
}

bool *convert(int n) {
  // [0] bit mais significativo
  // [7] bit menos significativo
  static bool bin[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  int rem = 0;

  for (int y = 7; y >= 0; y--) {
    rem = n % 2;

    n /= 2;

    bin[y] = rem;
  }

  return bin;
}
