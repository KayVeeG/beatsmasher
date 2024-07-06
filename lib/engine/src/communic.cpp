#include "communic.h"

namespace smash
{
    const std::string _COM_SEPARATOR = "|";
    const std::string _COM_SPEAKER = "_COM_SPEAKER" + _COM_SEPARATOR;
    
    const std::string _COM_INDEX(int index)
    {
        return std::to_string(index) + _COM_SEPARATOR;
    }

    const std::string _COM_NOTE_T(note_t note)
    {
        return std::to_string(note) + _COM_SEPARATOR;
    }

    const std::string _COM_OCTAVE(int value)
    {
        return std::to_string(value) + _COM_SEPARATOR;
    }

    const std::string _COM_SPEAKER_COMMAND(int index, note_t note, int octave)
    {
        return _COM_SPEAKER + _COM_INDEX(index) + _COM_NOTE_T(note) + _COM_OCTAVE(octave);
    }
}
