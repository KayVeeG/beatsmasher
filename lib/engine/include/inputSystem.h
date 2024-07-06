#ifndef _SMASH_INPUT_H
#define _SMASH_INPUT_H

#include <map>
#include <string>

namespace smash
{
    class InputSystem
    {
        std::map<std::string, bool> m_keys;
    public:
        void setKey(const std::string& key, bool value);
        bool getKey(const std::string& key) const;
    };
};

#endif