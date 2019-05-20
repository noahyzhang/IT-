#include<iostream>
#include<vector>
#include<algorithm>

int process(std::vector<int>& arr, int i, int rest)
{
	if (arr.size() == i)
		return rest == 0 ? 0 : -1;
	int res = -1;
	for (int k = 0; k*arr[i] <= rest; ++k)
	{
		int next = process(arr, i + 1, rest - k * arr[i]);
		if (next != -1)
			res = res == -1 ? next + k : std::min(res, next + k);
	}
	return res;
}

int minCoins1(std::vector<int>& arr, int aim)
{
	if (arr.empty() || aim < 0)
		return -1;
	return process(arr, 0, aim);
}

int minCoins2(std::vector<int>& arr, int aim)
{
	if (arr.empty() || aim < 0)
		return -1;
	int N = arr.size();
	std::vector<std::vector<int>> dp;
	dp.resize(N + 1);
	for (int i = 0; i < N + 1; ++i)
		dp[i].resize(aim + 1);
	for (int col = 1; col <= aim; ++col)
		dp[N][col] = -1;
	for (int i = N - 1; i >= 0; --i)
	{
		for (int rest = 0; rest <= aim; ++rest)
		{
			dp[i][rest] = -1;
			if (dp[i + 1][rest] != -1)
				dp[i][rest] = dp[i + 1][rest];
			if (rest - arr[i] >= 0 && dp[i][rest - arr[i]] != -1)
				if (dp[i][rest] == -1)
					dp[i][rest] = dp[i][rest - arr[i]] + 1;
				else
					dp[i][rest] = std::min(dp[i][rest], dp[i][rest - arr[i]] + 1);
		}
	}
	return dp[0][aim];
}
#if 0
int main()
{
	std::vector<int> vec{ 3,5 };
	//int res = minCoins1(vec, 2);
	int res = minCoins2(vec, 2);
	std::cout << res << std::endl;
	system("pause");
	return 0;
}
#endif