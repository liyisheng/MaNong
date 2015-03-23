#include <iostream>
#include <string.h>

class CharSZ
{
public:
    CharSZ(int sz)
    {
        iLen_ = sz;
        pBuf_ = new char[iLen_];
    }

    ~CharSZ()
    {
        delete pBuf_;
    }

    int getLen() const
    {
        return iLen_;
    }

    char &operator [](int idx);
	const char &operator[] (const size_t) const;

private:
    int iLen_;
    char *pBuf_;
};

char &CharSZ::operator [](int idx)
{
    static char szNull = '\0';
    if(idx < iLen_ && idx >= 0)
    {
        return pBuf_[idx];
    }
    else
    {
        std::cout << "下标越界" << std::endl;
        return szNull;
    }
}

int main()
{
    const char *sz = "Hello,world!";

    int length = strlen(sz) + 1;
    CharSZ de(length);
    for(int idx = 0; idx < length; ++idx)
    {
        de[idx] = sz[idx];
    }

    for(int idx = 0; idx < de.getLen(); ++idx)
    {
        std::cout << de[idx];
    }

    std::cout << std::endl;
    return 0;
}
