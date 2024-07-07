#ifndef _MASTER_RUNTIME_H
#define _MASTER_RUNTIME_H

#include "runtime.h"
#include "scene.h"
#include "display.h"
#include "inputSystem.h"
#include <vector>
#include <memory>

namespace smash
{
    class MasterRuntime : public Runtime
    {
        InputSystem m_inputSystem;
        std::vector<std::shared_ptr<Scene>> m_scenes;
        Scene* m_activeScene = nullptr;
        std::shared_ptr<Display> m_display;
        double m_deltaTime = -1;
        void provideSlaveInputs();
    public:
        MasterRuntime() = default;
        virtual ~MasterRuntime() = default;

        virtual void update() override;

        void setDisplay(std::shared_ptr<Display> display);
        std::shared_ptr<Display> getDisplay() const;

        void addScene(std::shared_ptr<Scene> scene);
        void removeScene(std::shared_ptr<Scene> scene);

        void setActiveScene(Scene* scene);
        Scene* getActiveScene() const;

    };
}
#endif