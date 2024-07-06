
#include <smash.h>


namespace smash
{
    std::vector<int> Speaker::s_availableChannels = {0, 1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    int Speaker::getAvailableChannel()
    {
        int channel = s_availableChannels.back();
        s_availableChannels.pop_back();
        return channel;
    }

    Speaker::Speaker(int index, int pin) : m_index(index), m_pin(pin), m_channel(getAvailableChannel())
    {
        ledcAttachPin(m_pin, m_channel);
    }

    void Speaker::play(note_t note, int octave)
    {
        // Set the frequency
        ledcWriteNote(m_channel, note, octave);
    }

    void Speaker::stop()
    {
        // Stop the tone
        ledcWriteTone(m_channel, 0);
    }

    int Speaker::getIndex() const
    {
        return m_index;
    }
}