#include<iostream>
#include<vector>
#if 0
bool Increment(char* number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	for (int i = nLength - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)
			nSum++;
		if (nSum >= 10)
		{
			if (i == 0)
				isOverflow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverflow;
}

void PrintToMaxOfNDigits(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
	{
		PrintNumber(number);
	}
	delete[] number;
}
#endif

void PrintDigit(std::vector<int>& vec)
{
	for (int i = vec.size() - 1; i >= 0; --i)
		std::cout << vec[i];
	std::cout << ' ';
}

void Print1ToMaxOfDigits(int n)
{
	std::vector<int> vec;
	vec.push_back(1);
	bool flag = false;
	while (1)
	{
		PrintDigit(vec);
		if (vec[0] + 1 <= 9)
			vec[0] += 1;
		else
		{
			vec[0] = 0;
			for (int i = 1; i < vec.size(); ++i)
			{
				if (vec[i] + 1 <= 9)
				{
					vec[i] += 1;
					flag = false;
					break;
				}
				vec[i] = 0;
				flag = true;
			}
			if(flag == true || vec.size() == 1)
				vec.push_back(1);
			if (vec.size() > n)
				break;
		}
	}
}
#if 0
int main()
{
	Print1ToMaxOfDigits(5);
	return 0;
}
#endif