#pragma once

#include <array>

class Vector2d
{
    public:
        Vector2d() { m_x = 0; m_y = 0; }
        Vector2d(float x, float y) { m_x = x; m_y = y; };
        ~Vector2d() {};
        float operator[](int i) const { return i == 0 ? m_x : m_y; }
        
        Vector2d operator+(const Vector2d& other);
        Vector2d operator-(const Vector2d& other);
        Vector2d operator*(float scalar);
        Vector2d operator/(float scalar);
        float dot(const Vector2d& other);
        float cross(const Vector2d& other);
        
        float magnitude();
        
        Vector2d operator+=(const Vector2d& other);
        Vector2d operator-=(const Vector2d& other);
        Vector2d operator*=(float scalar);
        Vector2d operator/=(float scalar);
        bool operator==(const Vector2d& other);
        bool operator!=(const Vector2d& other);
        
        float& x() { return m_x; }
        float& y() { return m_y; }
        float x() const { return m_x; }
        float y() const { return m_y; }

    private: 
        float m_x;
        float m_y;

};
