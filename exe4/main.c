#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_VERMELHO = 28;

const int LED_VERMELHO = 5;
const int LED_ROXO = 6;
const int LED_AZUL = 11;
const int LED_AMARELO = 15;

int main() {
  stdio_init_all();

  gpio_init(BTN_VERMELHO);
  gpio_set_dir(BTN_VERMELHO, GPIO_IN);
  gpio_pull_up(BTN_VERMELHO);

  gpio_init(LED_VERMELHO);
  gpio_set_dir(LED_VERMELHO, GPIO_OUT); 

  gpio_init(LED_ROXO);
  gpio_set_dir(LED_ROXO, GPIO_OUT);

  gpio_init(LED_AZUL);
  gpio_set_dir(LED_AZUL, GPIO_OUT);
  
  gpio_init(LED_AMARELO);
  gpio_set_dir(LED_AMARELO, GPIO_OUT);

  while (true) {
    // Use delay de 300 ms entre os estados!
    gpio_put(LED_VERMELHO, 1);
    sleep_ms(300);
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_ROXO, 1);
    sleep_ms(300);
    gpio_put(LED_ROXO, 0);
    gpio_put(LED_AZUL, 1);
    sleep_ms(300);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_AMARELO, 1);
    sleep_ms(300);
    gpio_put(LED_AMARELO, 0);
  }
}
