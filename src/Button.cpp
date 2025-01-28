#include "Button.h"

Button::Button(int8_t pin, uint32_t snubberT)
{
    _pin = pin;
    _prevoiusMillis = 0;
    _snubberT = snubberT;
}

Button::Button(int8_t pin)
{
    _pin = pin;
    _prevoiusMillis = 0;
    _snubberT = 0;
}

void Button::begin(int8_t mode)
{
    pinMode(_pin, mode);
    _oldState = digitalRead(_pin);
}

int8_t Button::getPin()
{
    return _pin;
}

uint32_t Button::getSnubberT()
{
    return _snubberT;
}

void Button::setSnubberT(uint32_t snubberT)
{
    _snubberT = snubberT;
}

bool Button::readRising()
{
    int8_t result;
    int8_t newState = digitalRead(_pin);
    if ((millis() - _prevoiusMillis >= _snubberT) && (_oldState < newState))
    {
        _prevoiusMillis = millis();
        result = true;
    }
    else
        result = false;
    _oldState = newState;
    return result;
}

bool Button::readFalling()
{
    int8_t result;
    int8_t newState = digitalRead(_pin);
    if ((millis() - _prevoiusMillis >= _snubberT) && (_oldState > newState))
    {
        _prevoiusMillis = millis();
        result = true;
    }
    else
        result = false;
    _oldState = newState;
    return result;
}

bool Button::readEdge()
{
    int8_t result;
    int8_t newState = digitalRead(_pin);
    if ((millis() - _prevoiusMillis >= _snubberT) && (_oldState != newState))
    {
        _prevoiusMillis = millis();
        result = true;
    }
    else
        result = false;
    _oldState = newState;
    return result;
}

bool Button::readLow()
{
    return digitalRead(_pin) == false;
}

bool Button::readHigh()
{
    return digitalRead(_pin) == true;
}
