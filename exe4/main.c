#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

// Definição dos pinos
const int BTN_VERMELHO = 28;

const int LED_VERMELHO = 5;
const int LED_ROXO = 8;
const int LED_AZUL = 11;
const int LED_VERDE = 15; 
int main() {
  stdio_init_all();

  // Inicialização do Botão
  gpio_init(BTN_VERMELHO);
  gpio_set_dir(BTN_VERMELHO, GPIO_IN);
  gpio_pull_up(BTN_VERMELHO);

  // Inicialização dos LEDs
  gpio_init(LED_VERMELHO);
  gpio_set_dir(LED_VERMELHO, GPIO_OUT); 

  gpio_init(LED_ROXO);
  gpio_set_dir(LED_ROXO, GPIO_OUT);

  gpio_init(LED_AZUL);
  gpio_set_dir(LED_AZUL, GPIO_OUT);

  gpio_init(LED_VERDE);
  gpio_set_dir(LED_VERDE, GPIO_OUT);

  gpio_put(LED_VERMELHO, 0);
  gpio_put(LED_ROXO, 0);
  gpio_put(LED_AZUL, 0);
  gpio_put(LED_VERDE, 0);

  while (true) {
    // Só executa se o botão for pressionado 
    if (!gpio_get(BTN_VERMELHO)) {
      // Sequência: Vermelho
      gpio_put(LED_VERMELHO, 1);
      sleep_ms(300);
      gpio_put(LED_VERMELHO, 0);

      // Sequência: Roxo
      gpio_put(LED_ROXO, 1);
      sleep_ms(300);
      gpio_put(LED_ROXO, 0);

      // Sequência: Azul
      gpio_put(LED_AZUL, 1);
      sleep_ms(300);
      gpio_put(LED_AZUL, 0);

      // Sequência: Verde
      gpio_put(LED_VERDE, 1);
      sleep_ms(300);
      gpio_put(LED_VERDE, 0);

      // Espera soltar o botão para não repetir a sequência sem querer
      while (!gpio_get(BTN_VERMELHO)) {
        tight_loop_contents();
      }
  }

    tight_loop_contents();
  }
}