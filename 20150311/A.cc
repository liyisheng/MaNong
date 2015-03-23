#include <iostream>

class A
{
public:
    A(int n) : value_(n) {}

    A(A &other)
    {
        value_ = other.value_;
    }

    void print() const 
    {
        std::cout << value_ << std::endl;
    }

private:
    int value_;
};

int main(void)
{

    A a = 10;//在C++中，引用的初始化规则规定：不能将临时变量作为引用的初始化值，除了常引用之外
    A b = a;
    b.print();
}
