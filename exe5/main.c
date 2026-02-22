#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_PIN = 26;
const int BTN_PIN_2 = 7;

int main() {
    stdio_init_all();

    // Configuração Botão 1
    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    // Configuração Botão 2
    gpio_init(BTN_PIN_2);
    gpio_set_dir(BTN_PIN_2, GPIO_IN);
    gpio_pull_up(BTN_PIN_2);

    int cnt_1 = 0;
    int cnt_2 = 0;

    while (true) {
        // Lógica para o Botão 1
        if (!gpio_get(BTN_PIN)) {
            cnt_1++;
            printf("Botao 1: %d\n", cnt_1);
            
            // Debouncing: Espera o botão ser solto
            while (!gpio_get(BTN_PIN)) {
                tight_loop_contents();
            }
            sleep_ms(50); // Pausa para ignorar o ruído mecânico (bouncing)
        }

        // Lógica para o Botão 2
        if (!gpio_get(BTN_PIN_2)) {
            cnt_2++;
            printf("Botao 2: %d\n", cnt_2);
            
            // Debouncing: Espera o botão ser solto
            while (!gpio_get(BTN_PIN_2)) {
                tight_loop_contents();
            }
            sleep_ms(50); // Pausa para ignorar o ruído mecânico
        }

        tight_loop_contents();
    }
    }