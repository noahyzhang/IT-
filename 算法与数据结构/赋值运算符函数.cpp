#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<string.h>

class CMyString {
public:
	CMyString(const char* pData = nullptr);
	CMyString(const CMyString& str);
	CMyString& operator=(const CMyString& str);
	void Print();
	~CMyString(void);


private:
	char* m_pData;
};

#if 0

CMyString& CMyString::operator=(const CMyString& str) //返回引用，才可以连续赋值。传入引用，防止重复拷贝
{
	if (this == &str)  //一旦释放了自身的内存，传入的参数的内存也被释放了，就会找不到需要赋值的内容了。
		return *this;
	delete[] m_pData;  //分配新内存之前释放自身已有的空间，则程序会出现内存泄露
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData) + 1];   //存在问题，，，new万一失败，则m_pData将是一个空指针。这样容易导致程序崩溃 。(1)
	strcpy(m_pData, str.m_pData);				   
	return *this;
}
#endif

//(1):解决：1、先用new申请内存，再delete原有内容  2、我们还可以先创建一个实例，再交换临时实例和原来的实例。

CMyString& CMyString::operator=(const CMyString& str)
{
	if (this != &str)
	{
		CMyString strTemp(str);

		char* pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}
	return *this;
}

CMyString::CMyString(const char* pData)  //此处的pData不能赋值为nullptr，否则会出现错误。重定义
{
	if (pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		int len = strlen(pData);
		m_pData = new char[len + 1];
		strcpy(m_pData, pData);
	}
}


CMyString::CMyString(const CMyString& str)
{
	int len = strlen(str.m_pData);
	m_pData = new char[len + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString(void)
{
	delete[] m_pData;
}

void CMyString::Print()
{
	printf("%s", m_pData);
}

void Test1()
{
	printf("Test1 begins:\n");

	const char* text = "Hello world";

	CMyString str1(text);
	CMyString str2;
	str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");
}

// 赋值给自己
void Test2()
{
	printf("Test2 begins:\n");

	const char* text = "Hello world";

	CMyString str1(text);
	str1 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str1.Print();
	printf(".\n");
}

// 连续赋值
void Test3()
{
	printf("Test3 begins:\n");

	const char* text = "Hello world";

	CMyString str1(text);
	CMyString str2, str3;
	str3 = str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str3.Print();
	printf(".\n");
}

#if 0
int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();

	system("pause");
	return 0;
}
#endif