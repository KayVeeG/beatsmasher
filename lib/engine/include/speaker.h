#ifndef _SPEAKER_H
#define _SPEAKER_H

#include <Arduino.h>
#include <vector>

namespace smash
{
    class Speaker
    {
        static std::vector<int> s_availableChannels;
        int m_index;
        int m_pin;
        int m_channel;
        int makeAvailableChannel();
    public:
        Speaker(int index, int pin);
        ~Speaker();

        int getIndex() const;

        virtual void playNote(note_t note, int octave);
        virtual void stopNote();
    };
}

#endif