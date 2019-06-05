#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
private:
	bool Check(char left, char right)
	{
		if ((left == 'I' && (right == 'V' || right == 'X'))
			|| (left == 'X' && (right == 'L' || right == 'C'))
			|| (left == 'C' && (right == 'D' || right == 'M')))
			return true;
		return false;
	}
public:
	int romanToInt(string s) {
		std::unordered_map<char, int> mp;
		mp['I'] = 1; mp['V'] = 5; mp['X'] = 10;
		mp['L'] = 50; mp['C'] = 100; mp['D'] = 500;
		mp['M'] = 1000;
		int res = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (i < (s.size() - 1) && Check(s[i], s[i + 1]))
			{
				res += (mp[s[i + 1]] - mp[s[i]]);
				++i;
			}
			else
				res += mp[s[i]];
		}
		return res;
	}
};
#if 0
int main()
{
	Solution s;
	std::string str{ "IV" };
	int res = s.romanToInt(str);

	return 0;
}
#endif