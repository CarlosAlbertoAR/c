/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-motion-sensor-led
 */

#define MOTION_SENSOR_PIN  2  // ESP32 pin GIOP2 connected to the OUTPUT pin of motion sensor

int motionStateCurrent  = LOW; // current  state of motion sensor's pin
int motionStatePrevious = LOW; // previous state of motion sensor's pin

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(MOTION_SENSOR_PIN, INPUT); // set ESP32 pin to input mode
}

void loop() {
  motionStatePrevious = motionStateCurrent;             // store old state
  motionStateCurrent  = digitalRead(MOTION_SENSOR_PIN); // read new state

  if (motionStatePrevious == LOW && motionStateCurrent == HIGH) { // pin state change: LOW -> HIGH
    Serial.println("Motion detected!");
  } else if (motionStateCurrent == LOW) { // pin state change: HIGH -> LOW
    Serial.println("No motion!");
  }

  delay(2000);
}