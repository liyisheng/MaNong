#include <iostream>

class Point
{
public:
    Point(int ix, int iy, double& z) : ref1_(ix_), ref2_(z)
    {
        ix_ = ix;
        iy_ = iy;
    }

    void print()
    {
        std::cout << "(" << ix_ << ", " << iy_ << ")" << std::endl;
        std::cout << "ref1 = " << ref1_ << std::endl
                  << "ref2 = " << ref2_ << std::endl;
    }

private:
    int ix_;
    int iy_;
    int &ref1_;
    double &ref2_;
};

int main(void)
{
    double dval = 5.0;
    Point pt(3, 4, dval);
    pt.print();

    std::cout << std::endl;
    std::cout << sizeof(Point) << std::endl;
    return 0;
}

