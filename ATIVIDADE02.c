/*
 * Temporizador One Shot
 * Autor: [Seu Nome] | Data: 04/02/2025
 * Descrição: Aciona LEDs via botão, desligando-os sequencialmente a cada 3s usando add_alarm_in_ms().
 */


#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define LED_AZUL 11
#define LED_VERMELHO 12
#define LED_VERDE 13
#define BOTAO 5

volatile bool estado_leds = false;

// Função de callback para desligar os LEDs em sequência
static int64_t callback_desligar_leds(alarm_id_t id, void *user_data) {
    static int seq = 0;
    switch (seq)
    {
    case 0:
        gpio_put(LED_AZUL, 0);
        seq++;
        add_alarm_in_ms(3000, callback_desligar_leds, NULL, false);
        break;
    case 1:
        gpio_put(LED_VERMELHO, 0);
        seq++;
        add_alarm_in_ms(3000, callback_desligar_leds, NULL, false);
        break;
    case 2:
        gpio_put(LED_VERDE, 0);
        estado_leds = false;
        seq = 0;
        break;
    }  
    return 0;
}

// Função de callback acionada pelo botão
void callback_botao(uint gpio, uint32_t events) {
    if (!estado_leds) {
        estado_leds = true;
        gpio_put(LED_AZUL, 1);
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_VERDE, 1);
        add_alarm_in_ms(3000, callback_desligar_leds, NULL, false);
    }
}

int main(void) {
    stdio_init_all();

    // Inicialização dos pinos dos LEDs
    int leds[] = {LED_AZUL, LED_VERMELHO, LED_VERDE};
    for (int i = 0; i < 3; i++) {
        gpio_init(leds[i]);
        gpio_set_dir(leds[i], GPIO_OUT);
    }

    // Configuração do pino do botão
    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);

    // Configuração da interrupção para o botão
    gpio_set_irq_enabled_with_callback(BOTAO, GPIO_IRQ_EDGE_FALL, true, callback_botao);
 
    // Loop principal com breve atraso 
    while (true) {
        sleep_ms(100);
    }
    
    return 0;
}
