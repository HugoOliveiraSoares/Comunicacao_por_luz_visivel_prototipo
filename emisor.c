#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <wiringPi.h>

#define PERIOD 100
#define LED_PIN 4

void send_byte(char b);

int main() {

  wiringPiSetup();

  pinMode(LED_PIN, OUTPUT);

  char *msg = "Hello World";

  int16_t msg_length = strlen(msg);

  while (TRUE) {
    for (int16_t i = 0; i < msg_length; i++) {
      send_byte(msg[i]);
    }
    delay(1000);
  }

  return 0;
}

void send_byte(char b) {

  digitalWrite(LED_PIN, LOW);
  delay(PERIOD);

  // transmission of bits
  for (int16_t i = 0; i < 8; i++) {
    printf("%i", (b & (0x01 << i)) != 0);
    digitalWrite(LED_PIN, (b & (0x01 << i)) != 0);
    delay(PERIOD);
  }
  printf("\n");

  digitalWrite(LED_PIN, HIGH);
  delay(PERIOD);
}
