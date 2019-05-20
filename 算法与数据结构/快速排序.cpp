#include<iostream>
#include<vector>
#include<algorithm>

void Print(std::vector<int>& vec)
{
	for (auto e : vec)
		std::cout << e << ' ';
	std::endl(std::cout);
}

int RandomInRange(int start, int end)
{
	return rand() % (end - start) + start;
}

int Partition(std::vector<int>& vec, int start, int end)
{
	if (vec.empty() || start < 0 || end >= vec.size())
		throw new std::exception("Invalid Parameters");
	
	int index = RandomInRange(start, end);
	std::swap(vec[index], vec[end]);

	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (vec[index] < vec[end])
		{
			++small;
			if(small != index)
				std::swap(vec[index], vec[small]);
		}
	}
	++small;
	std::swap(vec[end], vec[small]);

	return small;
}

void QuickSort(std::vector<int>& vec, int start, int end)
{
	if (start == end)
		return;
	int index = Partition(vec, start, end);
	if (index > start)
		QuickSort(vec, start, index - 1);
	if (index < end)
		QuickSort(vec, index + 1, end);
}
#if 0
int main()
{
	std::vector<int> vec{ 1,3,5,7,9,2,4,6,8,10 };
	Print(vec);
	QuickSort(vec, 0, 9);
	Print(vec);
	return 0;
}
#endif