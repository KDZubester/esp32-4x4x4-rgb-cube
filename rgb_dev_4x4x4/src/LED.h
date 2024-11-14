#ifndef _LED_H
#define _LED_H

#include <cstdint>

class LED
{
public:
    LED() : _r(0), _g(0), _b(0) {}
    ~LED() = default;

    void setR(uint16_t new_r_value) { _r = new_r_value; }
    void setG(uint16_t new_g_value) { _g = new_g_value; }
    void setB(uint16_t new_b_value) { _b = new_b_value; }

    uint16_t getR() { return _r; }
    uint16_t getG() { return _g; }
    uint16_t getB() { return _b; }

private:
    uint16_t _r;
    uint16_t _g;
    uint16_t _b;
};

#endif