#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<map>
using namespace std;
#if 0
class Solution {
private:
	unordered_map<int, string> u_mp;
	vector<string> res;
public:
	vector<string> letterCombinations(string digits) {
		u_mp.insert({ { 2,"abc" },{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"} });
		if(digits.size() != 0)
			backtrack("", digits);
		return res;
	}
private:
	void backtrack(string combination, string next_digits)
	{
		if (next_digits.size() == 0)
			res.push_back(combination);
		else
		{
			char digit = next_digits[0];
			string letters = u_mp[(digit - '0')];
			for (int i = 0; i < letters.size(); ++i)
			{
				string letter = u_mp[(digit - '0')].substr(i, i + 1);
				backtrack(combination + letter, next_digits.substr(1));
			}
		}
	}
};


class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (digits.empty())
			return res;
		string temp;
		res.push_back(temp);
		map<char, string> maps;
		maps['2'] = "abc";
		maps['3'] = "def";
		maps['4'] = "ghi";
		maps['5'] = "jkl";
		maps['6'] = "mno";
		maps['7'] = "pqrs";
		maps['8'] = "tuv";
		maps['9'] = "wxyz";
		letterCombinations(digits, maps, res);
		return res;
	}

	void letterCombinations(string &digits, map<char, string> &maps, vector<string> &res)
	{
		//从左到右增加每个按键
		for (int j = 0; j < digits.size(); j++)
		{
			//之前所有按键的情况组合数
			int len = res.size();
			for (int i = 0; i < len; i++)
			{
				//按键的每个情况，在之前结果上加上一个按键
				for (auto m : maps[digits[j]])
				{
					res.push_back(res[i] + m);
				}
			}
			//删除上一步中残留的项
			res.erase(res.begin(), res.begin() + len);
		}
		return;
	}
};
#endif

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		unordered_map<char, string> u_mp;
		u_mp.insert({ { '2',"abc" },{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} });
		if (digits.empty()) return res;
		func(res, "", digits, u_mp, 0);
		return res;
	}
private:
	void func(vector<string>& res,string str,string& digits,unordered_map<char,string>& u_map,int k)
	{
		if (str.size() == digits.size())
		{
			res.push_back(str);
			return;
		}
		string tmp = u_map[digits[k]];
		for (auto e : tmp)
		{
			str += e;
			func(res, str, digits, u_map, k + 1);
			str.pop_back();
		}
	}
};
#if 0
int main()
{
	Solution sn;
	string digits{ "23" };
	vector<string> res = sn.letterCombinations(digits);
	return 0;
}
#endif