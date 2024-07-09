#include <smash.h>

namespace smash
{

    void Communication::sendMessageToSlave(String message)
    {
        Serial.print(message);
    }

    void Communication::sendMessageToMaster(String message, HardwareSerial& masterSerial)
    {
        masterSerial.print(message);
    }

    const String Communication::_COM_BEGIN = "smash=>";
    const char Communication::_COM_SEPARATOR = '|';
    const char Communication::_COM_END = '\n';
    const String Communication::_COM_SPEAKER_NOTE = "speakerNote";
    const String Communication::_COM_SPEAKER_SILENT = "speakerSilent";
    const String Communication::_COM_BUTTON_CHANGE = "buttonChange";
    const String Communication::_COM_LCD_PRINT = "lcdPrint";
    String Communication::_COM_NUMBER(int number)
    {
        return String(number);
    } 
    void Communication::_CMD_LCD_PRINT(int row, const String& text)
    {
        sendMessageToSlave(_COM_BEGIN + _COM_LCD_PRINT + _COM_SEPARATOR + _COM_NUMBER(row) + _COM_SEPARATOR + text + _COM_END);
    }
    void Communication::_CMD_SPEAKER_NOTE(int index, note_t note, int octave)
    {
        sendMessageToSlave(_COM_BEGIN + _COM_SPEAKER_NOTE + _COM_SEPARATOR + _COM_NUMBER(index) + _COM_SEPARATOR + _COM_NUMBER(note) + _COM_SEPARATOR + _COM_NUMBER(octave) + _COM_END);
    }

    void Communication::_CMD_SPEAKER_SILENT(int index)
    {
        sendMessageToSlave(_COM_BEGIN + _COM_SPEAKER_SILENT + _COM_SEPARATOR + _COM_NUMBER(index) + _COM_END);
    }

    void Communication::_CMD_BUTTON_CHANGE(int index, bool state, HardwareSerial& masterSerial)
    {
        Serial.println(_COM_BEGIN + _COM_BUTTON_CHANGE + _COM_SEPARATOR + _COM_NUMBER(index) + _COM_SEPARATOR + (state ? "1" : "0") + _COM_END);
        sendMessageToMaster(_COM_BEGIN + _COM_BUTTON_CHANGE + _COM_SEPARATOR + _COM_NUMBER(index) + _COM_SEPARATOR + (state ? "1" : "0") + _COM_END, masterSerial);
    }

    std::vector<String> Communication::decodeMessage(HardwareSerial& senderSerial)
    {
        constexpr size_t maxMessageCharCheck = 2000;

        // Receive slave input information
        String message = "";
        bool validMessage = false;
        for (int i = 0; i < maxMessageCharCheck; i++)
        {
            char c = senderSerial.read();
            message += c;
            if (c == Communication::_COM_END)
            {
                break;
            }
            if (message.startsWith(Communication::_COM_BEGIN))
            {
                validMessage = true;
            }
            if (i == maxMessageCharCheck - 1 && !validMessage)
            {
                return std::vector<String>();
            }
        }

        while (!message.startsWith(Communication::_COM_BEGIN))
        {
            if (message.length() <= 0)
            {
                return std::vector<String>();
            }
            message = message.substring(1);
        }
        
        message = message.substring(Communication::_COM_BEGIN.length(), message.length());


        std::vector<String> splitMessage;

        int startIndex = 0;
        int endIndex = 0;

        while (endIndex >= 0) {
            endIndex = message.indexOf('|', startIndex);

            if (endIndex >= 0) {
                splitMessage.push_back(message.substring(startIndex, endIndex));
                startIndex = endIndex + 1;
            } else {
                // Add the last part
                splitMessage.push_back(message.substring(startIndex));
            }
        }

        // Print the split parts
        for (int i = 0; i < splitMessage.size(); i++) {
            senderSerial.println(splitMessage[i]);
        }

        return splitMessage;
    }

}