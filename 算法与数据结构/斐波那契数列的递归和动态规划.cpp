#include<vector>
#include<iostream>

int GetNum1(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	int start = 1, mid = 2,end = 0;
	for (int i = 3; i <= n; ++i)
	{
		end = start + mid;
		start = mid;
		mid = end;
	}
	return end;
}

int GetNum2(int n)
{
	if (n < 1)
		return 0;
	if (n == 1 || n == 2 || n == 3)
		return n;
	int first = 1, second = 2, third = 3;
	int tmp1 = 0, tmp2 = 0;
	for (int i = 4; i <= n; ++i)
	{
		tmp1 = third;
		tmp2 = second;
		third += first;
		second = tmp1;
		first = tmp2;
	}
	return third;
}

#if 0
int main()
{
	int n = 6;
	//int res = GetNum1(n);
	int res = GetNum2(n);
	std::cout << res << std::endl;
	system("pause");
	return 0;
}
#endif