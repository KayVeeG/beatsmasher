#include <smash.h>

namespace smash
{
    
    void MasterRuntime::provideSlaveInputs()
    {
        // Process master recieves
        std::vector<String> splitMessage = Communication::decodeMessage(Serial);

        // Select the command
        if (splitMessage.size() > 0)
        {
            if (splitMessage[0] == Communication::_COM_BUTTON_CHANGE)
            {
                int index = splitMessage[1].toInt();
                bool state = splitMessage[2].toInt();
                // Change button in input system
                m_inputSystem.registerInput(index, state);
            }
        }
    }
    

    void MasterRuntime::update()
    {
        // Get frame start time
        uint64_t currentTime = esp_timer_get_time();

        // Set input system
        g_inputSystem = &m_inputSystem; 

        // Provide slave inputs
        provideSlaveInputs();

        // Check for valid frame with provided delta time
        if (m_deltaTime >= 0)
        {   

            g_deltaTime = m_deltaTime;
            // Check for active scene
            if (m_activeScene)
            {
                // Update scene
                m_activeScene->update(m_deltaTime);

                // Check for display
                if (m_display)
                {
                    // Render active scene
                    m_activeScene->render(*m_display);
                    // Finish frame for display
                    m_display->swapFrameBuffers();
                }
            }
        }

        // Input System after frame
        m_inputSystem.afterFrame();

        // Calculate delta time for next frame
        m_deltaTime = (double)(esp_timer_get_time() - currentTime) / 1000000.0;

    }

    void MasterRuntime::setDisplay(std::shared_ptr<Display> display)
    {
        m_display = display;
    }

    std::shared_ptr<Display> MasterRuntime::getDisplay() const
    {
        return m_display;
    }

    void MasterRuntime::addScene(std::shared_ptr<Scene> scene)
    {
        m_scenes.push_back(scene);
    }

    void MasterRuntime::removeScene(std::shared_ptr<Scene> scene)
    {
        auto it = std::find(m_scenes.begin(), m_scenes.end(), scene);
        if (it != m_scenes.end())
        {
            m_scenes.erase(it);
        }
    }

    void MasterRuntime::setActiveScene(Scene* scene)
    {
        m_activeScene = scene;
    }

    Scene* MasterRuntime::getActiveScene() const
    {
        return m_activeScene;
    }
}