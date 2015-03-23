#include <iostream>
#include <list>

void disp(std::list<int> & li)
{
    std::list<int>::iterator it;
    for(it = li.begin(); it != li.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}


int main(void)
{
    int sz[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> obL(sz, sz + 9);
    disp(obL);
    std::cout << std::endl;

    std::list<int>::iterator it = obL.begin();
    ++it;
    it = obL.erase(it);
    std::cout << *it << std::endl;

    std::cout << std::endl;

    obL.erase(it, obL.end());
    disp(obL);

    obL.clear();

    std::cout << "obL's size() = " << obL.size() << std::endl;

    return 0;

}
