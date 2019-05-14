#include<iostream>
#include<deque>
#include<vector>

std::vector<int> GetMaxWindow(std::vector<int>& arr, int w)
{
	std::vector<int> res;
	if (arr.empty() || w < 1 || arr.size() < w)
		return res;
	std::deque<int> dq;
	for (int i = 0; i < arr.size(); ++i)
	{
		while (!dq.empty() && arr[dq.back()] <= arr[i])
			dq.pop_back();
		dq.push_back(i);
		if (dq.front() == i - w)
			dq.pop_front();
		if (i >= w - 1)
			res.push_back(arr[dq.front()]);
	}
	return res;
}
#if 0
int main()
{
	std::vector<int> vec{ 4,3,5,4,3,3,6,7 };
	std::vector<int> res = GetMaxWindow(vec, 3);
	for (auto e : res)
		std::cout << e << ' ';
	system("pause");
	return 0;
}
#endif