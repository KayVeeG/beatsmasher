

#include "gameRuntime.cpp"

GameRuntime gameRuntime;

void setup()
{
    gameRuntime.initialize();
}

void loop()
{
    while (!gameRuntime.getExitQueued())
    {
        gameRuntime.update();
    }
}

/*
#include <Arduino.h>

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    Serial.println("Hello from Master!");
    delay(1000);
}*/