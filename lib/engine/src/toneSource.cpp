
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

    void ToneSource::setSpeakerIndex(int speakerIndex)
    {
        m_speakerIndex = speakerIndex;
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

    int ToneSource::getSpeakerIndex() const
    {
        return m_speakerIndex;
    }

    void ToneSource::play()
    {
        Communication::_CMD_SPEAKER_NOTE(m_speakerIndex, m_note, m_octave);
        m_expandedDuration = 0;
    }

    void ToneSource::abort()
    {
        Communication::_CMD_SPEAKER_SILENT(m_speakerIndex);
        m_expandedDuration = -1;
    }
    std::string ToneSource::getTypeName() const
    {
        return "ToneSource";
    }

    void ToneSource::update(double deltaTime)
    {
        if (m_expandedDuration >= 0)
        {
            m_expandedDuration += deltaTime;
            if (m_expandedDuration >= m_duration)
            {
                abort();
            }
        }
    }
}
