#ifndef _SPEAKER_H
#define _SPEAKER_H

#include <Arduino.h>

namespace smash
{
    class Speaker
    {
        int m_index;
        int m_pin;
        int m_channel;
    public:
        Speaker(int index, int pin);
        ~Speaker() = default;

        int getIndex() const;

        virtual void playNote(note_t note, int octave);
        virtual void stopNote();
    };
}

#endif