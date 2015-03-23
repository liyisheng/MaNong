#include <iostream>

class Point;

std::ostream &operator <<(std::ostream &os, const Point &pt);

class AnotherPoint
{
public:
    AnotherPoint(double dx = 1.11, double dy = 1.11) : dx_(dx), dy_(dy) {}

    void print() const
    {
        std::cout << "( " << dx_ << ", " << dy_ << ")" << std::endl;
    }

private:
    double dx_;
    double dy_;
};

class Point
{
public:
    Point(int ix = 0, int iy = 0) : ix_(ix), iy_(iy) {}

    void print() const
    {
        std::cout << "(" << ix_ << ", " << iy_ << ")" << std::endl;
    }
    
    friend std::ostream &operator <<(std::ostream &os, const Point &pt);

    operator int()
    {
        return ix_;
    }

    operator double()
    {
        return ix_ * iy_;
    }

    operator AnotherPoint()
    {
        return AnotherPoint(ix_, iy_);
    }

private:
    int ix_;
    int iy_;
};


int main(void)
{
    Point pt1(4, 5);
    pt1.print();

    int x1 = pt1;
    std::cout << "x1 = " << x1 << std::endl;

    double dx = pt1;
    std::cout << "dx = " << dx << std::endl;

    AnotherPoint pt2;
    pt2 = pt1;
    pt2.print();
}
