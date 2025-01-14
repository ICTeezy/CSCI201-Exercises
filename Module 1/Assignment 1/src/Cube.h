

class Cube
{

private:
    int m_length;
    int m_width;
    int m_height;
    char *m_color;

public:
    Cube(int length, int width, int height, char *color);

    int getLength();
    int getWidth();
    int getHeight();
    char* const getColor();

    void setLength(int length);
    void setWidth(int width);
    void setHeight(int height);
    void setColor(char *color);

    int calculateVolume();
};