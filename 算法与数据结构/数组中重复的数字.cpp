#include<vector>
#include<iostream>
#include<algorithm>

bool GetRepetitionNum1(std::vector<int>& vec,int* duplication)
{
	if (vec.empty())
		return false;
	int len = vec.size();
	for (int i = 0; i < len; ++i)
		if (vec[i] < 0 || vec[i] > len - 1)
			return false;

	for(int i = 0;i < len;++i)
	{
		while (vec[i] != i)
		{
			if (vec[i] == vec[vec[i]])
			{
				*duplication = vec[i];
				return true;
			}
			std::swap(vec[i], vec[vec[i]]);
		}
	}
	return false;  
}

bool GetRepetitionNum2(std::vector<int>& vec, int* duplication)
{
	if (vec.empty())
		return false;
	int len = vec.size();
	for (int i = 0; i < len; ++i)
		if (vec[i] < 0 || vec[i] > len - 1)
			return false;

	for (int i = 0; i < len; ++i)
	{
		if (vec[i] == i)
			continue;
		else 
		{
			if (vec[i] == vec[vec[i]])
			{
				*duplication = vec[i];
				return true;
			}

			std::swap(vec[i], vec[vec[i]]);
			--i;
		}
	}
	return false;
}
//上面的两种解法修改了数组

//下面使用类似于二分查找的方式来解题
int countRange(std::vector<int>& vec, int start, int end)
{
	int count = 0;
	if (vec.empty())
		return 0;
	int len = vec.size();
	for (int i = 0; i < len; ++i)
		if (vec[i] >= vec[start] && vec[i] <= vec[end])
			++count;
	return count;
}

int GetRepetitionNum3(std::vector<int>& vec)
{
	if (vec.empty())
		return -1;
	int len = vec.size();
	for (int i = 0; i < len; ++i)
		if (vec[i] < 0 || vec[i] > len - 1)
			return -1;

	int start = 1;
	int end = len - 1;
	while (start <= end)
	{
		int middle = ((end - start) >> 1) + start;
		int count = countRange(vec, start, middle);
		if (end == start)
		{
			if (count > 1)
				return vec[start];
			else
				break;
		}
		if (count > (middle - start + 1))
			end = middle;
		else
			start = middle + 1;
	}
	return -1;
}

#if 0
int main()
{
	std::vector<int> vec{ 2,3,1,0,2,5,3 };
	int duplication;
	//bool res = GetRepetitionNum2(vec, &duplication);
	int res = GetRepetitionNum3(vec);
	std::cout << res << std::endl;
	system("pause");
	return 0;
}
#endif