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

CMyString& CMyString::operator=(const CMyString& str) //�������ã��ſ���������ֵ���������ã���ֹ�ظ�����
{
	if (this == &str)  //һ���ͷ���������ڴ棬����Ĳ������ڴ�Ҳ���ͷ��ˣ��ͻ��Ҳ�����Ҫ��ֵ�������ˡ�
		return *this;
	delete[] m_pData;  //�������ڴ�֮ǰ�ͷ��������еĿռ䣬����������ڴ�й¶
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData) + 1];   //�������⣬����new��һʧ�ܣ���m_pData����һ����ָ�롣�������׵��³������ ��(1)
	strcpy(m_pData, str.m_pData);				   
	return *this;
}
#endif

//(1):�����1������new�����ڴ棬��deleteԭ������  2�����ǻ������ȴ���һ��ʵ�����ٽ�����ʱʵ����ԭ����ʵ����

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

CMyString::CMyString(const char* pData)  //�˴���pData���ܸ�ֵΪnullptr���������ִ����ض���
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

// ��ֵ���Լ�
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

// ������ֵ
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