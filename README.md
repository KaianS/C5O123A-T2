# Temporizador One Shot

Este projeto implementa um sistema de temporização acionado por botão, utilizando a função `add_alarm_in_ms()` do Pico SDK.

## 🚀 Requisitos

- Raspberry Pi Pico W
- 3 LEDs (azul, vermelho e verde)
- 3 resistores de 330 Ω
- 1 botão (pushbutton)
- Ferramenta Educacional BitDogLab
- Simulador Wokwi

## 📌 Funcionalidades

- O botão liga os três LEDs simultaneamente.
- A cada 3 segundos, um LED é desligado até restar apenas um.
- O botão só pode ser acionado novamente após todos os LEDs apagarem.
- A mudança de estado dos LEDs ocorre nas funções de call-back do temporizador.
- Teste adicional com LED RGB nos GPIOs 11, 12 e 13 e botão A no GPIO 05 via BitDogLab.

## 🔧 Configuração e Execução

1. Instale o **Pico SDK** e configure o ambiente no **VS Code**.
2. Clone este repositório:
   ```sh
   git clone https://github.com/KaianS/C5O123A-T2.git
   cd C5O123A-T2
3. Compile e execute o projeto