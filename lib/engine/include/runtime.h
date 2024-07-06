#ifndef _smash_runtime_h
#define _smash_runtime_h

#include <smash.h>
#include <vector>
#include <memory>

namespace smash
{
    class Runtime
    {
    private:
        InputSystem m_inputSystem;
        std::vector<std::shared_ptr<InputDevice>> m_inputDevices;
        std::vector<std::shared_ptr<Scene>> m_scenes;
        std::shared_ptr<Display> m_display;
        Scene *m_currentScene = nullptr;
        bool m_exitQueued = false;
        double deltaTime = -1.0;
    public:

        Runtime() = default;
        virtual ~Runtime() = default;
        
        virtual void initialize();
        virtual void shutdown();

        void addInputDevice(std::shared_ptr<InputDevice> device);
        void removeInputDevice(std::shared_ptr<InputDevice> device);

        void addScene(std::shared_ptr<Scene> scene);
        void removeScene(std::shared_ptr<Scene> scene);
        void setActiveScene(std::shared_ptr<Scene> scene);

        void queueExit();
        bool getExitQueued() const;

        void setDisplay(std::shared_ptr<Display> display);

        Scene* getActiveScene();

        void update();

    };
}
#endif