#include "pico/stdlib.h"
#include "hardware/gpio.h"
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
  gpio_put(LED_VERDE, 0);

  gpio_init(LED_VERMELHO);
  gpio_set_dir(LED_VERMELHO, GPIO_OUT);
  gpio_put(LED_VERMELHO, 0);

  int estado_led_verde = 0;
  int estado_led_vermelho = 0;

  while (true) {
    if (!gpio_get(BTN_VERDE)) {
      estado_led_verde = !estado_led_verde;
      gpio_put(LED_VERDE, estado_led_verde);
            
      while (!gpio_get(BTN_VERDE)) {
        tight_loop_contents();
      }

    }

    if (!gpio_get(BTN_VERMELHO)) {
      estado_led_vermelho = !estado_led_vermelho;
      gpio_put(LED_VERMELHO, estado_led_vermelho);
      
      while (!gpio_get(BTN_VERMELHO)) {
          tight_loop_contents();
      }
    }

  tight_loop_contents();
  }
}