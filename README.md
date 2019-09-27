# Botón con Arduino
Aprende a utilizar un botón como interruptor con Arduino.

### Requisitos
- Tener el IDE de [Arduino](https://www.arduino.cc/en/Main/Software) (o el de tu preferencia) con la versión más actual
- Tener el material para hacer el proyecto

### Código
**[Aqui](https://github.com/proyectoTEOS/Boton-con-Arduino/blob/master/Boton-con-Arduino.ino)** podrás obtener el link del código, también dejaremos
una vista previa aquí abajo.

```c++
/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  WEB https://www.proyecto-teos.com
*/

const int buttonPinT = 2;
volatile uint16_t ISRcounterT = 0;
uint16_t counterT = 0;
unsigned long previousMillisT = 0;
String resultSerialT;

void setup() {
  pinMode(buttonPinT, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(buttonPinT), debounceISRT, FALLING);
}

void loop() {
  if (counterT != ISRcounterT) {
    resultSerialT = "El botón se presionó, estado";
    resultSerialT += (counterT % 2 == 0) ? " bajo." : " alto.";
    Serial.println(resultSerialT);
    counterT = ISRcounterT;
  }
}

void debounceISRT() {
  unsigned long currentMillisT = millis();
  if ((unsigned long)(currentMillisT - previousMillisT >= 150)) {
    ISRcounterT++;
    previousMillisT = millis();
  }
}
```

### Diagrama
El siguiente esquemático muestra como se debe conectar todos los componentes con la placa.
![](https://github.com/proyectoTEOS/Boton-con-Arduino/blob/master/Boton-con-Arduino.jpg)
