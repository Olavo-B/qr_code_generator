/*
Sample for TTGO Watch 2020v1
Acknowledging the huge work of  https://github.com/Bodmer/TFT_eSPI
This is an example of load and display JPG images from SPIFFS
Upload suitable images to SPIFFS using the IDE or other method (240x240px at 0,0 for full screen).
*/
#define LILYGO_WATCH_2020_V1              // Using T-Watch2020
#include <LilyGoWatch.h>
#include <TJpg_Decoder.h>
#include "SPIFFS.h"

TFT_eSPI tft = TFT_eSPI();  
TTGOClass *ttgo; //Main watch class, used to access all watch features

const char *name ; // Sequence of filenames for Gallery
bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap)
{
        if ( y >= tft.height() ) return 0; // Stop further decoding as image is running off bottom of screen
        ttgo->tft->pushImage(x, y, w, h, bitmap);     // This function will clip the image block rendering automatically at the TFT boundaries
        return 1;  // Return 1 to decode next block
}
    File directory = SPIFFS.open("/");
    File f;
    int16_t x, y;

void setup() {
    Serial.begin(115200);
    ttgo = TTGOClass::getWatch();
    ttgo->begin();
      if (!SPIFFS.begin()) {
          Serial.println("SPIFFS initialisation failed!");
          while (1) yield(); 
        }
  TJpgDec.setJpgScale(1);
  TJpgDec.setCallback(tft_output);
  ttgo->tft->setRotation(2);
  ttgo->tft->setSwapBytes(true); // We need to swap the colour bytes (endianess)
  ttgo->tft->fillScreen(TFT_BLACK);
  Serial.println("Trying to load images");
}

void loop() {

    ttgo->openBL(); // Backlight 
    Serial.println("Starting up...");
    ttgo->tft->setTextFont(4);
    ttgo->tft->fillScreen(TFT_BLACK);
    ttgo->tft->setCursor(10, 40);
    ttgo->tft->println("Loading !");
    

    Serial.println("DEBUG: here");
    TJpgDec.drawFsJpg(0, 0, "/sumburgh.jpg"); //Uploaded jpg file 240x240px to SPIFFS

    delay(2000);
    appGallery();        
}



void appGallery() {   /// Loops through all jpg in the SPIFFS and display

    File directory = SPIFFS.open("/");
    File f;
    while (f = directory.openNextFile()) {
        String image = f.name();
        const char *s = image.c_str();
        if (strstr(s, ".jpg") != NULL) {       
        Serial.println(image);
        ttgo->tft->fillScreen(TFT_BLACK);
        TJpgDec.drawFsJpg(0, 0, "/"+ image);
    while (!ttgo->getTouch(x, y)) {} // wait until touched, then advance
    while (ttgo->getTouch(x, y)) {}
    }
  }
}