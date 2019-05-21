#include<iostream>
#include<vector>

#if 0
void AdjustArray(std::vector<int>& vec)
{
	if (vec.empty())
		return;
	int start = 0, end = vec.size() - 1;
	while (start < end)
	{
		while (start < end && vec[start] % 2 == 1)
			start++;
		while (start < end && vec[end] % 2 == 0)
			end--;
		if (start < end)
			std::swap(vec[start], vec[end]);
	}
}

void PrintArr(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << ' ';
	std::endl(std::cout);
}

int main()
{
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	PrintArr(vec);
	AdjustArray(vec);
	PrintArr(vec);
	return 0;
}
#endif

#if 0
void Reorder(int* pData, unsigned int length, bool(*func)(int))
{
	if (pData == nullptr || length == 0)
		return;
	int* pBegin = pData;
	int* pEnd = pData + length - 1;

	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && !func(*pBegin))
			pBegin++;
		while (pBegin < pEnd && func(*pEnd))
			pEnd--;
		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isEven(int n)
{
	return (n & 1) == 0;
}

void ReorderOddEven(int* pData, unsigned int length)
{
	Reorder(pData, length, isEven);
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	ReorderOddEven(arr, 10);
	return 0;
}
#endif