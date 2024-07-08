#include <smash.h>

namespace smash
{
    std::vector<int> Speaker::s_availableChannels =  {0, 1, 2, 3, 4, 5, 6, 7,8, 9, 10, 11, 12, 13, 14, 15};

    int Speaker::makeAvailableChannel()
    {
        int channel = s_availableChannels.back();
        s_availableChannels.pop_back();
        Serial.println("Making channel available: " + String(channel));
        return channel;
    }

    Speaker::Speaker(int index, int pin) : m_index(index), m_pin(pin), m_channel(makeAvailableChannel())
    {
        ledcSetup(m_channel, 5000, 8);
        ledcAttachPin(m_pin, m_channel);
    }

    Speaker::~Speaker()
    {
        ledcDetachPin(m_pin);
        s_availableChannels.push_back(m_channel);
    }

    int Speaker::getIndex() const
    {
        return m_index;
    }

    void Speaker::playNote(note_t note, int octave)
    {
        Serial.println("Playing on channel: " + String(m_channel));
        ledcWriteNote(m_channel, note, octave);
    }

    void Speaker::stopNote()
    {
        ledcWriteTone(m_channel, 0);
    }
}