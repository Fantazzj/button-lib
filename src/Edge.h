#ifndef EDGE_h
#define EDGE_h

#include <Arduino.h>

class Edge{
    public:
        Edge(int pin, unsigned long snubberT);
        Edge(int pin);
        int getPin();
        void inputMode(int);
        unsigned long getSnubberT();
        void setSnubberT(unsigned long snubberT);
        bool readRising();
        bool readFalling();

    private:
        int _pin;
        int _oldState;
        unsigned long _prevoiusMillis;
        unsigned long _snubberT;
        void _init(int pin, unsigned long snubberT);
};

#endif
