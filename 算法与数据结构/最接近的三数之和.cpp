#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int ans = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < nums.size(); ++i)
		{
			int start = i + 1, end = nums.size() - 1;
			while (start < end)
			{
				int tmp = nums[start] + nums[end] + nums[i];
				if (std::abs(tmp - target) < std::abs(ans - target))
					ans = tmp;
				else if (tmp > target)
					end--;
				else if (tmp < target)
					start++;
				else
					return ans;
			}
		}
		return ans;
	}
};
#if 0
int main()
{
	std::vector<int> nums{ -3,-2,-5,3,-4 };
	Solution sn;
	int res = sn.threeSumClosest(nums, -1);
	std::cout << res << std::endl;
	return 0;
}
#endif