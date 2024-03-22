/* Título: Teste do Sensor T1592
 * Desenvolvido: Curto Circuito
 *
 * VCC na porta digital 2
 * S na porta analógica
 */

const int pinoSensor = 2; //PINO DIGITAL UTILIZADO PELO SENSOR

void setup(){
  pinMode(pinoSensor, INPUT); //DEFINE O PINO COMO ENTRADA
  Serial.begin(9600);
}

void loop(){
  if(digitalRead(pinoSensor) == LOW){ //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
      Serial.println("Chuva detectada!");
  delay(2000)  ;
  }
}