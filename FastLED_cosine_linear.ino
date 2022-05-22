//M5Atom Matrixに書き込むと本体を破損させる可能性があります

#include <FastLED.h>
#define NUM_LEDS 16
#define DATA_PIN 32

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(115200);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

float fact = PI / 180;
int ss;
int bg;
int dd = 20;
int S = 255;
boolean ATOMLITE = true; //M5Atom Liteで動かすと発熱で壊れる可能性があるので回避用。Atom Lite以外の場合はfalseにしてください。

void loop() {
  for (int i = 0; i < 360; i++) {
    if (ss < 2) {
      float rad = fact * i;
      bg = 255 - (127 + (128 * cos(rad)));
      //      Serial.print("C");
    }
    else if (ss < 4)
    {
      int bbg = i * 255 / 360;
      if (i >= 180) bg = (254 - bbg) * 2;
      else bg = bbg * 2;
      //      Serial.print("L");
    }
    else {
      ss = 0;
    }
    for (int p = 0; p < NUM_LEDS; p++) {
      leds[p + ATOMLITE] = CHSV(i * 255 / 360 + p * 8, S, bg);
    }
    Serial.println(bg);
        delay(dd);
    FastLED.show();

  }
  ss ++;
//  dd ++;
//  if (dd>15) dd=0;
}
