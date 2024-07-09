#ifndef _SMASH_COMMUNICATION_H
#define _SMASH_COMMUNICATION_H

#include <string>
#include <Arduino.h>

namespace smash
{
    class Communication
    {
        static void sendMessageToSlave(String message);
        static void sendMessageToMaster(String message, HardwareSerial& masterSerial);
    public:
        static std::vector<String> decodeMessage(HardwareSerial& senderSerial);
        static const String _COM_BEGIN;
        static const char _COM_SEPARATOR;
        static const char _COM_END;
        static const String _COM_SPEAKER_NOTE;
        static const String _COM_SPEAKER_SILENT;
        static const String _COM_BUTTON_CHANGE;
        static const String _COM_LCD_PRINT;
        static String _COM_NUMBER(int number);
        static void _CMD_LCD_PRINT(int row, const String& text);
        static void _CMD_SPEAKER_NOTE(int index, note_t note, int octave);
        static void _CMD_SPEAKER_SILENT(int index);
        static void _CMD_BUTTON_CHANGE(int index, bool state, HardwareSerial& masterSerial);
    };
}

#endif