#include "Cube.h"

void Cube::clearLED(uint16_t y,
                    uint16_t z,
                    uint16_t x)
{
    _matrix_layers[y][x + z * _z_size].setR(0);
    _matrix_layers[y][x + z * _z_size].setG(0);
    _matrix_layers[y][x + z * _z_size].setB(0);
}

void Cube::setLED(uint16_t x,
                  uint16_t y,
                  uint16_t z,
                  Color c)
{
    _matrix_layers[y][x + z * _z_size].setR(c.r);
    _matrix_layers[y][x + z * _z_size].setG(c.g);
    _matrix_layers[y][x + z * _z_size].setB(c.b);
}

void Cube::tlcSetLED(uint16_t x,
                     uint16_t y,
                     uint16_t z)
{
    uint16_t ledNum = x + z * _z_size;
    _tlc->setLED(ledNum,
                 _matrix_layers[y][ledNum].getR(),
                 _matrix_layers[y][ledNum].getG(),
                 _matrix_layers[y][ledNum].getB());
}

LED Cube::getLED(uint16_t x,
                 uint16_t y,
                 uint16_t z)
{
    return _matrix_layers[y][x + z * _z_size];
}

void Cube::setLayer(uint16_t y,
                    Color c)
{
    for (uint16_t z = 0; z < _z_size; z++)
    {
        for (uint16_t x = 0; x < _x_size; x++)
        {
            setLED(x, y, z, c);
        }
    }
}

void Cube::setColumn(uint16_t x,
                     Color c)
{
    for (uint16_t y = 0; y < _y_size; y++)
    {
        for (uint16_t z = 0; z < _z_size; z++)
        {
            setLED(x, y, z, c);
        }
    }
}

void Cube::setRow(uint16_t z,
                  Color c)
{
    for (uint16_t y = 0; y < _y_size; y++)
    {
        for (uint16_t x = 0; x < _x_size; x++)
        {
            setLED(x, y, z, c);
        }
    }
}

void Cube::lightCube()
{
    for (uint16_t y = 0; y < _y_size; y++)
    {
        for (uint16_t z = 0; z < _z_size; z++)
        {
            for (uint16_t x = 0; x < _x_size; x++)
            {
                setLED(x, y, z, WHITE);
            }
        }
    }
}

void Cube::clearCube()
{
    for (uint16_t y = 0; y < _y_size; y++)
    {
        for (uint16_t z = 0; z < _z_size; z++)
        {
            for (uint16_t x = 0; x < _x_size; x++)
            {
                clearLED(x, y, z);
            }
        }
    }
}

void Cube::renderCube()
{
    for (uint16_t y = 0; y < _y_size; y++)
    {
        digitalWrite(HSPI_CS, LOW);
        _spi->transfer(~(0x01 << y));
        for (uint16_t z = 0; z < _z_size; z++)
        {
            for (uint16_t x = 0; x < _x_size; x++)
            {
                tlcSetLED(x, y, z);
            }
        }
        _tlc->write();
        digitalWrite(HSPI_CS, HIGH);
    }
}