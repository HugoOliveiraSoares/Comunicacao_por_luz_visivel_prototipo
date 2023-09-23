#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <wiringPi.h>

#define PIN 3
#define PERIOD 500

bool get_ldr();

char get_byte();

void print_byte(char my_byte);

int main() {

  wiringPiSetup();

  pinMode(PIN, INPUT);

  bool previous_state;
  bool current_state;

  printf("RECEPTOR\n");
  while (TRUE) {
    current_state = get_ldr();
    if (!current_state && previous_state) {
      print_byte(get_byte());
    }
    previous_state = current_state;
  }

  return 0;
}

bool get_ldr() { return digitalRead(PIN); }

char get_byte() {
  char ret = 0;
  delay(PERIOD * 1.5);
  for (int16_t i = 0; i < 8; i++) {
    ret = ret | get_ldr() << i;
    delay(PERIOD);
  }
  return ret;
}
void print_byte(char my_byte) {
  char buff[2];
  sprintf(buff, "%c", my_byte);
  printf("%s", buff);
}
