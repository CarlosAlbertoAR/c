/* RF 433/315 module
*  Install library rc-switch by sui77 
* https://randomnerdtutorials.com/rf-433mhz-transmitter-receiver-module-with-arduino/
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int oldvalue;
int value;

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(2);
}

void loop() {
  if (mySwitch.available()) {
    value = mySwitch.getReceivedValue();

      if (value == 0) {
        Serial.println("Codigo desconhecido");
      } else {
        Serial.print("Recebido: ");
        Serial.print(mySwitch.getReceivedValue());
        Serial.print(" / ");
        Serial.print(mySwitch.getReceivedBitlength());
        Serial.print("bit ");
        Serial.print("Protocolo: ");
        Serial.println(mySwitch.getReceivedProtocol());
      }
      mySwitch.resetAvailable();
  }
}
