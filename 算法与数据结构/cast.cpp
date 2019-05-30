//#include <iostream>
//using namespace std; 
//
//int main(void)
//{
//	double dPi = 3.1415926;
//	int num1 = (int)dPi;    //c语言的旧式类型转换
//	int num2 = dPi;         //隐式类型转换
//	// 静态的类型转换:   
//	// 在编译的时 进⾏行基本类型的转换 能替代c⻛风格的类型转换 可以进⾏行⼀一部分检查     
//	int num3 = static_cast<int> (dPi); //c++的新式的类型转换运算符   
//	cout << "num1:" << num1 << " num2:" << num2 << " num3:" << num3 << endl;
//	return 0;
//}

//#include<iostream>
//
//class Animal {
//public:
//	virtual void cry() = 0;
//};
//
//class Dog : public Animal
//{
//public:
//	virtual void cry()
//	{
//		std::cout << "旺旺" << std::endl;
//	}
//	void dohome()
//	{
//		std::cout << "看家" << std::endl;
//	}
//};
//
//class Cat : public Animal
//{
//public:
//	virtual void cry()
//	{
//		std::cout << "喵喵" << std::endl;
//	}
//	void dohome()
//	{
//		std::cout << "抓老鼠" << std::endl;
//	}
//};
//
//int main()
//{
//	Animal* base = NULL;
//	base = new Cat();
//	base->cry();
//
//	//⽤用于将⽗父类指针转换成⼦子类，
//	Dog	*pDog = dynamic_cast<Dog*>(base); //此时转换时失败的，因为父类指针现在指向的对象是猫，所以转换狗是失败的。
//	                                      //转换失败返回空（NULL）
//	if (pDog != NULL)
//	{
//		pDog->cry();
//		pDog->dohome();
//	}
//
//	Cat* pCat = dynamic_cast<Cat*>(base); //此时转换成功，成功将父类指针转换成子类指针
//	if (pCat != NULL)
//	{
//		pCat->cry();
//		pCat->dohome();
//	}
//
//	system("pause");
//	return 0;
//}


//#include<iostream>
//
//class A {
//public:
//	int data;
//};
//
//int main()
//{
//	const A a = { 200 };
//	A a1 = const_cast<A>(a);    //错误，const_cast 目标类型只能是引用或者指针
//	a1.data = 100;
//
//	A& a2 = const_cast<A&>(a);
//	a2.data = 100;
//	std::cout << a.data << ' ' << a2.data << std::endl;
//
//	A* a3 = const_cast<A*>(&a);
//	a3->data = 100;
//	std::cout << a.data << ' ' << a3->data << std::endl;
//
//	const int x = 3;
//
//	int& x1 = const_cast<int&>(x);
//	x1 = 200;
//	std::cout << x << ' ' << x1 << std::endl;
//
//	int* x2 = const_cast<int*>(&x);
//	*x2 = 300;
//	std::cout << x << ' ' << *x2 << std::endl;
//
//	system("pause");
//	return 0;
//}


//#include<iostream>
//
//class Animal {
//public:
//	void cry()
//	{
//		std::cout << "Animal cry" << std::endl;
//	}
//};
//
//class Book {
//public:
//	void look()
//	{
//		std::cout << "Book look " << std::endl;
//	}
//};
//
//int main()
//{
//	Animal* a = new Animal();
//	a->cry();
//	Book* b = reinterpret_cast<Book*>(a);
//	b->look();
//	system("pause");
//	return 0;
//}