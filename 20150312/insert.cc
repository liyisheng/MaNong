#include <iostream>
#include <vector>

void disp(std::vector<int> &vec)
{
    std::vector<int>::iterator it = vec.begin();
    for(; it != vec.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}

int main()
{
    std::vector<int> obD(5);
    disp(obD);

	std::cout << std::endl;

    std::vector<int>::iterator it = obD.end();
    it = obD.insert(it, 1);
    std::cout << *it << std::endl;
	std::cout << std::endl;

    disp(obD);
    std::cout << std::endl;

    obD.insert(it, 2, 3);
    disp(obD);
    std::cout << std::endl;

    it = obD.begin();
    int sz[3] = {7, 8, 9};
    obD.insert(it, sz, sz + 3);
    disp(obD);
    std::cout << std::endl;
}
