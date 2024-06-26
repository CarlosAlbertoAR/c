/* 
Install IRremote library *#
http://www.esp32learning.com/code/esp32-and-infrared-receiver-example.php
*/

#include <IRremote.h>

int RECV_PIN = 13;
 
IRrecv irrecv(RECV_PIN);
 
decode_results results;
 
void setup()
{
Serial.begin(9600);
irrecv.enableIRIn(); 
}
 
void loop()
{
if (irrecv.decode(&results))
{
Serial.println(results.value, HEX);
irrecv.resume();
}
}