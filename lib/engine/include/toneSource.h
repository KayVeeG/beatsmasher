#ifndef _SMASH_TONE_SOURCE_H
#define _SMASH_TONE_SOURCE_H

#include "component.h"
#include <string>

namespace smash
{
        class ToneSource : public Component
    {
    private:
        note_t m_note;
        int m_octave;
        float m_duration;

    public:
        ToneSource() = default;
        ~ToneSource() = default;

        void setNote(note_t note);
        void setOctave(int octave);
        void setDuration(float duration);

        note_t getNote() const;
        int getOctave() const;
        float getDuration() const;

        void play(int speakerIndex);
        void abort(int speakerIndex);

        std::string getTypeName() const override;
    };
}

#endif
