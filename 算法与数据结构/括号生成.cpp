#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		if (n <= 0) return res;
		func(res, "", 0, 0, n);
		return res;
	}
private:
	void func(vector<string>& res, string str, int open, int close, int max)
	{
		if (str.size() == max * 2)
		{
			res.push_back(str);
			return;
		}
		if (open < max)
			func(res, str + '(', open + 1, close, max);
		if (close < open)
			func(res, str + ')', open, close + 1, max);
	}
};

#if 0
int main()
{
	Solution sn;
	vector<string> res = sn.generateParenthesis(3);
	return 0;
}
#endif