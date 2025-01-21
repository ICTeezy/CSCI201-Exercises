#include <string>

class Cube
{

private:
    int m_length;
    int m_width;
    int m_height;
    std::string m_color;

public:
    Cube(int length, int width, int height, std::string color);

    int getLength();
    int getWidth();
    int getHeight();
    std::string getColor();

    void setLength(int length);
    void setWidth(int width);
    void setHeight(int height);
    void setColor(std::string color);

    int calculateVolume();
};