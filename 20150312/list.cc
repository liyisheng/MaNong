#include <iostream>
#include <list>

int main(void)
{
    std::list<int>::iterator it;
    int sz[5] = {1, 2, 3, 4, 5};
    std::list<int> obL(sz, sz + 5);
    obL.push_front(9);
    for(it = obL.begin(); it != obL.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    std::cout << std::endl;
    obL.pop_front();
    for(it = obL.begin(); it != obL.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    

}
