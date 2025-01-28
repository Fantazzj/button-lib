#ifndef Button_h
#define Button_h

#include <Arduino.h>

class Button
{
public:
    Button(int8_t pin, uint32_t snubberT);
    Button(int8_t pin);
    void begin(int8_t mode);
    int8_t getPin();
    uint32_t getSnubberT();
    void setSnubberT(uint32_t snubberT);
    bool readRising();
    bool readFalling();
    bool readEdge();
    bool readLow();
    bool readHigh();

private:
    int8_t _pin;
    bool _oldState;
    uint32_t _prevoiusMillis;
    uint32_t _snubberT;
};

#endif
