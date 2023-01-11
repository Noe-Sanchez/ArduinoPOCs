/*
By: Daniel Salinas
Contact: danielnsalinass@gmail.com
*/

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "AnotherIFTTTWebhook.h"
#include "secrets.h"

// Set IFTTT Webhooks event name and key
#define IFTTT_Event "water"


int counter = 0;

void setup() {
  //pinMode(A0, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.begin(SSIDD, PASSS);

  // Connecting to WiFi...
  Serial.print("Connecting to ");
  Serial.print(SSIDD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }

  // Connected to WiFi
  Serial.println();
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(A0);
  Serial.println(x);  
  if(x < 50){
    //tone(7, 1000);
    digitalWrite(LED_BUILTIN,HIGH);
    counter = 0;
  }else{
    if(counter  == 10){
       digitalWrite(LED_BUILTIN,LOW);
       Serial.println("Proc");
       send_webhook(IFTTT_Event,APIKEY,"Front door","HIGH","Webhook");
    }
      
   counter++;
  }
      
  delay(1000);
}
