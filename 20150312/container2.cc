#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void)
{
    std::vector<int> obV(3, 1);
    obV.push_back(2);
    std::vector<int>::iterator it;
    for(it = obV.begin(); it != obV.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;

    obV.pop_back();
    for(it = obV.begin(); it != obV.end(); ++it)
    {
        std::cout << *it << std::endl;
    }


}
