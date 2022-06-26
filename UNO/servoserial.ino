/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 28 May 2015
  by Michael C. Miller
  modified 8 Nov 2013
  by Scott Fitzgerald

  http://arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1);
  myservo.attach(D4);  // attaches the servo on GIO2 to the servo object
}

void loop() {
  int pos=0;
  while (!Serial.available());
  pos = Serial.readString().toInt();
  myservo.write(pos); 
  delay(500);
}
