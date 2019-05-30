#include<vector>
#include<string>
#include<iostream>

using namespace std;
#if 0
string longestPalindrome(string s)
{
	if (s.empty()) return "";
	int len = s.size();
	if (len == 1)return s;
	int longest = 1;
	int start = 0;
	vector<vector<int> > dp(len, vector<int>(len));
	for (int i = 0; i < len; i++)
	{
		dp[i][i] = 1;
		if (i < len - 1)
		{
			if (s[i] == s[i + 1])
			{
				dp[i][i + 1] = 1;
				start = i;
				longest = 2;
			}
		}
	}
	for (int l = 3; l <= len; l++)//�Ӵ�����
	{
		for (int i = 0; i + l - 1 < len; i++)//ö���Ӵ�����ʼ��
		{
			int j = l + i - 1;//�յ�
			if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
			{
				dp[i][j] = 1;
				start = i;
				longest = l;
			}
		}
	}
	return s.substr(start, longest);
}

int main()
{
	std::string str("abbad");
	std::string res = longestPalindrome(str);
	std::cout << res << std::endl;
	return 0;
}
#endif