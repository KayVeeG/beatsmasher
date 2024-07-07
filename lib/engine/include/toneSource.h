#ifndef _SMASH_TONE_SOURCE_H
#define _SMASH_TONE_SOURCE_H

#include "component.h"
#include <string>

namespace smash
{
    class ToneSource : public Component
    {
        note_t m_note;
        int m_octave;
        float m_duration;
        int m_speakerIndex;
        double m_expandedDuration = -1;
    public:
        ToneSource() : Component(100) {}
        ~ToneSource() = default;

        void setNote(note_t note);
        void setOctave(int octave);
        void setDuration(float duration);
        void setSpeakerIndex(int speakerIndex);

        note_t getNote() const;
        int getOctave() const;
        float getDuration() const;
        int getSpeakerIndex() const;

        void play();
        void abort();

        void update(double deltaTime) override;

        std::string getTypeName() const override;
    };
}

#endif
