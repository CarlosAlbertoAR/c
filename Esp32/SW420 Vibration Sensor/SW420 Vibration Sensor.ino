
#define pinoSensor 2 // pino que o sensor esta conectado
int ctd = 0;
int tempo = 10000;

void setup() {
  pinMode(pinoSensor, INPUT);
  Serial.begin(9600);
}

void loop() {
if(digitalRead(pinoSensor) == LOW)// lê a porta digital 2 e verfica a se o valor é alto
{
  Serial.println("Vibração detectada");
  delay(tempo);
ctd++;
}
else
{
  Serial.println("Sem vibração");
  delay(tempo);
ctd--;
}
Serial.println(ctd);
}
