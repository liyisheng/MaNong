#include <iostream>

class X
{
public:
    
private:
    int &iref0;
    int &iref1;
    int &iref2;
};

int main(void)
{
    std::cout << sizeof(X) << std::endl;
}
