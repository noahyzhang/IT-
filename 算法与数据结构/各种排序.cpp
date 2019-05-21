#include<iostream>
#include<vector>

void PrintArr(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << ' ';
	std::endl(std::cout);
}

void InsertSort(std::vector<int>& vec)
{
	int i, j;
	for (i = 1; i < vec.size(); ++i)
	{
		int num = vec[i];
		for (j = i - 1; j >= 0; --j)
		{
			if (num < vec[j])
				vec[j + 1] = vec[j];
			else
				break;
		}
		vec[j+1] = num;
	}
}

void BubbleSort(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		int flag = 0;
		for (int j = 0; j < vec.size() - i - 1; ++j)
		{
			if (vec[j] > vec[j+1])
			{
				std::swap(vec[j], vec[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

void MergeData(std::vector<int>& vec, int left, int mid, int right, std::vector<int>& temp)
{
	int index = left;
	int left1 = left, right1 = mid, left2 = mid, right2 = right;
	while (left1 < right1 && left2 < right2)
	{
		if (vec[left1] < vec[left2])
			temp[index++] = vec[left1++];
		else
			temp[index++] = vec[left2++];
	}
	while (left1 < right1)
		temp[index++] = vec[left1++];
	while (left2 < right2)
		temp[index++] = vec[left2++];
}

void _Merge(std::vector<int>& vec, int left, int right, std::vector<int>& temp)
{
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);
		_Merge(vec, left, mid, temp);
		_Merge(vec, mid, right, temp);

		MergeData(vec, left, mid, right, temp);

		for (int i = left; i < right; ++i)
			vec[i] = temp[i];
	}
}

void Merge(std::vector<int>& vec)
{
	if (vec.empty())
		return;
	std::vector<int> temp(vec.size(),0);
	_Merge(vec, 0, vec.size(), temp);
}

void AdjustDown(std::vector<int>& vec, int parent, int size)
{
	int child = (parent << 1) + 1;
	while (child < size)
	{
		if (child + 1 < size && vec[child] < vec[child + 1])
			child += 1;
		if (vec[parent] < vec[child])
			std::swap(vec[parent], vec[child]);
		parent = child;
		child = (child << 1) + 1;
	}
}

void HeapSort(std::vector<int>& vec)
{
	int size = vec.size();
	int root = (size - 2) >> 1;
	for (; root >= 0; --root)
		AdjustDown(vec, root, size);
	for (int i = 0; i < size - 1; ++i)
	{
		std::swap(vec[0], vec[size - i - 1]);
		AdjustDown(vec, 0, size - 1 - i);
	}
}

void _InsertSort(std::vector<int>& vec, int gap)
{
	int i, j, key;
	for (i = 0; i < vec.size(); ++i)
	{
		key = vec[i];
		for (j = i - gap; j >= 0; j -= gap)
		{
			if (key < vec[j])
				vec[j+gap] = vec[j];
			else
				break;
		}
		vec[j + gap] = key;
	}
}

void ShellSort(std::vector<int>& vec)
{
	if (vec.empty())
		return;
	int gap = vec.size();
	while (1)
	{
		gap = gap / 3 + 1;
		_InsertSort(vec, gap);
		if (gap == 1) break;
	}
}

int Random(int start, int end)
{
	return rand() % (end - start) + start;
}

int Partion1(std::vector<int>& vec, int start, int end)
{
	if (vec.empty() || start < 0 || end >= vec.size())
		throw new std::exception("Invaild Parameters");

	int index = Random(start, end);
	std::swap(vec[index], vec[end]);
	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (vec[index] < vec[end])
		{
			++small;
			if (small != index)
				std::swap(vec[index], vec[small]);
		}
	}
	++small;
	std::swap(vec[end], vec[small]);
	return small;
}

void _QuickSort(std::vector<int>& vec, int start, int end)
{
	if (start == end)
		return;
	int index = Partion1(vec, start, end);
	if (index > start)
		_QuickSort(vec, start, index-1);
	if (index < end)
		_QuickSort(vec, index + 1, end);
}

void QuickSort(std::vector<int>& vec)
{
	if (vec.empty())
		return;
	int size = vec.size();
	_QuickSort(vec, 0, size-1);
}
#if 0
int main()
{
	std::vector<int> vec{ 1,3,5,7,9,2,4,6,8,10 };
	//InsertSort(vec);
	//BubbleSort(vec);
	//Merge(vec);
	//HeapSort(vec);
	//ShellSort(vec);
	QuickSort(vec);
	PrintArr(vec);
	return 0;
}
#endif