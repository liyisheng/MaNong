#include <iostream>

int x = 100;
int z = 200;

namespace mynm
{
int x = 20;


}

class Example
{
public:
    Example(int xp = 0, int yp = 0) : x(xp), y(yp) {}

    void print(int x)
    {
        std::cout << "形参x = " << x << std::endl;
        std::cout << "成员x = " << this->x << std::endl;
        std::cout << "成员x = " << Example::x << std::endl;
        std::cout << "匿名空间 x = " << ::x << std::endl;
        std::cout << "mynm::x = " << mynm::x << std::endl;
        std::cout << "z = " << z << std::endl;
    }




private:
    int x;
    int y;
};

int main(void)
{
    Example ex;
    ex.print(5);
}
