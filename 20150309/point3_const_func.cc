#include <iostream>

class Point
{
public:
    Point(int ix = 0, int iy = 0) : ix_(ix), iy_(iy)
    {}

    void print() const
    {
        std::cout << "(" << ix_ << ", " << iy_ << ")" << std::endl;
    }

    void print2()
    {
    
        ix_ = 10;
        iy_ = 11;
    }
    void print3()
    {
        std::cout << "(" << ix_ << ", " << iy_ << ")" << std::endl;
    }

private:
    int ix_;
    int iy_;

};

int main(void)
{
    Point pt(3, 4);
    pt.print();//非const对象调用了一个const的成员函数

    const Point pt2(5,6);
    pt2.print3();//const对象调用了一个非const的成员函数,编译会出错
    return 0;
}

