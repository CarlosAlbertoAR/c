/*
https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-sensor-detector-de-fogo-chama-infravermelho
*/

const int pinoSensor = 2; //PINO DIGITAL UTILIZADO PELO SENSOR

void setup(){
  pinMode(pinoSensor, INPUT); //DEFINE O PINO COMO ENTRADA
  Serial.begin(9600);
}

void loop(){
  if(digitalRead(pinoSensor) == LOW){ //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
      Serial.println("Fogo detectado!");
  delay(2000)  ;
  }
}