#include <iostream>
#include <string>

int main(void)
{
    std::string str = "hello,world!";

    for(int idx = 0; idx != str.size(); ++idx)
    {
        std::cout << str[idx] << std::endl;
    }

    return 0;
}
