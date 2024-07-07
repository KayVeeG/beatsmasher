#include <smash.h>

namespace smash
{
    Speaker::Speaker(int index, int pin) : m_index(index), m_pin(pin), m_channel(0)
    {
        ledcAttachPin(m_pin, m_channel);
    }

    int Speaker::getIndex() const
    {
        return m_index;
    }

    void Speaker::playNote(note_t note, int octave)
    {
        ledcWriteNote(m_channel, note, octave);
    }

    void Speaker::stopNote()
    {
        ledcWriteTone(m_channel, 0);
    }
}