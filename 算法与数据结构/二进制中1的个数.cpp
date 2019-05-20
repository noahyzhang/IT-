#include<iostream>

int NumberOf1(int n) //错误的解法，处理不了负数
{
	int count = 0;
	while (n != 0)
	{
		if (n & 0x1)
			count++;
		n = n >> 1;
	}
	return count;
}

int NumberOf2(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
			count++;
		flag = flag << 1;
	}
	return count;
}

int NumberOf3(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = (n - 1)&n;
	}
	return count;
}

#if 0
int main()
{
	int n = 0xFFFFFFFF;
	int count = NumberOf3(n);
	std::cout << count << std::endl;
	return 0;
}
#endif