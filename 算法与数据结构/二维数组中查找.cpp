#include<iostream>
#include<vector>

bool Find(std::vector<std::vector<int>>& vec, int aim)
{
	int row = vec.size();
	int col = vec[0].size();
	for (int i = col - 1; i >= 0; --i)
	{
		if (vec[0][i] <= aim)
		{
			for (int j = 0; j < row; ++j)
			{
				if (vec[j][i] == aim)
					return true;
			}
			return false;
		}
	}
	return false;
}

#if 0
int main()
{
	std::vector<std::vector<int>> vec{ {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
	bool res = Find(vec, 7);
	std::cout << res << std::endl;
	res = Find(vec, 5);
	std::cout << res << std::endl;
	system("pause");
	return 0;
}

#endif