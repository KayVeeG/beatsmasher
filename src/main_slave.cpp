
#include "circuitRuntime.cpp"

CircuitRuntime circuitRuntime;

void setup()
{
    circuitRuntime.initialize();
}

void loop()
{
    while (!circuitRuntime.getExitQueued())
    {
        circuitRuntime.update();
    }
}


/*
#define MASTER_RX 21
#define MASTER_TX 22

#include <Arduino.h>
HardwareSerial MasterCommunic(2);

void setup()
{
    Serial.begin(115200);
    MasterCommunic.begin(115200, SERIAL_8N1, MASTER_RX, MASTER_TX);
}

void loop()
{
    if (MasterCommunic)
    {
        String message = MasterCommunic.readStringUntil('\n');
        Serial.print("Message from Master: ");
        Serial.println(message);
    }
}
*/




/*
#define SPEAKER_PIN 26
#include <smash.h>

smash::Speaker *speaker = nullptr;

void setup()
{
    speaker = new smash::Speaker(0, SPEAKER_PIN);
}

void loop()
{
    if (speaker->getIndex() == 0)
    {
        speaker->playNote(NOTE_C, 4);
        delay(1000);
        speaker->stopNote();
        delay(1000);
    }
}*/

/*
#include <smash.h>

HardwareSerial MasterCommunic(2);
smash::SlaveInputSystem slaveInputSystem(MasterCommunic);

void setup()
{
    Serial.begin(115200);
    MasterCommunic.begin(115200, SERIAL_8N1, 21, 22);
    slaveInputSystem.addButton(smash::SlaveButton(36, 0));
}

void loop()
{
    slaveInputSystem.update();
}
*/
/*
#include <Arduino.h>

void setup()
{
    Serial.begin(115200);
    pinMode(36, INPUT);
}

void loop()
{
    Serial.println(digitalRead(36));
}*/
/*

#define I2C_SDA 27
#define I2C_SCL 14

#include <Wire.h>
#include <LiquidCrystal_I2C.h>


// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Wire.begin(I2C_SDA, I2C_SCL);
    lcd.init();
    lcd.backlight();
    lcd.print("Hello, World!");
    lcd.setCursor(0, 1);
    lcd.print("Hello, Will :3");
}

void loop() {
  // Your code here
}*/
/*
#include <smash.h>

void setup()
{
    smash::LcdDisplay display(0x27, 27, 14);
    display.printRow(0, "Hello, Karl!");
    display.printRow(1, "Hello, Will :3");
}

void loop()
{

}*/
/*
#include <Arduino.h>

#define SPEAKER_0 12
#define SPEAKER_1 13
#define SPEAKER_2 19
#define SPEAKER_3 18
#define SPEAKER_4 5
#define SPEAKER_5 23

void setup()
{
    ledcSetup(0, 5000, 8);
    ledcAttachPin(SPEAKER_0, 0);
    ledcSetup(1, 5000, 8);
    ledcAttachPin(SPEAKER_1, 1);
    ledcSetup(2, 5000, 8);
    ledcAttachPin(SPEAKER_2, 2);
    ledcSetup(3, 5000, 8);
    ledcAttachPin(SPEAKER_3, 3);
    ledcSetup(4, 5000, 8);
    ledcAttachPin(SPEAKER_4, 4);
    ledcSetup(5, 5000, 8);
    ledcAttachPin(SPEAKER_5, 5);
}

void loop()
{
    ledcWriteNote(0, NOTE_C, 4);
    delay(1000);
    ledcWriteTone(0, 0);
    ledcWriteNote(1, NOTE_E, 4);
    delay(1000);
    ledcWriteTone(1, 0);
    ledcWriteNote(2, NOTE_G, 4);
    delay(1000);
    ledcWriteTone(2, 0);
    ledcWriteNote(3, NOTE_C, 5);
    delay(1000);
    ledcWriteTone(3, 0);
    ledcWriteNote(4, NOTE_E, 5);
    delay(1000);
    ledcWriteTone(4, 0);
    ledcWriteNote(5, NOTE_G, 5);
    delay(1000);
    ledcWriteTone(5, 0);
    delay(1000);
}
*/