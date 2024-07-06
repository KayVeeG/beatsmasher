#ifndef _SMASH_COMMUNIC_H
#define _SMASH_COMMUNIC_H

#include <Arduino.h>
#include <string>

namespace smash
{
    extern const std::string _COM_SEPARATOR;
    extern const std::string _COM_SPEAKER;
    
    const std::string _COM_INDEX(int index);
    const std::string _COM_NOTE_T(note_t note);
    const std::string _COM_OCTAVE(int value);
    const std::string _COM_SPEAKER_COMMAND(int index, note_t note, int octave);
}

#endif
