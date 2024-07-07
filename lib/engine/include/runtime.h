#ifndef _SMASH_RUNTIME_H
#define _SMASH_RUNTIME_H

namespace smash
{
    class Runtime
    {
        bool m_exitQueued = false;
    public:
        Runtime() = default;
        virtual ~Runtime() = default;

        void queueExit() { m_exitQueued = true; }
        bool getExitQueued() const { return m_exitQueued; }

        virtual void initialize() {}
        virtual void update() {}
        virtual void shutdown() {}
    };
}

#endif