
#include <Arduino.h>
#include <smash.h>

HardwareSerial SerialPort(2);

void setup()
{
    Serial.begin(115200);
    SerialPort.begin(115200, SERIAL_8N1, 32, 33);
}

void loop()
{
    Serial.println("INSIDE LOOP");
    if (SerialPort.available())
    {
        Serial.println("Data available");
        String receivedData = SerialPort.readStringUntil('\n');
        Serial.print("Received from master: ");
        Serial.println(receivedData);
    }
}