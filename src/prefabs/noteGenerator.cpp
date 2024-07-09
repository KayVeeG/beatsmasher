#ifndef _TONE_GENERATOR_CPP
#define _TONE_GENERATOR_CPP

#include <smash.h>
#include "../scripts/noteGeneratorLogic.cpp"
class ToneGenerator : public smash::GameObject

{
public:
    ToneGenerator()
    {
        // Add tone generator logic
        addComponent(std::make_shared<NoteGeneratorLogic>());
    }
    ~ToneGenerator() = default;
};

#endif