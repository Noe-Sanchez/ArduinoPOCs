#include <Adafruit_NeoPixel.h>
#define LED_PIN    D4
#define LED_COUNT 60

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup(){
  strip.begin();
  strip.show();            
  strip.setBrightness(255); 

  Serial.begin(9600);
  Serial.setTimeout(1);
}

void loop() {
  int brr;
  colorWipe(strip.Color(  255, 0,   0));
  while (!Serial.available());
  brr = Serial.readString().toInt();
  strip.setBrightness(brr); 
}

void colorWipe(uint32_t color) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);
  }
  strip.show(); 
}
