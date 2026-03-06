#define LED 3
#define TIME 750
#define LEDS_QUANTITY 10

int leds[LEDS_QUANTITY] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
bool estado[LEDS_QUANTITY];
int button = 2;

int projetoAtual = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  for (int i = 0; i < LEDS_QUANTITY; i++) {
    pinMode(leds[i], OUTPUT);
    estado[i] = false;
  }

  Serial.println("Digite um numero (1 a 5) para escolher o projeto:");
}

void loop() {
  if (Serial.available() > 0) {
    char entrada = Serial.read();
    
    if (entrada >= '1' && entrada <= '5') {
      projetoAtual = entrada - '0';
    }
  }

  switch (projetoAtual) {
    case 1:
      projeto1();
      break;
    case 2:
      projeto2();
      break;
    case 3:
      projeto3();
      break;
    case 4:
      projeto4();
      break;
    case 5:
      projeto5();
      break;
  }
}

void projeto1() {
  analogWrite(LED, 0);
  delay(TIME);
  analogWrite(LED, 64);
  delay(TIME);
  analogWrite(LED, 127);
  delay(TIME);
  analogWrite(LED, 192);
  delay(TIME);
  analogWrite(LED, 255);
  delay(TIME * 1.5);
}

void projeto2() {
  /*
  - O pino central do Potenciometro conectado ao pino analogico 0...
  - laterais do potenciometro conectados no terra e 5V.
  - LED conectado no pino digital 9 e no terra.
  Criado em 29/12/2008, Modificado em 09/04/2012 por Tom Igoe
  Este exemplo e de dominio publico.
  */

  
  const int analogInPin = A0; 
  const int analogOutPin = 3; 
  int sensorValue = 0;        
  int outputValue = 0;        

  
  sensorValue = analogRead(analogInPin);

  
  outputValue = map(sensorValue, 0, 1023, 0, 255);

  
  analogWrite(analogOutPin, sensorValue);

  
  Serial.print("sensor = " );
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  
  delay(2);
}

void projeto3() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(leds[i], HIGH);
    if (i > 0) digitalWrite(leds[i-1], HIGH);
    delay(80);
    if (i > 1) digitalWrite(leds[i-2], LOW);
  }

  for (int i = 9; i >= 0; i--) {
    digitalWrite(leds[i], HIGH);
    if (i < 9) digitalWrite(leds[i+1], HIGH);
    delay(80);
    if (i < 8) digitalWrite(leds[i+2], LOW);
  }
  digitalWrite(leds[0], LOW);
  digitalWrite(leds[1], LOW);
}

void projeto4() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(leds[i], HIGH);
    if (i > 0) digitalWrite(leds[i-1], HIGH);
    delay(analogRead(A0));
    if (i > 1) digitalWrite(leds[i-2], LOW);
  }

  for (int i = 9; i >= 0; i--) {
    digitalWrite(leds[i], HIGH);
    if (i < 9) digitalWrite(leds[i+1], HIGH);
    delay(analogRead(A0));
    if (i < 8) digitalWrite(leds[i+2], LOW);
  }
}

void projeto5() {
  percorreLeds();
}

void percorreLeds() {
  for (int i = 0; i < 9; i++) {
    digitalWrite(leds[i], HIGH);
    estado[i] = true;
    if ((!digitalRead(button)) && estado[4]) {
      Serial.println("Comemora fi");
      meioAcendeTresVezes();
    } else if ((!digitalRead(button)) && !estado[4]) {
      Serial.println("Senta e chora");
      todosPiscamDuasVezes();
    }
    delay(analogRead(A0));
    digitalWrite(leds[i], LOW);
    estado[i] = false;
  }

  for (int i = 8; i >= 0; i--) {
    digitalWrite(leds[i], HIGH);
    estado[i] = true;
    if ((!digitalRead(button)) && estado[4]) {
      Serial.println("Comemora fi");
      meioAcendeTresVezes();
    } else if ((!digitalRead(button)) && !estado[4]) {
      Serial.println("Senta e chora");
      todosPiscamDuasVezes();
    }
    delay(analogRead(A0));
    digitalWrite(leds[i], LOW);
    estado[i] = false;
  }
}

void meioAcendeTresVezes() {
  for (int j = 0; j < 3; j++) {
    digitalWrite(leds[4], LOW);
    delay(analogRead(A0));
    digitalWrite(leds[4], HIGH);
    delay(analogRead(A0));
  }
}

void todosPiscamDuasVezes() {
  for (int j = 0; j < 2; j++) {
    for (int k = 0; k < 9; k++) {
      digitalWrite(leds[k], LOW);
    }
    delay(analogRead(A0));
    for (int k = 0; k < 9; k++) {
      digitalWrite(leds[k], HIGH);
    }
    delay(analogRead(A0));
  }
  for (int k = 0; k < 9; k++) {
    digitalWrite(leds[k], LOW);
  }
}