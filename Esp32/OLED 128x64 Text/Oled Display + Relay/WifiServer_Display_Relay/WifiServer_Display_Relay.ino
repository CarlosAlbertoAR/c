#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Mapeamento de portas 
int rele = 23;

// Constantes da rede Wifi
const char *ssid = "Carlos&Thais";
const char *password = "*170789080588#";

// Objeto do servidor e porta
//WiFiServer server(80) ;

//Setup inicial
void setup() {
  Serial.begin(115200);    //Inializa a poorta serial em 115200
  Serial.println('Iniciando Setup');  
  pinMode(rele, OUTPUT);   //Configura saída para relé 1

  Serial.println('Configurando Display');    
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  Serial.println('Display apagado');

  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("CATO TECNOLOGIA");
  delay(2000);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Conectando a rede");
  display.setCursor(0, 20);    
  display.println(ssid);  
  WiFi.begin(ssid, password); //Conecta a rede Wifi

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(741);
    display.setCursor(0, 40);    
    display.println('.'); // Mostra pontos até realizar a conexão 
  }

  display.setCursor(0, 20);
  display.println("Wifi Conectado");
  display.setCursor(0, 40);  
  display.println("IP:");
  display.setCursor(0, 60);  
  //display.println(WiFi.localIP);  

 //server.begin(); //Inializa o servidor
  
}

void loop() {
  //Serial.println('Iniciando o loop');  
  
  while(WiFi.status() != WL_CONNECTED)  //Reconecta em caso de perda da conexão
  {WiFi.begin(ssid, password);
    delay(741);
    display.setCursor(0, 40);    
    display.println('.'); // Mostra pontos até realizar a conexão 
  }

  relay_wifi();
  
  /*
  digitalWrite(rele, HIGH);
  display.setCursor(0, 20);  
  display.println("Rele ligado");
  display.display(); 
  delay(5000);    

  digitalWrite(rele, LOW);
  display.setCursor(0, 20);
  display.println("Rele desligado");
  display.display(); 
  delay(5000);    
  */
}

// Funções
void relay_wifi()
{
/*
WiFiClient client = server.available(); //Verifica se existe algum cliente conectado com dados a serem transmitidos

  if(client) // Existe um cliente?
  {
    display.setCursor(0, 40);    
    display.println("Novo Cliente Definido");
    String currentLine = "";  //String que vai armazenar mensagem do cliente

    while(client.connected()) //Repete enquanto o cliente estiver conectado
    {
      if(client.available()) //Existem dados a serem lidos?
      {
        char c=client.read();
        display.setCursor(0, 40);    
        display.println(c);

        if (c=='\n') //Caracter de nova linha?
        {
          if(currentLine.length()==0)  // A mensagem terminou?
          {
            //Gera a página HTML
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.println("<h2>Clique <a href=\"/H1\">AQUI</a> para ligar o rele1.</h2><br>");
            client.println("<h2>Clique <a href=\"/L1\">AQUI</a> para desligar o rele1.</h2><br>");
            client.println();
            break; //Encerra o laço
          }
          else currentLine=""; // Senão, impede string de ficar com espaços em branco
        }
        else if(c != '\r') currentLine += c; //Adicionamos o caractere como PARTE DA MENSAGEM, SE DIFERENTE

        //Verifica para ligar ou desligar os relés
        if(currentLine.endsWith("GET /H1")) digitalWrite(rele, HIGH); 
        if(currentLine.endsWith("GET /L1")) digitalWrite(rele, LOW);         
      }
    }

    client.stop();
    display.setCursor(0, 40);    
    display.println("Cliente desconectado.");
  }
*/   
}
