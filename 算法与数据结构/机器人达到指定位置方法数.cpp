#include<iostream>
#include<vector>

int Walk(int N, int cur, int rest, int P)
{
	if (rest == 0)
		return cur == P ? 1 : 0;
	if (cur == 1)
		return Walk(N, 2, rest - 1, P);
	if (cur == N)
		return Walk(N, N - 1, rest - 1, P);

	return Walk(N, cur + 1, rest - 1, P) + Walk(N, cur - 1, rest - 1, P);
}

//N一共有N个位置，M代表机器人开始在M位置上,K代表必须走K步，P代表最终到达的位置
int way1(int N, int M, int K, int P)
{
	if (N < 2 || K < 1 || M < 1 || M > N || P < 1 || P > N)
		return 0;
	return Walk(N, M, K, P);
}

int way2(int N, int M, int K, int P)
{
	if (N < 2 || K < 1 || M < 1 || M > N || P < 1 || P > N)
		return 0;
	int cur = M, rest = K;
	std::vector<std::vector<int>> dp;
	dp.resize(rest+1);
	for (int i = 0; i < rest+1; ++i)
		dp[i].resize(N);
	for (int i = 0; i < N; ++i)
		dp[0][i] = 0;
	dp[0][P-1] = 1;

	for (int i = 1; i < rest+1; ++i) //row
	{
		for (int j = 0; j < N; ++j)  //col
		{
			if (j == 0)
				dp[i][0] = dp[i - 1][1];
			else if (j == N - 1)
				dp[i][N - 1] = dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
		}
	}
	int res = 0;
	for (int i = 0; i < N; ++i)
		if (dp[rest][i] > res)
			res = dp[rest][i];
	return res;
}

#if 0
int main()
{
	int n = 5, m = 2, k = 3, p = 3;
	//int res = way1(3,1,3,3);
	int res = way2(7, 4, 9, 5);
	std::cout << res << std::endl;
	system("pause");
	return 0;
}
#endif