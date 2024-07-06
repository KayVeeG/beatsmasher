#include <smash.h>
#include <Arduino.h>

namespace smash
{
    void Runtime::initialize()
    {
        
    }
    void Runtime::shutdown()
    {

    }

    void Runtime::addInputDevice(std::shared_ptr<InputDevice> device)
    {
        m_inputDevices.push_back(device);
    }

    void Runtime::removeInputDevice(std::shared_ptr<InputDevice> device)
    {
        for (auto it = m_inputDevices.begin(); it != m_inputDevices.end(); ++it)
        {
            if (*it == device)
            {
                m_inputDevices.erase(it);
                break;
            }
        }
    }

    void Runtime::addScene(std::shared_ptr<Scene> scene)
    {
        m_scenes.push_back(scene);
    }

    void Runtime::removeScene(std::shared_ptr<Scene> scene)
    {
        for (auto it = m_scenes.begin(); it != m_scenes.end(); ++it)
        {
            if (*it == scene)
            {
                m_scenes.erase(it);
                break;
            }
        }
    }

    void Runtime::setActiveScene(std::shared_ptr<Scene> scene)
    {
        m_currentScene = scene.get();
    }

    void Runtime::queueExit()
    {
        m_exitQueued = true;
    }

    bool Runtime::getExitQueued() const
    {
        return m_exitQueued;
    }

    Scene* Runtime::getActiveScene()
    {
        return m_currentScene;
    }

    void Runtime::update()
    {
        g_inputSystem = &m_inputSystem;

        uint64_t currentTime = esp_timer_get_time();
        if (deltaTime >= 0.0)
        {
            for (auto& device : m_inputDevices)
            {
                device->provideInput(m_inputSystem);
            }

            if (m_currentScene)
            {
                m_currentScene->update(deltaTime);
                if (m_display)
                {
                    m_currentScene->render(*m_display);
                    m_display->swapFrameBuffers();
                }
            }
            
        }
        
        deltaTime = (double)(esp_timer_get_time() - currentTime) / 1000000.0;
    }

    void Runtime::setDisplay(std::shared_ptr<Display> display)
    {
        m_display = display;
    }

}