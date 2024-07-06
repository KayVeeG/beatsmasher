#ifndef _SMASH_TRANSFORM_H
#define _SMASH_TRANSFORM_H

#include "component.h"
#include "vector2.h"

namespace smash
{
    class Transform : public Component
    {
        Vector2 m_position;
        Vector2 m_scale;
    public:

        Transform() = default;
        Transform(float x, float y) : m_position(x, y), m_scale(1.0f, 1.0f) {}
        Transform(Vector2 position) : m_position(position), m_scale(1.0f, 1.0f) {}
        Transform(float x, float y, float xScale, float yScale) : m_position(x, y), m_scale(xScale, yScale) {}
        Transform(Vector2 position, Vector2 scale) : m_position(position), m_scale(scale) {};
        ~Transform() = default;

        void translate(Vector2 translation);

        void setPosition(Vector2 position);
        Vector2 getPosition() const;
        Vector2& getPositionRef();

        void setScale(Vector2 scale);
        Vector2 getScale() const;
        Vector2& getScaleRef();

        std::string getTypeName() const override { return "Transform"; }

    };
}

#endif