#include <Arduino.h>
#include <SPI.h>
#include "Adafruit_TLC5947.h"
#include "Cube.h"
#include "Animations.h"

// How many boards do you have chained?
#define NUM_TLC5947 2
#define data 4
#define clock 17
#define latch 2 // 6
#define oe -1   // set to -1 to not use the enable pin (its optional)

#define NUM_X_COL 4
#define NUM_Y_LAYER 4
#define NUM_Z_COL 4

Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5947, clock, data, latch);

SPIClass mySPI(HSPI);

Cube myCube(4, 4, 4, &tlc, &mySPI);

Animations myAnimations(&myCube);

void setup()
{
  mySPI.begin(HSPI_CLK, HSPI_MISO, HSPI_MOSI, HSPI_CS);
  pinMode(HSPI_CS, OUTPUT);

  tlc.begin();
  if (oe >= 0)
  {
    pinMode(oe, OUTPUT);
    digitalWrite(oe, LOW);
  }

  myCube.setLayer(0, RED);
  myCube.setLayer(1, GREEN);
  myCube.setLayer(2, BLUE);
  myCube.setLayer(3, WHITE);
}

void loop()
{
  myAnimations.animationController();
}