#ifndef _CUBE_H
#define _CUBE_H

#include <Arduino.h>
#include <vector>
#include <SPI.h>

#include "LED.h"
#include "Adafruit_TLC5947.h"
#include "globals.h"

#define HSPI_MOSI 13
#define HSPI_MISO 12
#define HSPI_CLK 14
#define HSPI_CS 15

class Cube
{
public:
    Cube(uint16_t x,
         uint16_t y,
         uint16_t z,
         Adafruit_TLC5947 *tlc,
         SPIClass *spi) : _x_size(x),
                          _y_size(y),
                          _z_size(z),
                          _matrix_layers(y, std::vector<LED>(x * z)),
                          _tlc(tlc),
                          _spi(spi)
    {
        clearCube();
    }
    ~Cube() {};

    uint16_t getXSize() { return _x_size; }
    uint16_t getYSize() { return _y_size; }
    uint16_t getZSize() { return _z_size; }

    void clearLED(uint16_t x,
                  uint16_t y,
                  uint16_t z);
    void setLED(uint16_t x,
                uint16_t y,
                uint16_t z,
                Color c);
    void tlcSetLED(uint16_t x,
                   uint16_t y,
                   uint16_t z);
    LED getLED(uint16_t x,
               uint16_t y,
               uint16_t z);

    void setLayer(uint16_t y,
                  Color c);
    void setColumn(uint16_t x,
                   Color c);
    void setRow(uint16_t z,
                Color c);
    void lightCube();
    void clearCube();
    void renderCube();

private:
    uint16_t _x_size, _y_size, _z_size;
    std::vector<std::vector<LED>> _matrix_layers;
    Adafruit_TLC5947 *_tlc;
    SPIClass *_spi;
};

#endif