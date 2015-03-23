#include <iostream> 
class CData
{
	public:
		int getLen()
		{
			return 5;
		}
};


class CDataPtr
{
	public:
		CDataPtr()
		{
			m_pData = new CData;
		}

		~CDataPtr()
		{
			delete m_pData;
		}

		CData *operator ->()
		{
			std::cout << "->操作符重载函数被调用" << std::endl;
			return m_pData;
		}


	public:
		CData *m_pData;

};

int main(void)
{
	CDataPtr p;
	std::cout << p->getLen()<< std::endl;

	(p.operator->())->getLen();

	return 0;
}
