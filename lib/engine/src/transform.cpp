#include <smash.h>

namespace smash
{
    void Transform::translate(Vector2 translation)
    {
        m_position += translation;
    }

    void Transform::setPosition(Vector2 position)
    {
        m_position = position;
    }

    Vector2 Transform::getPosition() const
    {
        return m_position;
    }

    Vector2& Transform::getPositionRef()
    {
        return m_position;
    }

    void Transform::setScale(Vector2 scale)
    {
        m_scale = scale;
    }

    Vector2 Transform::getScale() const
    {
        return m_scale;
    }

    Vector2& Transform::getScaleRef()
    {
        return m_scale;
    }

}