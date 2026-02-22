#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_PIN = 26;
const int BTN_PIN_2 = 7;

int main() {
    stdio_init_all();

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    gpio_init(BTN_PIN_2);
    gpio_set_dir(BTN_PIN_2, GPIO_IN);
    gpio_pull_up(BTN_PIN_2);

    int cnt_1 = 0;
    int cnt_2 = 0;

    int state_btn_1 = 0;
    int state_btn_2 = 0;

    while (true) {
    
        if (!gpio_get(BTN_PIN) && state_btn_1 == 0) {
            sleep_ms(15); // Filtra o ruído ao apertar
            if (!gpio_get(BTN_PIN)) { 
                state_btn_1 = 1;
                cnt_1++;
                printf("Botao 1: %d\n", cnt_1); 
            }
        } 
        else if (gpio_get(BTN_PIN) && state_btn_1 == 1) {
            sleep_ms(15); // Filtra o ruído ao soltar
            if (gpio_get(BTN_PIN)) { 
                state_btn_1 = 0; 
            }
        }

        if (!gpio_get(BTN_PIN_2) && state_btn_2 == 0) {
            sleep_ms(15);
            if (!gpio_get(BTN_PIN_2)) {
                state_btn_2 = 1;
                cnt_2++;
                printf("Botao 2: %d\n", cnt_2); 
            }
        } 
        else if (gpio_get(BTN_PIN_2) && state_btn_2 == 1) {
            sleep_ms(15);
            if (gpio_get(BTN_PIN_2)) {
                state_btn_2 = 0;
            }
        }
    }
}