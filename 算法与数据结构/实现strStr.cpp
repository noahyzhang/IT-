#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (haystack.empty() || needle.empty() || haystack.size() < needle.size())
			return -1;
		for (int i = 0; i < haystack.size(); ++i)
		{
			if (haystack[i] == needle[0])
			{
				int j, k;
				for (j = i, k = 0; j < haystack.size() && k < needle.size(); ++j, ++k)
				{
					if (haystack[j] != needle[k])
						break;
				}
				if (k == needle.size())
					return i;
			}
		}
		return -1;
	}
};
#if 0
int main()
{
	string s1{ "aaaaaaaaaaaaaaaaaaaaaaaaaa" };
	string s2{ "aaaaaaaaaaaaaaaaaaaaaaaaa" };
	Solution sn;
	int res = sn.strStr(s1, s2);
	return 0;
}
#endif

//使用 KMP算法解决。。