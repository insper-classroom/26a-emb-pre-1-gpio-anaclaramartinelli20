#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_VERDE = 26;
const int BTN_VERMELHO = 28;

const int LED_VERDE = 4;
const int LED_VERMELHO = 6;

int main() {
  stdio_init_all();

  gpio_init(BTN_VERDE);
  gpio_set_dir(BTN_VERDE, GPIO_IN);
  gpio_pull_up(BTN_VERDE);

  gpio_init(BTN_VERMELHO);
  gpio_set_dir(BTN_VERMELHO, GPIO_IN);
  gpio_pull_up(BTN_VERMELHO);

  gpio_init(LED_VERDE);
  gpio_set_dir(LED_VERDE, GPIO_OUT);

  gpio_init(LED_VERMELHO);
  gpio_set_dir(LED_VERMELHO, GPIO_OUT);

  while (true) {
    if (!gpio_get(BTN_VERDE)) {
      gpio_put(LED_VERDE, 1);
      while (!gpio_get(BTN_VERDE)) {
      };
      gpio_put(LED_VERDE, 0);
    }

    if (!gpio_get(BTN_VERMELHO)) {
      gpio_put(LED_VERMELHO, 1);
      while (!gpio_get(BTN_VERMELHO)) {
      };
      gpio_put(LED_VERMELHO, 0);
    }
  }
}
