#include "vector2d.hh"

Vector2d Vector2d::operator+(const Vector2d& other)
{
    return Vector2d(m_x + other.x(), m_y + other.y());
}

Vector2d Vector2d::operator-(const Vector2d& other)
{
    return Vector2d(m_x - other.x(), m_y - other.y());
}

Vector2d Vector2d::operator*(float scalar)
{
    return Vector2d(m_x * scalar, m_y * scalar);
}

Vector2d Vector2d::operator/(float scalar)
{
    return Vector2d(m_x / scalar, m_y / scalar);
}

float Vector2d::dot(const Vector2d& other)
{
    return m_x * other.x() + m_y * other.y();
}

float Vector2d::cross(const Vector2d& other)
{
    return m_x * other.y() - m_y * other.x();
}

float Vector2d::magnitude()
{
    return sqrt(m_x * m_x + m_y * m_y);
}

Vector2d Vector2d::operator+=(const Vector2d& other)
{
    m_x += other.x();
    m_y += other.y();
    return *this;
}

Vector2d Vector2d::operator-=(const Vector2d& other)
{
    m_x -= other.x();
    m_y -= other.y();
    return *this;
}

Vector2d Vector2d::operator*=(float scalar)
{
    m_x *= scalar;
    m_y *= scalar;
    return *this;
}

Vector2d Vector2d::operator/=(float scalar)
{
    m_x /= scalar;
    m_y /= scalar;
    return *this;
}

bool Vector2d::operator==(const Vector2d& other)
{
    return m_x == other.x() && m_y == other.y();
}

bool Vector2d::operator!=(const Vector2d& other)
{
    return m_x != other.x() || m_y != other.y();
}
