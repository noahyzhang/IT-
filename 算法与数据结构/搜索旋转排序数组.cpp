#include<iostream>
#include<vector>

using namespace std;
#if 0
int find_rotate_index(vector<int>& nums, int left, int right)
{
	if (nums[left] < nums[right]) return 0;
	while (left <= right)
	{
		int pivot = left + right >> 1;
		if (nums[pivot] > nums[pivot + 1])
			return pivot + 1;
		else
			if (nums[pivot] < nums[left])
				right = pivot - 1;
			else
				left = pivot + 1;
	}
	return 0;
}

int search(vector<int>& nums, int left, int right,int target)
{
	while (left <= right)
	{
		int pivot = left + right >> 1;
		if (nums[pivot] == target)
			return pivot;
		else
			if (target < nums[pivot])
				right = pivot - 1;
			else
				left = pivot + 1;
	}
	return -1;
}

int search(vector<int>& nums, int target) 
{
	int n = nums.size();
	if (nums.empty()) return -1;
	if (nums.size() == 1)
		return nums[0] == target ? 0 : -1;

	int rotate_index = find_rotate_index(nums, 0, n - 1);

	if (nums[rotate_index] == target)
		return rotate_index;
	if (rotate_index == 0)
		return search(nums, 0, n - 1, target);
	if (nums[rotate_index] < nums[0])
		return search(nums, rotate_index, n - 1, target);
	return search(nums, 0, rotate_index, target);
}


int main()
{
	vector<int> num{1,3};
	int target = 3;
	int res = search(num, target);
	return 0;
}

#endif


class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty()) return -1;
		if (nums.size() == 1)
			return nums[0] == target ? 0 : -1;

		int n = nums.size();
		int rotate_index = find_rotate_index(nums, 0, n - 1);
		if (nums[rotate_index] == target)
			return rotate_index;
		if (rotate_index == 0)
			return search(nums, 0, n - 1, target);
		if (target < nums[0])
			return search(nums, rotate_index, n - 1, target);
		return search(nums, 0, rotate_index, target);
	}
private:
	int search(vector<int>& nums, int left, int right, int target)
	{
		while (left <= right)
		{
			int pivot = left + right >> 1;
			if (nums[pivot] == target)
				return pivot;
			else
				if (nums[pivot] > target)
					right = pivot - 1;
				else
					left = pivot + 1;
		}
		return -1;
	}
	int find_rotate_index(vector<int>& nums, int left, int right)
	{
		if (nums[left] < nums[right]) return 0;
		while (left <= right)
		{
			int pivot = left + right >> 1;
			if (nums[pivot] > nums[pivot + 1])
				return pivot + 1;
			else
				if (nums[pivot] < nums[left])
					right = pivot - 1;
				else
					left = pivot + 1;
		}
		return 0;
	}
};
#if
int main()
{
	Solution sn;
	vector<int> num{ 1,3 };
	int target = 3;
	int res = sn.search(num, target);
	return 0;
}
#endif