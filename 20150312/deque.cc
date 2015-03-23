#include <iostream>
#include <deque>

int main(void)
{
    double sz[6] = {0, 1, 2, 3, 4, 5};
    std::deque<double> obD(sz, sz + 6);

    double dFront = obD.front();
    double dBack = obD.back();

    std::cout << dFront << std::endl;
    std::cout << dBack << std::endl;

    std::deque<double>::iterator it = obD.begin();
    for(; it != obD.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
