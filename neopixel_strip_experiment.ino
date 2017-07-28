
#include <ESP8266WiFi.h>
#include <Adafruit_NeoPixel.h>

#define NEOPIN D6
#define NEOPIXEL_LENGTH 14
#define BRIGHTNESS 255 // set max brightness (0-255)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NEOPIXEL_LENGTH, NEOPIN, NEO_GRB + NEO_KHZ800); // strip object
byte pixels[NEOPIXEL_LENGTH * 3];
unsigned int offset;

void setup() {
  Serial.begin(115200);
  
  pinMode(NEOPIN, OUTPUT);
  strip.begin();
  strip.show();
  strip.setBrightness(BRIGHTNESS);

  pinMode(D7, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(D7))
    offset = offset + 1;
  
  for(int i=0; i < NEOPIXEL_LENGTH * 3; i++) {
    pixels[(i + (offset * 3)) % (NEOPIXEL_LENGTH * 3)] = (i % 5) > 0 ? 255 : 0;
  }
  
  for (int i=0; i < NEOPIXEL_LENGTH; i++) {
    strip.setPixelColor(i, strip.Color(pixels[i*3], pixels[(i*3)+1], pixels[(i*3)+2]));
  }
  strip.show();
  delay(500);
}
