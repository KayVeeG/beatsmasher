#ifndef _NOTE_BLOCK_LOGIC_CPP
#define _NOTE_BLOCK_LOGIC_CPP

#include <smash.h>

class NoteBlockLogic : public smash::BehaviourScript
{
    bool m_TonePlaySent = false;
public:
    static constexpr float s_fallSpeed = 10.0f;

    NoteBlockLogic() = default;
    ~NoteBlockLogic() = default;

    void update(double deltaTime) override
    {
        // get transform
        auto transform = static_cast<smash::Transform*>(getComponent("Transform"));
        if (transform)
        {
            // move the note block
            transform->translate(smash::Vector2::right() * s_fallSpeed * (float)deltaTime);

            // check for falling out of the screen
            if (transform->getPosition().x + transform->getScale().x >= 64)
            {
                // Get tone source
                auto toneSource = static_cast<smash::ToneSource*>(getComponent("ToneSource"));
                if (toneSource && !m_TonePlaySent)
                {
                    // play the note
                    toneSource->play();
                    m_TonePlaySent = true;
                }
            }
        }
    }

    std::string getTypeName() const override
    {
        return "NoteBlockLogic";
    }

};

#endif