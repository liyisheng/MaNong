//单例设计模式
#include <iostream>

class Singleton
{
	public:
		static Singleton* createInstance()
		{
			if(NULL == pInstance)
			{
				pInstance = new Singleton;
			}
			return pInstance;
		}
	private:
		Singleton()
		{
			std::cout << "构造函数被执行 " << std::endl;
		}

	private:
		static Singleton *pInstance;
};

Singleton* Singleton::pInstance = NULL;

int main(void)
{
	Singleton *pInstance = Singleton::createInstance();
	Singleton *pInstance2 = Singleton::createInstance();
	//Singleton *ps2 = new Singleton;
	std::cout << "pInstance  = " << pInstance << std::endl;
	std::cout << "pInstance2 = " << pInstance2 << std::endl;

}
