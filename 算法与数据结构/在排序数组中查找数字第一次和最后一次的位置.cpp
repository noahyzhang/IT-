
#include<vector>
#include<iostream>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int> res;
	if (nums.empty()) return res;
	int left = 0, right = nums.size() - 1, mid = 0, res_p = 0;
	while (left <= right)
	{
		mid = left + ((right - left) >> 1);
		if (target == nums[mid])
		{
			break;
		}
		else if (target > nums[mid])
			left = mid + 1;
		else if (target < nums[mid])
			right = mid - 1;
	}
	if (target == nums[mid])
		res_p = mid;
	else
	{
		res.push_back(-1);
		res.push_back(-1);
		return res;
	}
	while (res_p - 1 >= 0 && nums[res_p - 1] == target)
		res_p--;
	res.push_back(res_p);
		res_p++;
	res.push_back(res_p);
	return res;
}

#if 0
int main()
{
	vector<int> vec{ 1 ,4};
	vector<int> res = searchRange(vec,4);
	return 0;
}
#endif