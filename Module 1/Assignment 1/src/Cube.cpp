#include "Cube.h"

#include <cstring>

Cube::Cube(int length, int width, int height, char *color)
    : m_length(length), m_width(width), m_height(height), m_color(nullptr)
{
    setColor(color);
}

int Cube::getLength()
{
    return m_length;
}

int Cube::getWidth()
{
    return m_width;
}

int Cube::getHeight()
{
    return m_height;
}

char *const Cube::getColor() // Returns a non-owning pointer to the color
{
    return m_color;
}

void Cube::setLength(int length)
{
    m_length = length;
}

void Cube::setWidth(int width)
{
    m_width = width;
}

void Cube::setHeight(int height)
{
    m_height = height;
}

void Cube::setColor(char *color) // Doesn't take ownership of passed in string
{
    int colorLength = strlen(color);

    if (!m_color) // No color stored (construction) allocate for copy
    {
        m_color = new char[colorLength];
    }
    else if (strlen(m_color) < colorLength) // Current buffer is too small, re-allocate
    {
        delete m_color;
        m_color = new char[colorLength];
    }

    std::memcpy(m_color, color, strlen(color));
}

int Cube::calculateVolume()
{
    return m_length * m_width * m_height;
}
