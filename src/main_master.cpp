

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
#include <smash.h>

void setup()
{
    Serial.begin(115200);
    smash::Communication::_CMD_LCD_PRINT(0, "Hello World");
}

void loop()
{
}



*/
