#include "Cube.h"

Cube::Cube(int length, int width, int height, std::string color)
    : m_length(length), m_width(width), m_height(height), m_color(color)
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

std::string Cube::getColor() 
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

void Cube::setColor(std::string color)
{
    m_color = color;
}

int Cube::calculateVolume()
{
    return m_length * m_width * m_height;
}
