#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void)
{
    std::vector<int> obv;
    std::cout << "obv's size = " << obv.size() << std::endl;

    double sz[5] = {1, 2, 3, 4, 5};
    std::deque<double> obD(sz + 1, sz + 5);

    //通过下标[]访问容器中的元素
    for(int idx = 0; idx != obD.size(); ++idx)
    {
        std::cout << obD[idx] << std::endl;
    }

    //通过迭代器访问容器中的元素
    std::deque<double>::iterator it = obD.end();
    while(it != obD.begin())
    {
       it--;
       std::cout << *it << std::endl;
    }
    std::cout << std::endl;

    std::list<float> obL(3, 5);
    std::list<float>::iterator lit = obL.begin();
    for(; lit != obL.end(); ++lit)
    {
        (*lit) += 2;
        std::cout << *lit << std::endl;
    }
    std::cout << "swap ---->" << std::endl;

    std::list<float> obL2(4, 9);
    obL.swap(obL2);

    for(lit = obL.begin(); lit != obL.end(); ++lit)
    {
        std::cout << *lit << std::endl;
    }

    std::cout << std::endl;
    std::list<float>::iterator lit2 = obL2.begin();
    for(; lit2 != obL2.end(); ++lit2)
    {
        std::cout << *lit2 << std::endl;
    }
    std::cout << std::endl;

}
