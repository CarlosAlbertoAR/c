int rele = 23;
 
void setup() {
 pinMode(rele, OUTPUT);
}
 
void loop() {
 digitalWrite(rele, HIGH);
 delay(5000);
 digitalWrite(rele, LOW);
 delay(5000);
}
