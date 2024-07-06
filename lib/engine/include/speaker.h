#ifndef _SMASH_SPEAKER_H
#define _SMASH_SPEAKER_H

#include <vector>

namespace smash
{
    class Speaker
    {
        int m_index;
        int m_pin;
        int m_channel;
        int getAvailableChannel();
    public:
        static std::vector<int> s_availableChannels;

        Speaker(int index, int pin);
        ~Speaker() = default;

        void play(note_t note, int octave);
        void stop();
        int getIndex() const; // New method
    };
}

#endif