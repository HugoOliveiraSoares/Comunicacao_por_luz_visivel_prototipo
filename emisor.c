#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <wiringPi.h>

#define PERIOD 100
#define LED_PIN 3

void send_byte(char b);
bool *convert(int n);

int main() {

  wiringPiSetup();

  pinMode(LED_PIN, OUTPUT);

  char *msg = "Hello";

  int msg_length = strlen(msg);

  digitalWrite(LED_PIN, HIGH);
  delay(5000);
  printf("EMISSOR\n");
  while (TRUE) {
    // START CODE
    digitalWrite(LED_PIN, LOW);

    // SEND BYTES
    for (int i = 0; i < msg_length; i++) {
      send_byte(msg[i]);
    }

    // STOP CODE
    digitalWrite(LED_PIN, HIGH);
    delay(2000);
  }

  return 0;
}

void send_byte(char b) {
  bool *byte = convert((int)b);

  for (int i = 0; i < 8; i++) {
    printf("%i", *(byte + i));
    digitalWrite(LED_PIN, *(byte + i));
    delay(PERIOD);
  }
  printf("\n");
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
