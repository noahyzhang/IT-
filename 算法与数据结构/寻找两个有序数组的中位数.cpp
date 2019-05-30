#include<vector>
#include<iostream>
using namespace std;
#if 0
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size(), len2 = nums2.size();
		int len = len1 + len2;
		bool flag = false;
		int mid = (len % 2 == 0) ? (flag = true, len / 2) : (flag = false, len / 2);
		int s1 = 0, s2 = 0;
		double num = 0.0;
		std::vector<int> res;
		for (int i = 0; i <= mid; ++i)
		{
			if (s1 < len1 && s2 < len2)
			{
				if (nums1[s1] < nums2[s2])
					res.push_back(nums1[s1++]);
				else if (nums1[s1] >= nums2[s2])
					res.push_back(nums2[s2++]);
			}
			else
			{
				if (s1 >= len1 && s2 < len2)
					res.push_back(nums2[s2++]);
				if (s2 >= len2 && s1 < len1)
					res.push_back(nums1[s1++]);
			}
		}
		if (flag == false)
		{
			num = res[res.size()-1];
		}
		else
		{
			num = (res[res.size() - 1] + res[res.size() - 2]) / 2.0;
		}
		return num;
	}
};


int main()
{
	std::vector<int> v1{ 1 };
	std::vector<int> v2{ 1 };
	Solution s;
	double res = s.findMedianSortedArrays(v1, v2);
	std::cout << res << std::endl;
	return 0;
}
#endif