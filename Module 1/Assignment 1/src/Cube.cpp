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
    int newColorLength = strlen(color);

    if (!m_color) // No color stored (construction) allocate and copy
    {
        m_color = new char[newColorLength];
        std::memcpy(m_color, color, newColorLength);
        return;
    }

    int oldColorLength = strlen(m_color);

    if (oldColorLength < newColorLength) // Current buffer is too small, re-allocate
    {
        delete m_color;
        m_color = new char[newColorLength];
    }
    else
    {
        std::memset(m_color, 0, oldColorLength); // Clear previous string
    }

    std::memcpy(m_color, color, newColorLength);
}

int Cube::calculateVolume()
{
    return m_length * m_width * m_height;
}
