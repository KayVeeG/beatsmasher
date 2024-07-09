#ifndef _NOTE_BLOCK_LOGIC_CPP
#define _NOTE_BLOCK_LOGIC_CPP

#include <smash.h>
#include <noteGeneratorLogic.h>

class NoteBlockLogic : public smash::BehaviourScript
{
    NoteGeneratorLogic *m_noteGeneratorLogic = nullptr;
    bool m_TonePlaySent = false;
    double m_BeginTimeStamp = -1;
    int m_buttonIndex = -1;
public:
    static constexpr float s_fallSpeed = 10.0f;

    NoteBlockLogic() = default;
    ~NoteBlockLogic() = default;

    void setButtonIndex(int buttonIndex)
    {
        m_buttonIndex = buttonIndex;
    }

    void setGeneratorCallback(NoteGeneratorLogic *noteGeneratorLogic)
    {
        m_noteGeneratorLogic = noteGeneratorLogic;
    }

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
                // get the time stamp
                if (m_BeginTimeStamp < 0)
                {
                    m_BeginTimeStamp = esp_timer_get_time();
                }

                // Get tone source
                auto toneSource = static_cast<smash::ToneSource*>(getComponent("ToneSource"));
                if (toneSource && !m_TonePlaySent)
                {
                    // play the note
                    if (smash::g_inputSystem->getButtonPressed(m_buttonIndex))
                    {
                        float timePassed = (float)(esp_timer_get_time() - m_BeginTimeStamp) / 1000000.0f;
                        toneSource->setDuration(toneSource->getDuration() - timePassed);
                        toneSource->play();
                        m_TonePlaySent = true;
                    }

                }

                else if (smash::g_inputSystem->getButtonReleased(m_buttonIndex))
                {
                    toneSource->abort();
                }
                else
                {
                    smash::g_score += deltaTime;
                }
            }
            // check if not visible
            if (transform->getPosition().x >= 64)
            {
                // destroy the note block
                if (getGameObject())
                {
                    destroy(getGameObject());
                }
                // make next tone through generator
                if (m_noteGeneratorLogic)
                {
                    m_noteGeneratorLogic->generateNextNote();
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