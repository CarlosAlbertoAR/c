/* Título: Teste do Sensor T1592
 * Desenvolvido: Curto Circuito
 *
 * https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-sensor-detector-de-chuva
 *
 * VCC na porta digital 2
 * S na porta analógica
 */

/* Pinos correspondentes ao sensor */
#define sensorvcc 4     /*Define vcc como pino 4 */ 
#define sensorsinal 2  /*Define sinal como pino 2 */ 

/* Declara variável inteira para armazenamento dos dados */
int val = 0;

void setup() { 
  pinMode(sensorvcc, OUTPUT);
  digitalWrite(sensorvcc, LOW); /* vcc tem nível lógico baixo até que haja alguma variação na leitura */
  Serial.begin(9600); /* Baudrate de 9600 */
}

void loop() {
  int level = readSensor(); 
  /*printa o nível da água no monitor serial */
  Serial.print("Nível de água: "); 
  Serial.println(level); 
  delay(2000); 
}

/* leitura do sensor */
int readSensor() {  
digitalWrite(sensorvcc, HIGH);  /* alimenta o sensor */
delay(10);                      /* espera 10ms */
val = analogRead(sensorsinal);  /* Realiza a leitura analógica do sinal do sensor */
digitalWrite(sensorvcc, LOW);   /* Desliga o sensor */
return val;                     /* envia leitura */
}