#include <Arduino.h>
#include <Button.h>

Button b(3);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    if (b.readEdge())
        Serial.println("Edge");
}
