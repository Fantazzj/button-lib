#include "Edge.h"

Edge::Edge(int pin, unsigned long snubberT) {
    _init(pin, snubberT);
}

Edge::Edge(int pin) {
    _init(pin, 0);
}

void Edge::_init(int pin, unsigned long snubberT) {
    _pin = pin;
    _oldState = digitalRead(_pin);
    _prevoiusMillis = 0;
    _snubberT = snubberT;
}

int Edge::getPin() {
    return _pin;
}

void Edge::inputMode(int mode) {
    pinMode(_pin, mode);
}

unsigned long Edge::getSnubberT() {
    return _snubberT;
}

void Edge::setSnubberT(unsigned long snubberT) {
    _snubberT = snubberT;
}

bool Edge::readRising() {
    int result;
    int newState = digitalRead(_pin);
    if((millis() - _prevoiusMillis >= _snubberT) && (_oldState < newState)) {
        _prevoiusMillis = millis();
        result = true;
    }
    else result = false;
    _oldState = newState;
    return result;
}

bool Edge::readFalling() {
    int result;
    int newState = digitalRead(_pin);
    if((millis() - _prevoiusMillis >= _snubberT) && (_oldState > newState)) {
        _prevoiusMillis = millis();
        result = true;
    }
    else result = false;
    _oldState = newState;
    return result;

}
