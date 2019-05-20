#include<iostream>
#include<vector>

void SortArray(std::vector<int>& v1, std::vector<int>& v2)
{
	int len1 = v1.size();
	int len2 = v2.size();
	v1.resize(len1 + len2);
	int p1 = len1 - 1;
	int p2 = len2 - 1;
	for (int i = len1 + len2 - 1; i >= 0; --i)
	{
		if (p1 >= 0 && p2 >= 0)
			v1[i] = v1[p1] > v2[p2] ? v1[p1--] : v2[p2--];
		else
		{
			if (p2 >= 0)
				v1[i] = v1[p2];
		}
	}
}
#if 0
int main()
{
	std::vector<int> v1{ 1,3,5,7,9 };
	std::vector<int> v2{ 2,4,6,8,10 };
	SortArray(v1, v2);
	for (int i = 0; i < v1.size(); ++i)
		std::cout << v1[i] << std::endl;
	system("pause");
	return 0;
}
#endif