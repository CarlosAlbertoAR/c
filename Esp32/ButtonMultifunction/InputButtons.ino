#include <EEPROM.h>

#define ultimaPorta 39
#define EEPROM_SIZE 64

byte porta;

void setup() {

  Serial.begin(9600);
  while (!Serial) {
  }

  if (!EEPROM.begin(EEPROM_SIZE))
  {
    Serial.println("failed to initialise EEPROM"); delay(1000000);
  }

  porta = EEPROM.read(0);
  porta++;
  if (porta > ultimaPorta) {
     porta = 0; 
  }

  EEPROM.write(0, porta);
  EEPROM.commit();

  Serial.println();
  Serial.print("Testando Porta ");
  Serial.println(porta);

  //pinMode(porta, INPUT);
  pinMode(porta, INPUT_PULLUP);  //para testar INPUT_PULLUP
}

void loop() {

  //if (!digitalRead(porta)) {   //para testar INPUT_PULLUP
  if (digitalRead(porta)) {
     Serial.print(".");
  }
  delay(50);
}
