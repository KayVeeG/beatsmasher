
#include <smash.h>

namespace smash
{
    void ToneSource::setNote(note_t note)
    {
        m_note = note;
    }

    void ToneSource::setOctave(int octave)
    {
        m_octave = octave;
    }

    void ToneSource::setDuration(float duration)
    {
        m_duration = duration;
    }

    note_t ToneSource::getNote() const
    {
        return m_note;
    }

    int ToneSource::getOctave() const
    {
        return m_octave;
    }

    float ToneSource::getDuration() const
    {
        return m_duration;
    }

    void ToneSource::play(int speakerIndex)
    {
        g_slaveCom.println(_COM_SPEAKER_COMMAND(speakerIndex, m_note, m_octave).c_str());
        Serial.println(_COM_SPEAKER_COMMAND(speakerIndex, m_note, m_octave).c_str());
    }

    void ToneSource::abort(int speakerIndex)
    {
        //g_toneProvider->stop(speakerIndex);
    }
    std::string ToneSource::getTypeName() const
    {
        return "ToneSource";
    }
}
