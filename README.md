# Atividade Arduino da cadeira de Robótica Inclusiva

Este repositório contém o código-fonte de uma **Série de Efeitos** interativa construída com Arduino Uno. O projeto foi desenvolvido para explorar e consolidar conceitos fundamentais de eletrônica digital e programação embarcada, incluindo **Modulação por Largura de Pulso (PWM)**, leitura de sinais analógicos e manipulação de arrays.

## Funcionalidades

O código implementa uma máquina de estados controlada via **Monitor Serial**, permitindo a alternância em tempo real entre 5 projetos distintos:

1. **Efeito Dímer (PWM):** Controle escalonado da potência média fornecida a um LED usando `analogWrite()` com diferentes Duty Cycles (0% a 100%).
2. **Mapeamento Analógico:** Leitura de um potenciômetro (0-1023) e conversão via função `map()` para saída PWM (0-255).
3. **Sequencial KITT:** Efeito de iluminação sequencial bidirecional (vai e vem) utilizando um array de 10 LEDs com tempo de transição fixo.
4. **Sequencial Interativo:** Evolução do efeito KITT, onde a velocidade da transição das luzes é controlada dinamicamente em tempo real através de um potenciômetro.
5. **Jogo LED Chase (Corrida de Luz):** Um mini-jogo de reflexo. Um LED percorre a barra rapidamente. O jogador deve pressionar um botão exatamente quando o LED central acender. Inclui feedback visual de vitória (pisca o centro) ou derrota (pisca todos).

## Hardware Necessário

Para reproduzir este projeto, você precisará dos seguintes componentes:

* 1x Placa Arduino Uno (ou compatível)
* 10x LEDs (de preferência da mesma cor para a barra sequencial)
* 10x Resistores (ex: 220Ω ou 330Ω) para os LEDs
* 1x Potenciômetro (ex: 10kΩ)
* 1x Push Button (Botão tátil)
* Jumpers e Protoboard

### Esquema de Pinos
* **LEDs Sequência:** Pinos Digitais `4` ao `13`
* **LED PWM (Projetos 1 e 2):** Pino Digital `3` (PWM)
* **Botão:** Pino Digital `2` (Configurado com `INPUT_PULLUP`)
* **Potenciômetro:** Pino Analógico `A0`

## 🚀 Como Executar

1. Monte o circuito na protoboard seguindo o esquema de pinos acima.
2. Clone este repositório:
   ```bash
   git clone [https://github.com/Jhon-Victor-Ramos/atividade-arduino-com-efeitos.git](https://github.com/Jhon-Victor-Ramos/atividade-arduino-com-efeitos.git)
   ```
3. Abra o arquivo `.ino` na Arduino IDE.
4. Conecte sua placa via USB e faça o upload do código.
5. Abra o Monitor Serial (configure a taxa de transmissão para `9600 baud` — para isso, utilzia-se o comando: `Serial.begin(9600);`).
6. Digite um número de 1 a 5 e pressione Enter para iniciar o projeto correspondente.

## Tecnologias e Conceitos Aplicados
- C++ (Arduino Core)
- Arrays e Laços de Repetição (`for`, `while`)
- Estruturas de Controle (`switch case`, máquina de estados)
- Comunicação Serial (`Serial.read()`, Tabela ASCII)
- Sinais Digitais e Analógicos (`digitalWrite`, `analogRead`, `analogWrite`)
- Pull-up Interno (`INPUT_PULLUP`)
