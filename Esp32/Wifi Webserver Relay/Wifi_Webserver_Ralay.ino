/* ============================================================================
   
   Controle de Relés por WiFi com ESP32

   Vídeo Aula de Engenharia Eletrônica, a Clássica de Sexta!
   Aula número 369

   Compilador: Arduino IDE 1.8.4
   Autor: Eng. Wagner Rambo
   Março de 2021

============================================================================ */


// ============================================================================
// --- Bibliotecas Auxiliares ---
#include <WiFi.h>                         //inclui biblioteca WiFi


// ============================================================================
// --- Mapeamento de Hardware ---
#define   relay1   23                    //pino para controle do relé 1
#define   relay2   22                    //pino para controle do relé 2


// ============================================================================
// --- Constantes Auxialires ---
const char *ssid     = "Carlos&Thais";  //atribuir nome da rede WiFi
const char *password = "*170789080588#"; //atribuir senha da rede


// ============================================================================
// --- Objetos ---
WiFiServer server(80);                    //define a porta que o servidor irá utilizar
                                          //(normalmente utiliza-se a porta padrão 80)

// ============================================================================
// --- Protótipo das Funções ---
void relay_wifi();                       //função para gerar web server e controlar os relés
                                

// ============================================================================
// --- Configurações Iniciais ---
void setup() 
{
  Serial.begin(115200);                  //inicializa Serial em 115200 baud rate
  pinMode(relay1, OUTPUT);               //configura saída para relé 1
  pinMode(relay2, OUTPUT);               //configura saída para relé 2

  Serial.println();                      //
  Serial.print("Conectando-se a ");      //
  Serial.println(ssid);                  //
  WiFi.begin(ssid, password);            //inicializa WiFi, passando o nome da rede e a senha

  while(WiFi.status() != WL_CONNECTED)   //aguarda conexão (WL_CONNECTED é uma constante que indica sucesso na conexão)
  {
    delay(741);                          //
    Serial.print(".");                   //vai imprimindo pontos até realizar a conexão...
  }

  Serial.println("");                    //mostra WiFi conectada
  Serial.println("WiFi conectada");      //
  Serial.println("Endereço de IP: ");    //
  Serial.println(WiFi.localIP());        //mostra o endereço IP

  server.begin();                        //inicializa o servidor web

}


// ============================================================================
// --- Loop Infinito ---
void loop() 
{


  while(WiFi.status() != WL_CONNECTED)   //aguarda conexão (WL_CONNECTED é uma constante que indica sucesso na conexão)
  {
    WiFi.begin(ssid, password);          //inicializa WiFi, passando o nome da rede e a senha
    Serial.print(".");                   //vai imprimindo pontos até realizar a conexão...

    delay(741);                          //741ms
  }
  
  relay_wifi();                                //chama função para controle dos relés por wifi


  
} //end loop


// ============================================================================
// --- relay_wifi ---
void relay_wifi()
{

  WiFiClient client = server.available();      //verifica se existe um cliente conectado com dados a serem transmitidos
  
  if(client)                                   //existe um cliente?
  {                                            //sim
    Serial.println("Novo Cliente Definido");   //informa por serial
    String currentLine = "";                   //string para armazenar a mensagem do cliente
    
    while(client.connected())                  //repete enquanto o cliente estiver conectado
    {
      
      if(client.available())                   //existem dados a serem lidos?
      {                                        //sim
        char c=client.read();                  //salva em c
        Serial.write(c);                       //mostra na Serial
        
        if(c=='\n')                            //é um caractere de nova linha?
        {                                      //sim
          if(currentLine.length()==0)          //a mensagem terminou?
          {                                    //sim
            //gera a página HTML
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.print("<h2>Clique <a href=\"/H1\">AQUI</a> para ligar o rele 1.</h2><br>");
            client.print("<h2>Clique <a href=\"/L1\">AQUI</a> para desligar o rele 1.</h2><br>");
            client.print("<h2>Clique <a href=\"/H2\">AQUI</a> para ligar o rele 2.</h2><br>");
            client.print("<h2>Clique <a href=\"/L2\">AQUI</a> para desligar o rele 2.</h2><br>");
            client.println();
            break;                             //encerra o laço
            
          } //end if currentLine.length
          
          else currentLine="";                 //senão, impede string de ficar com espaços em branco
        
        } //end if c
                  
        else if(c != '\r') currentLine += c;  //adicionamos o caractere como parte da mensagem, se diferene de retorno/nova linha

       //verifica para ligar ou desligar os relés
          if(currentLine.endsWith("GET /H1")) digitalWrite(relay1, HIGH);
          if(currentLine.endsWith("GET /L1")) digitalWrite(relay1,  LOW);
          if(currentLine.endsWith("GET /H2")) digitalWrite(relay2, HIGH);
          if(currentLine.endsWith("GET /L2")) digitalWrite(relay2,  LOW);
          
       
      } //end if client.available()
      
    } //end if while client.connected

    client.stop();                           //finaliza conexão
    Serial.println("Client Disconnected.");
    
  } //end if client  
  
  
} //end relay_wifi









/* ========================================================   
 
                                                              
======================================================== */
/* --- Final do Programa --- */
