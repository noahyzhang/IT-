#include<iostream>
#include<vector>
#include<algorithm>

int MinPathSum1(std::vector<std::vector<int>>& m)
{
	if (m.empty() || m[0].empty())
		return 0;
	int row = m.size();
	int col = m[0].size();

	std::vector<std::vector<int>> dp;
	dp.resize(row);
	for (int i = 0; i < row; ++i)
		dp[i].resize(col);

	dp[0][0] = m[0][0];
	for (int i = 1; i < row; ++i)
		dp[i][0] = dp[i - 1][0] + m[i][0];
	for (int i = 1; i < col; ++i)
		dp[0][i] = dp[0][i - 1] + m[0][i];

	for (int i = 1; i < row; ++i)
	{
		for (int j = 1; j < col; ++j)
		{
			dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + m[i][j];
		}
	}
	return dp[row - 1][col - 1];
}

int MinPathSum2(std::vector<std::vector<int>>& m)
{
	if (m.empty() || m[0].empty())
		return 0;
	int more = std::max(m.size(), m[0].size());
	int less = std::min(m.size(), m[0].size());
	bool rowmore = more == m.size();
	std::vector<int> res;
	res.resize(less);
	res[0] = m[0][0];
	for (int i = 1; i < less; ++i)
		res[i] = res[i - 1] + (rowmore ? m[0][i] : m[i][0]);
	for (int i = 1; i < more; ++i)
	{
		res[0] = res[0] + (rowmore ? m[i][0] : m[0][i]);
		for (int j = 1; j < less; ++j)
		{
			res[j] = std::min(res[j - 1], res[j]) + (rowmore ? m[i][j] : m[j][i]);
		}
	}
	return res[less - 1];
}

#if 0
int main()
{
	std::vector<std::vector<int>> vec{ {1,3,5,9},{8,1,3,4},{5,0,6,1},{8,8,4,0} };
	//int res = MinPathSum1(vec);
	int res = MinPathSum2(vec);
	std::cout << res << std::endl;

	system("pause");
	return 0;
}
#endif