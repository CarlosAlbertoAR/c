// Brincando com ideias
// Um Botão, Múltiplas Funções no Arduino #ComoProgramar 
// https://www.youtube.com/watch?v=kFwaSB1pHAc



#define pinBotao 6

#define pinLED0 12
#define pinLED1 11
#define pinLED2 10
#define pinLED3 9
#define pinLED9 7

unsigned long tempoInicio = 0;
unsigned long tempoBotao = 0;

bool estadoBotao;
bool estadoBotaoAnt;

void setup() {
  pinMode(pinBotao, INPUT_PULLUP);
  pinMode(pinLED0, OUTPUT);
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  pinMode(pinLED3, OUTPUT);
  pinMode(pinLED9, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  estadoBotao = !digitalRead(pinBotao);

  //Ao apertar o botão
  if (estadoBotao && !estadoBotaoAnt) {
    if (tempoInicio == 0) {
      tempoInicio = millis();

      digitalWrite(pinLED0, LOW);
      digitalWrite(pinLED1, LOW);
      digitalWrite(pinLED2, LOW);
      digitalWrite(pinLED3, LOW);
    }
  }  

  //Ao soltar o botão
  if (tempoInicio > 200) {  //Filtro Debounce
    if (!estadoBotao && estadoBotaoAnt) {
      tempoBotao = millis() - tempoInicio;
      tempoInicio = 0;  
      digitalWrite(pinLED9, LOW);
    }
  }

  //Retorno
  if (tempoInicio > 0) {
     digitalWrite(pinLED9, bitRead(millis(),8)); 
  }

  //Comando 1
  if ((tempoBotao > 0) && (tempoBotao <= 500)) {
     tempoBotao = 0;
     Serial.println("Comando 1 executado");

     digitalWrite(pinLED0, HIGH);
     digitalWrite(pinLED1, LOW);
     digitalWrite(pinLED2, LOW);
     digitalWrite(pinLED3, LOW);
  }

  //Comando 2
  if ((tempoBotao > 500) && (tempoBotao <= 1000)) {
     tempoBotao = 0;
     Serial.println("Comando 2 executado");

     digitalWrite(pinLED0, HIGH);
     digitalWrite(pinLED1, HIGH);
     digitalWrite(pinLED2, LOW);
     digitalWrite(pinLED3, LOW);
  }

  //Comando 3
  if (tempoBotao > 1000) {
     tempoBotao = 0;
     Serial.println("Comando 3 executado");
  
     digitalWrite(pinLED0, HIGH);
     digitalWrite(pinLED1, HIGH);
     digitalWrite(pinLED2, HIGH);
     digitalWrite(pinLED3, LOW);
  }

  estadoBotaoAnt = estadoBotao;
  delay(20);
}
