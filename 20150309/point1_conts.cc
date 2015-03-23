#include <iostream>

class Point
{
public:
    Point(int ix, int iy) : ix_(ix), iy_(iy)
    {
    }

    void print()
    {
        std::cout << "(" << ix_ << ", " << iy_ << ")" << std::endl;
    }

private:
    const int ix_;//常量的初始化必须在初始化列表里进行初始化
    const int iy_;
};

int main(void)
{
    Point pt(3, 4);

    pt.print();
    return 0;
}

