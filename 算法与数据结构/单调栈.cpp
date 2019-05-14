#include<iostream>
#include<vector>
#include<stack>

std::vector<std::pair<int,int>> GetNearLessNoRepeat(std::vector<int>& vec)
{
	std::vector<std::pair<int, int>> res;
	res.resize(vec.size());
	std::stack<int> st;
	for (int i = 0; i < vec.size(); ++i)
	{
		while (!st.empty() && vec[st.top()] > vec[i])
		{
			int popIndex = st.top();
			st.pop();
			int leftLessIndex = (st.empty() == true) ? -1 : st.top();
			res[popIndex].first = leftLessIndex;
			res[popIndex].second = i;
		}
		st.push(i);
	}
	while (!st.empty())
	{
		int popIndex = st.top();
		st.pop();
		int leftLessIndex = (st.empty() == true) ? -1 : st.top();
		res[popIndex].first = leftLessIndex;
		res[popIndex].second = -1;
	}
	return res;
}
#if 0
int main()
{
	std::vector<int> vec{ 3,4,1,5,6,2,7 };
	std::vector<std::pair<int, int>> res;
	res = GetNearLessNoRepeat(vec);
	for (auto e : res)
	{
		std::cout << "(" << e.first << "," << e.second << ")" << " ";
	}
	system("pause");
	return 0;
}
#endif