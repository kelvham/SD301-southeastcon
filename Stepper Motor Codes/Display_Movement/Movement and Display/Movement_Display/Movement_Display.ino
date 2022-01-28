#include <Adafruit_GFX.h>         // Core graphics library
#include <Adafruit_ILI9341.h>     // Hardware-specific library
#include <SdFat.h>                // SD card & FAT filesystem library
#include <Adafruit_SPIFlash.h>    // SPI / QSPI flash library
#include <Adafruit_ImageReader.h> // Image-reading functions
#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

// Comment out the next line to load from SPI/QSPI flash instead of SD card:
#define USE_SD_CARD

// TFT display and SD card share the hardware SPI interface, using
// 'select' pins for each to identify the active device on the bus.

#define SD_CS   6 // SD card select pin
#define TFT_CS 5 // TFT select pin
#define TFT_DC  7 // TFT display/command pin

#if defined(USE_SD_CARD)
  SdFat                SD;         // SD card filesystem
  Adafruit_ImageReader reader(SD); // Image-reader object, pass in SD filesys
//I TOOK OUT UNNECESSARY CODE HERE. -MEL
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
//I TOOK OUT UNNECESSARY CODE HERE. -MEL
#endif
//  Serial.println(F("OK!"));

  // Fill screen blue. Not a required step, this just shows that we're
  // successfully communicating with the screen.
  tft.fillScreen(ILI9341_BLACK);

  Serial.print(F("Loading logos.bmp to screen..."));
  reader.drawBMP("/logos.bmp", tft, 0, 0);

    // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);

      // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(stepsPerRevolution/4);

  delay(2000); // Pause 2 seconds before moving on to loop()
}

void loop() {
 Serial.print(F("Loading logos.bmp to screen..."));
 reader.drawBMP("/logos.bmp", tft, 0, 0);

 delay(6000);
     // step one revolution in the other direction:
 Serial.println("clockwise");
 myStepper.step(-stepsPerRevolution/4);

 delay(2000);
 tft.fillScreen(ILI9341_BLACK);
 
 exit(1);
}
