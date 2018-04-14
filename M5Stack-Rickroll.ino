/*
 * 
 
  M5Stack Rickroll

  Copyright 2018 tobozo http://github.com/tobozo
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

  TODO: WiFi Beacon spam with lyrics for completeness
 
 *
 */

#include <M5Stack.h>             // https://github.com/m5stack/M5Stack/
#include "M5StackUpdater.h"      // https://github.com/tobozo/M5Stack-SD-Updater
#include "Game_Audio.h"         // http://www.buildlog.net/blog/2018/02/game-audio-for-the-esp32/
#include "rickrollanim.h"
#include "rickrollsound.h"

long count = 0; // Loop count
int iconpointer = 0;
int totalframes = 20;
long duration = 90;
long last = 0;

Game_Audio_Class GameAudio(25,0); 
Game_Audio_Wav_Class rickroll(rickrollwav);

void animloop() {
  long now = millis();
  if(duration + last < now) {
    last = now;
    switch(iconpointer) {
      case 0:  M5.Lcd.drawJpg(rickroll01_jpg, rickroll01_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
      case 1:  M5.Lcd.drawJpg(rickroll02_jpg, rickroll02_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
      case 2:  M5.Lcd.drawJpg(rickroll03_jpg, rickroll03_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
      case 3:  M5.Lcd.drawJpg(rickroll04_jpg, rickroll04_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
      case 4:  M5.Lcd.drawJpg(rickroll05_jpg, rickroll05_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
      case 5:  M5.Lcd.drawJpg(rickroll06_jpg, rickroll06_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
      case 6:  M5.Lcd.drawJpg(rickroll07_jpg, rickroll07_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
      case 7:  M5.Lcd.drawJpg(rickroll08_jpg, rickroll08_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
      case 8:  M5.Lcd.drawJpg(rickroll09_jpg, rickroll09_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
      case 9:  M5.Lcd.drawJpg(rickroll10_jpg, rickroll10_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
      case 10: M5.Lcd.drawJpg(rickroll11_jpg, rickroll11_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
      case 11: M5.Lcd.drawJpg(rickroll12_jpg, rickroll12_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
      case 12: M5.Lcd.drawJpg(rickroll13_jpg, rickroll13_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
      case 13: M5.Lcd.drawJpg(rickroll14_jpg, rickroll14_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
      case 14: M5.Lcd.drawJpg(rickroll15_jpg, rickroll15_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
      case 15: M5.Lcd.drawJpg(rickroll16_jpg, rickroll16_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
      case 16: M5.Lcd.drawJpg(rickroll17_jpg, rickroll17_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
      case 17: M5.Lcd.drawJpg(rickroll18_jpg, rickroll18_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
      case 18: M5.Lcd.drawJpg(rickroll19_jpg, rickroll19_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
      case 19: M5.Lcd.drawJpg(rickroll00_jpg, rickroll00_jpg_len, 106, 36, 128, 128, 0, 0,  JPEG_DIV_NONE); break;
    }
    iconpointer++;
    if(iconpointer>totalframes-1) iconpointer = 0;
  }
}

void setup() {
  Serial.begin(115200); 
  Serial.println("Begin...");
  M5.begin();
  Wire.begin();
  if(digitalRead(BUTTON_A_PIN) == 0) {
    Serial.println("Will Load menu binary");
    updateFromFS(SD,"/menu.bin");
    ESP.restart();
  }
}

void loop() {

  M5.Lcd.setBrightness(100);
  M5.Lcd.fillScreen(BLACK);
  M5.update();

  GameAudio.PlayWav(&rickroll, false, 1.0);
  while(GameAudio.IsPlaying()) { 
    animloop();
    // beaconSpam() ?
  }
  
}


