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
