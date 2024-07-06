#include <smash.h>
#include <cmath>
#include <sstream>
#include <iomanip>

namespace smash
{

    // Constructors
    Vector2::Vector2() : x(0), y(0) {}
    Vector2::Vector2(float x, float y) : x(x), y(y) {}

    // Operations
    Vector2 Vector2::operator+(const Vector2& other) const { return Vector2(x + other.x, y + other.y); }
    Vector2 Vector2::operator-(const Vector2& other) const { return Vector2(x - other.x, y - other.y); }
    Vector2 Vector2::operator*(float scalar) const { return Vector2(x * scalar, y * scalar); }
    Vector2 Vector2::operator/(float scalar) const { return Vector2(x / scalar, y / scalar); }

    Vector2& Vector2::operator+=(const Vector2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2& Vector2::operator-=(const Vector2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2& Vector2::operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2& Vector2::operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    bool Vector2::operator==(const Vector2& other) const {
        return (x == other.x) && (y == other.y);
    }

    bool Vector2::operator!=(const Vector2& other) const {
        return !(*this == other);
    }

    // Utility functions
    float Vector2::magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    float Vector2::sqrMagnitude() const {
        return x * x + y * y;
    }

    Vector2 Vector2::normalized() const {
        float mag = magnitude();
        if (mag == 0) return Vector2(0, 0);
        return Vector2(x / mag, y / mag);
    }

    void Vector2::normalize() {
        float mag = magnitude();
        if (mag != 0) {
            x /= mag;
            y /= mag;
        }
    }

    float Vector2::dot(const Vector2& other) const {
        return x * other.x + y * other.y;
    }

    float Vector2::cross(const Vector2& other) const {
        return x * other.y - y * other.x;
    }

    float Vector2::distance(const Vector2& other) const {
        return (*this - other).magnitude();
    }

    float Vector2::angle(const Vector2& other) const {
        return std::atan2(cross(other), dot(other));
    }

    Vector2 Vector2::rotate(float angle) const {
        float cs = std::cos(angle);
        float sn = std::sin(angle);
        return Vector2(x * cs - y * sn, x * sn + y * cs);
    }

    Vector2 Vector2::lerp(const Vector2& other, float t) const {
        return *this + (other - *this) * t;
    }

    std::string Vector2::toString() const {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << "(" << x << ", " << y << ")";
        return oss.str();
    }

    // Static utility functions
    Vector2 Vector2::zero() { return Vector2(0, 0); }
    Vector2 Vector2::one() { return Vector2(1, 1); }
    Vector2 Vector2::up() { return Vector2(0, 1); }
    Vector2 Vector2::down() { return Vector2(0, -1); }
    Vector2 Vector2::left() { return Vector2(-1, 0); }
    Vector2 Vector2::right() { return Vector2(1, 0); }

}

