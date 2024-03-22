#include <Arduino.h>

#define DebounceFilter 200

#define button01 4
#define button02 5

#define relay01 25
#define relay02 26

unsigned long startTimeButton01;
unsigned long timeButton01;

unsigned long startTimeButton02;
unsigned long timeButton02;

bool stateButton01;
bool stateBeforeButton01;
bool stateRelay01;

bool stateButton02;
bool stateBeforeButton02;
bool stateRelay02;

void setup() {
  pinMode(button01, INPUT_PULLUP);
  pinMode(button02, INPUT_PULLUP);
  pinMode(relay01, OUTPUT);
  pinMode(relay02, OUTPUT);

  stateRelay01 = false;
  stateRelay02 = false;  

  startTimeButton01 = 0; 
  startTimeButton02 = 0;   

  Serial.begin(115200);
  Serial.println("Setup OK");
}

void loop() {

  stateButton01 = !digitalRead(button01);
  stateButton02 = !digitalRead(button02);  

  //Ao apertar o botão
  if (stateButton01 && !stateBeforeButton01){
    if (startTimeButton01 == 0) {
      startTimeButton01 = millis();
    }
  }

  //Ao soltar o botão
  if (startTimeButton01 > DebounceFilter) {
    if (!stateButton01 && stateBeforeButton01) {
      timeButton01 = millis() - startTimeButton01;
      startTimeButton01 = 0;
      digitalWrite(relay01, LOW);
    }
  }

  //Comando 1
  if ((timeButton01 > 0) && (timeButton01 < 1000)) {
    timeButton01 = 0;

    if (stateRelay01) {
      digitalWrite(relay01, LOW);
      stateRelay01 = false;      
      Serial.println("Relay 01 OFF");
    }  
    else if (stateRelay02) {
      digitalWrite(relay02, LOW);
      stateRelay02 = false;      
      Serial.println("Relay 02 OFF");
    }  
    else {
      digitalWrite(relay01, HIGH);
      stateRelay01 = true;      
      Serial.println("Relay 01 ON");
    }
  }
  
  //Comando 2
  if (timeButton01 > 1000) {
    timeButton01 = 0;

    if (!stateRelay02) {
      digitalWrite(relay02, HIGH);
      stateRelay02 = true;      
      Serial.println("Relay 02 ON");
  }  
  }

  stateBeforeButton01 = stateButton01;
  stateBeforeButton02 = stateButton02;  
  delay(20);
}