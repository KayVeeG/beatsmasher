#ifndef _NOTE_BLOCK_CPP
#define _NOTE_BLOCK_CPP

#include <smash.h>
#include "../shaders/dynamicRectFrag.cpp"
#include "../scripts/noteBlockLogic.cpp"

class NoteBlock : public smash::GameObject
{
public:
    NoteBlock(int buttonIndex, note_t note, int octave, float duration)
    {
        // Init transform
        auto transform = std::make_shared<smash::Transform>(0.0f, (float)buttonIndex * 4.0f, duration * NoteBlockLogic::s_fallSpeed, 4.0f);

        // Init shader renderer
        auto shaderRenderer = std::make_shared<smash::ShaderRenderer>();

        // Init shaders
        auto baseShader = std::make_shared<DynamicRectFragment>();

        // Init shader attributes
        auto shaderAttributes = std::make_shared<smash::ShaderAttributes>();
        shaderAttributes->setPointer("p_Position", &transform->getPositionRef());
        shaderAttributes->setPointer("p_Scale", &transform->getScaleRef());

        // Add shader attributes and shaders
        shaderRenderer->setShaderAttributes(shaderAttributes);
        shaderRenderer->getShaderProgram().addShader(baseShader);

        // Init note block logic
        auto noteBlockLogic = std::make_shared<NoteBlockLogic>();

        // Init tone source
        auto toneSource = std::make_shared<smash::ToneSource>();
        toneSource->setNote(note);
        toneSource->setOctave(octave);
        toneSource->setDuration(duration);
        toneSource->setSpeakerIndex(buttonIndex);

        // Add components
        addComponent(transform);
        addComponent(shaderRenderer);
        addComponent(noteBlockLogic);
        addComponent(toneSource);
    }
    ~NoteBlock() = default;
};

#endif