#ifndef _NOTE_BLOCK_CPP
#define _NOTE_BLOCK_CPP

#include <smash.h>
#include "../shaders/dynamicRectFrag.cpp"
#include "../scripts/noteBlockLogic.cpp"

class NoteBlock : public smash::GameObject
{
public:
    NoteBlock(float timestamp, int buttonIndex, note_t note, int octave, float duration)
    {
        // Init transform
        float timeStampTransform = 0.0f - timestamp * NoteBlockLogic::s_fallSpeed;
        float buttonTransform = 28.0f - (float)buttonIndex * 4.0f;
        auto transform = std::make_shared<smash::Transform>(timeStampTransform, buttonTransform, duration * NoteBlockLogic::s_fallSpeed, 4.0f);

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
        Serial.print("X Position:");
        Serial.println(transform->getPositionRef().x);
        Serial.print("Y Position:");
        Serial.println(transform->getPositionRef().y);
        addComponent(shaderRenderer);
        addComponent(noteBlockLogic);
        addComponent(toneSource);
    }
    ~NoteBlock() = default;
};

#endif