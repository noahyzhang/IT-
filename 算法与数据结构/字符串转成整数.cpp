#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		if (str.empty()) return 0;
		int i = 0;
		while (str[i] == ' ')
			i++;
		bool flag = true;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '+')
				flag = true;
			else if (str[i] == '-')
				flag = false;
			++i;
		}
		while (str[i] == '0')
			++i;
		long long ans = 0;
		std::stack<int> st;
		while (i < str.size() && str[i] >= '0' && str[i] <= '9')
		{

			st.push(str[i++] - '0');
		}
		long long num = 1;
		while (!st.empty())
		{
			int tmp = st.top();
			st.pop();
			ans += tmp * num;
			if (flag == true && ans > INT_MAX) return INT_MAX;
			if (flag == false && ans < INT_MIN) return INT_MIN;
			if (num > INT_MAX)
			{
				if (flag == true) return INT_MAX;
				if (flag == false) return INT_MIN;
			}
			num *= 10;
		}
		if (flag == false) ans = -ans;
		if (flag == true && ans > INT_MAX) return INT_MAX;
		if (flag == false && ans < INT_MIN) return INT_MIN;
		
		return ans;
	}
};
#if 0
int main()
{
	Solution s;
	string st{ "-2147483649"};
	int res = s.myAtoi(st);
	std::cout << res << std::endl;
	return 0;
}
#endif