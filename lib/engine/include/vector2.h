#ifndef VECTOR2_H
#define VECTOR2_H

#include <string>

namespace smash
{
    class Vector2 {
    public:
        float x;
        float y;

        // Constructors
        Vector2();
        Vector2(float x, float y);

        // Operations
        Vector2 operator+(const Vector2& other) const;
        Vector2 operator-(const Vector2& other) const;
        Vector2 operator*(float scalar) const;
        Vector2 operator/(float scalar) const;
        Vector2& operator+=(const Vector2& other);
        Vector2& operator-=(const Vector2& other);
        Vector2& operator*=(float scalar);
        Vector2& operator/=(float scalar);
        bool operator==(const Vector2& other) const;
        bool operator!=(const Vector2& other) const;

        // Utility functions
        float magnitude() const;
        float sqrMagnitude() const;
        Vector2 normalized() const;
        void normalize();
        float dot(const Vector2& other) const;
        float cross(const Vector2& other) const;
        float distance(const Vector2& other) const;
        float angle(const Vector2& other) const;
        Vector2 rotate(float angle) const;
        Vector2 lerp(const Vector2& other, float t) const;
        std::string toString() const;

        // Static utility functions
        static Vector2 zero();
        static Vector2 one();
        static Vector2 up();
        static Vector2 down();
        static Vector2 left();
        static Vector2 right();
    };
}

#endif // VECTOR2_H