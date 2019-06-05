#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) 
{
	std::vector<std::vector<int>> res;
	if (nums.size() < 4) return res;
	std::sort(nums.begin(), nums.end());
	std::set<std::vector<int>> st;
	for (int i = 0; i < nums.size()-3; ++i)
	{
		if (nums[i] > target && target > 0) break;
		for (int j = i + 1; j < nums.size() - 2; ++j)
		{
			int left = j + 1, right = nums.size() - 1;
			while (left < right)
			{
				int tmp = nums[i] + nums[j] + nums[left] + nums[right];
				if (tmp < target)
					left++;
				else if (tmp > target)
					right--;
				else
				{
					st.insert({ nums[i],nums[j],nums[left],nums[right] });
					left++;
					right--;
				}
			}

		}
	}
	for (auto e : st)
	{
		res.push_back(e);
	}
	return res;
}

#if 0
int main()
{
	std::vector<int> nums{ 1,0,-1,0,-2,2 };
	std::vector<std::vector<int>> res = fourSum(nums, 0);
	return 0;
}
#endif