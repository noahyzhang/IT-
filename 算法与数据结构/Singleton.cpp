#include<iostream>
#include<mutex>
#include<Windows.h>

#if 0  //ÀÁºº
class Singleton {
public:
	static Singleton* GetIndex()
	{
		if (_sInstance == nullptr)
		{
			//std::lock_guard<std::mutex> lock(_mtx);
			_mtx.lock();
			if (_sInstance == nullptr)
			{
				Singleton* tmp = new Singleton;
				MemoryBarrier(); //ÄÚ´æÕ¤À¸
				_sInstance = tmp;
			}
			_mtx.unlock();
		}
		return _sInstance;
	}
	void Print()
	{
		std::cout << _data << std::endl;
	}
private:
	Singleton() :_data(0)
	{}
	Singleton(const Singleton&);
	Singleton& operator=(const char* data);
private:
	static Singleton* _sInstance;
	static std::mutex _mtx;
	int _data;
};

Singleton* Singleton::_sInstance = nullptr;
std::mutex Singleton::_mtx;

Singleton* ptr3 = Singleton::GetIndex();

int main()
{
	Singleton* ptr1 = Singleton::GetIndex();
	Singleton* ptr2 = Singleton::GetIndex();

	std::cout << ptr1 << " " << std::endl;
	std::cout << ptr2 << " " << std::endl;
	std::cout << ptr3 << " " << std::endl;
	system("pause");
	return 0;
}
#endif

#if 0 //¶öºº1
#include<assert.h>

class Singleton {
public:
	static Singleton* GetIndex()
	{
		assert(_Instance);
		return _Instance;
	}
	void Print()
	{
		std::cout << _data << std::endl;
	}
private:
	Singleton() :_data(1)
	{}
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
private:
	int _data;
	static Singleton* _Instance;
};

Singleton* Singleton::_Instance = new Singleton;


Singleton* ptr3 = Singleton::GetIndex();
int main()
{
	Singleton* ptr1 = Singleton::GetIndex();
	Singleton* ptr2 = Singleton::GetIndex();
	ptr1->Print();
	std::cout << ptr1 << std::endl;
	std::cout << ptr1 << std::endl;
	std::cout << ptr1 << std::endl;
	system("pause");
	return 0;
}
#endif

#if 0  //¶öºº2
class Singleton {
public:
	static Singleton* GetIndex()
	{
		static Singleton _sIndex;
		return &_sIndex;
	}
	void Print()
	{
		std::cout << _data << std::endl;
	}
private:
	Singleton() :_data(1)
	{}
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
private:
	int _data;
};

Singleton* ptr3 = Singleton::GetIndex();
int main()
{
	Singleton* ptr1 = Singleton::GetIndex();
	Singleton* ptr2 = Singleton::GetIndex();
	ptr1->Print();

	std::cout << ptr1 << std::endl;
	std::cout << ptr2 << std::endl;
	std::cout << ptr3 << std::endl;
	system("pause");
	return 0;
}
#endif