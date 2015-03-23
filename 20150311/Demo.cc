#include <iostream>

class Demo
{
public:
    double operator ()(double x, double y)
    {
        return x * y;
    }

    double operator ()(double x, double y, double z)
    {
        return (x +y ) * z;
    }
};

int main(void)
{
    Demo demo;
    std::cout << demo(2.5, 0.2) << std::endl;
    std::cout << demo(1.2, 1.5, 7.0) << std::endl;
    
    return 0;
}
