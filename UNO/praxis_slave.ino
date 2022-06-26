#include <Wire.h>

void setup() {
  Wire.begin(8);
  Serial.begin(9600);
  Serial.println("Slave online");
}

void loop() {
  String c = String(Wire.read());
  if(c == "H"){ 
    digitalWrite(LED_BUILTIN, HIGH);
    }else{ 
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(500);
}
