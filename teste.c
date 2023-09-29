#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define LED_PIN 4

void send_byte(char b);
bool *convert(int n);

int main() {
  char msg[5] = "Hello";

  for (int i = 0; i < 5; i++) {
    send_byte(msg[i]);
  }
  printf("\n");

  return 0;
}

void send_byte(char b) {
  bool *byte = convert((int)b);

  for (int i = 0; i < 8; i++) {
    printf("%i", *(byte + i));
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
