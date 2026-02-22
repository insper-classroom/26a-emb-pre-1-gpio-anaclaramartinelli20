#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdio.h>

// Definição dos pinos
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

  bool status_verde = false;
  bool status_vermelho = false;

  while (true) {
      // Lógica para o LED Verde
      if (!gpio_get(BTN_VERDE)) {
          status_verde = !status_verde; // Inverte o estado lógico
          gpio_put(LED_VERDE, status_verde);
          
          // Espera soltar o botão para não inverter várias vezes seguidas
          while (!gpio_get(BTN_VERDE)) {
              tight_loop_contents();
          }
          sleep_ms(50); 
      }

      // Lógica para o LED Vermelho
      if (!gpio_get(BTN_VERMELHO)) {
          status_vermelho = !status_vermelho; // Inverte o estado lógico
          gpio_put(LED_VERMELHO, status_vermelho);
          
          // Espera soltar o botão
          while (!gpio_get(BTN_VERMELHO)) {
              tight_loop_contents();
          }
          sleep_ms(50); 
      }

      tight_loop_contents();
  }
}