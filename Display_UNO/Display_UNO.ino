#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>

#include <Adafruit_GFX.h>         // Core graphics library
#include <Adafruit_ILI9341.h>     // Hardware-specific library
#include <SdFat.h>                // SD card & FAT filesystem library
#include <Adafruit_SPIFlash.h>    // SPI / QSPI flash library
#include <Adafruit_ImageReader.h> // Image-reading functions

// Comment out the next line to load from SPI/QSPI flash instead of SD card:
#define USE_SD_CARD

// TFT display and SD card share the hardware SPI interface, using
// 'select' pins for each to identify the active device on the bus.

//PIN CONNECTIONS AS OF 2/18
//LCD_PIN - COLOR - UNO_PIN
//GND     - BLACK - GND
//VIN     - RED   - 5V
//D/C     - GREY  - 9
//RESET   - NO CONNECTION
//SD CS   - GREEN - 8
//LCD CS  - BROWN - 10
//MOSI    - YELLOW- 11
//MISO    - WHITE - 12
//SCK     - OLIVE - 13

#define SD_CS   8 // SD card select pin
#define TFT_CS 10 // TFT select pin
#define TFT_DC  9 // TFT display/command pin

#if defined(USE_SD_CARD)
  SdFat                SD;         // SD card filesystem
  Adafruit_ImageReader reader(SD); // Image-reader object, pass in SD filesys

#endif

Adafruit_ILI9341     tft    = Adafruit_ILI9341(TFT_CS, TFT_DC);
Adafruit_Image       img;        // An image loaded into RAM

void setup(void) {
  Serial.begin(9600);
#if !defined(ESP32)
  while(!Serial);       // Wait for Serial Monitor before continuing
#endif

  tft.begin();          // Initialize screen

  Serial.print(F("Initializing filesystem..."));
#if defined(USE_SD_CARD)
  // SD card is pretty straightforward, a single call...
  if(!SD.begin(SD_CS, SD_SCK_MHZ(25))) { // ESP32 requires 25 MHz limit
    Serial.println(F("SD begin() failed"));
    for(;;); // Fatal error, do not continue
  }

#endif

  // Fill screen black. Not a required step, this just shows that we're
  // successfully communicating with the screen.
  tft.fillScreen(ILI9341_BLACK);

  Serial.print(F("Loading logos.bmp to screen..."));
  reader.drawBMP("/logos.bmp", tft, 0, 0);

  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
 Serial.print(F("Loading logos.bmp to screen..."));
 reader.drawBMP("/logos.bmp", tft, 0, 0);

 //delay(6000);
 //tft.fillScreen(ILI9341_BLACK);
 
// exit(1);
}
