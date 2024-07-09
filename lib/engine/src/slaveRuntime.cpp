#include <smash.h>

#include <string>
#include <sstream>
#include <vector>

#define MASTER_RX 21
#define MASTER_TX 22

namespace smash
{

    void SlaveRuntime::initialize()
    {
        Serial.begin(115200);
        m_masterSerial = new HardwareSerial(2);
        m_masterSerial->begin(115200, SERIAL_8N1, MASTER_RX, MASTER_TX);
        m_inputSystem.setMasterSerial(m_masterSerial);
        Serial.println("SlaveRuntime initialized!");
    }

    void SlaveRuntime::update()
    {

        if (m_masterSerial && *m_masterSerial)
        {   
            // Process master recieves
            std::vector<String> splitMessage = Communication::decodeMessage(*m_masterSerial);

            // Select the command
            if (splitMessage.size() > 0)
            {
                if (splitMessage[0] == Communication::_COM_SPEAKER_NOTE)
                {
                    int index = splitMessage[1].toInt();
                    note_t note = (note_t)splitMessage[2].toInt();
                    int octave = splitMessage[3].toInt();
                    // Call the speaker note command
                    for (auto speaker : m_speakers)
                    {
                        if (speaker->getIndex() == index)
                        {
                            speaker->playNote(note, octave);
                        }
                    }
                }
                else if (splitMessage[0] == Communication::_COM_SPEAKER_SILENT)
                {
                    int index = splitMessage[1].toInt();
                    // Call the speaker silent command
                    for (auto speaker : m_speakers)
                    {
                        if (speaker->getIndex() == index)
                        {
                            speaker->stopNote();
                        }
                    }
                }
                else if (splitMessage[0] == Communication::_COM_LCD_PRINT)
                {
                    int row = splitMessage[1].toInt();
                    String text = splitMessage[2];
                    text = text.substring(0, text.length() - 1);
                    // Call the lcd print command
                    m_lcdDisplay->printRow(row, text);
                }
            }
            
            // Process master sends
            m_inputSystem.update();
            
        }
        

    }

    void SlaveRuntime::shutdown()
    {
        delete m_masterSerial;
        Serial.println("SlaveRuntime shutdown called!");
    }

    void SlaveRuntime::addSpeaker(std::shared_ptr<Speaker> speaker)
    {
        m_speakers.push_back(speaker);
    }

    void SlaveRuntime::addButton(SlaveButton button)
    {
        m_inputSystem.addButton(button);
    }

    void SlaveRuntime::setLcdDisplay(std::shared_ptr<LcdDisplay> lcdDisplay)
    {
        m_lcdDisplay = lcdDisplay;
    }
}