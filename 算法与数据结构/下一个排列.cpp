#include<iostream>
#include<vector>

using namespace std;


void nextPermutation(std::vector<int>& nums)
{
	int i = nums.size() - 2;
	while (i >= 0 && nums[i + 1] <= nums[i])
		i--;
	if (i >= 0)
	{
		int j = nums.size() - 1;
		while (j >= 0 && nums[j] <= nums[i])
			j--;
		std::swap(nums[i], nums[j]);
	}
	std::reverse(nums.begin() + i + 1, nums.end());
}
#if 0
int main()
{
	std::vector<int> num{ 1,2,3 };
	nextPermutation(num);
	return  0;
}
#endif