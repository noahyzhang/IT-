#include<iostream>
#include<vector>

using namespace std;
#if 0
void AdjustArray(std::vector<int>& arr)
{
	if (arr.empty())
		return;
	size_t size = arr.size();
	size_t pos_count = 0, neg_count = 0; //正数数量，负数数量
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] >= 0)
			pos_count++;
		else
			neg_count++;
	}
	bool pre_pos = false; 
	if (pos_count > neg_count)
		pre_pos = true; //正数放前面

	int pTemp = 0;
	if (pre_pos == true)
	{
		if (arr[0] < 0)
		{
			while (arr[pTemp] < 0)
				++pTemp;
			std::swap(arr[0], arr[pTemp]);
		}
	}
	else
	{
		if (arr[0] > 0)
		{
			while (arr[pTemp] > 0)
				++pTemp;
			std::swap(arr[0], arr[pTemp]);
		}
	}

	int pPre = 0, pPost = 1;
	pTemp = pPost;
	while (pPost != size)
	{
		if (arr[pPre] >= 0)
		{
			if (arr[pPost] >= 0)
			{
				pTemp = pPost + 1;
				while (pTemp < size && arr[pTemp] >= 0)
					pTemp++;
				if (pTemp != size)
				{
					int num = arr[pTemp];
					for (int i = pTemp - 1; i >= pPost; --i)
					{
						arr[i + 1] = arr[i];
					}
					arr[pPost] = num;
				}
			}
			pPre++;
			pPost++;
		}
		else
		{
			if (arr[pPre] < 0)
			{
				if (arr[pPost] < 0)
				{
					pTemp = pPost + 1;
					while (pTemp < size && arr[pTemp] < 0 )
						pTemp++;
					if (pTemp != size)
					{
						int num = arr[pTemp];
						for (int i = pTemp - 1; i >= pPost; --i)
						{
							arr[i + 1] = arr[i];
						}
						arr[pPost] = num;
					}
				}
				pPre++;
				pPost++;
			}
		}
	}	
}

int main()
{
	std::vector<int> arr;
	//int num = 0;
	//while (std::cin >> num)
	//{
	//	arr.push_back(num);
	//}
	char num = '0';
	while (std::cin >> num)
	{
		if (num == '\r')
			break;
		arr.push_back(num - '0');
	}
	AdjustArray(arr);
	for (int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << ' ';
	std::endl(std::cout);
	return 0;
}
#endif
#if 0
class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		vector<int> leafSet;
		unordered_map<int, set<int>> hashTable;
		for (int i = 0; i < edges.size(); i++) {
			hashTable[edges[i].first].insert(edges[i].second);
			hashTable[edges[i].second].insert(edges[i].first);
		}
		for (int i = 0; i < hashTable.size(); i++) {
			if (hashTable[i].size() == 1) {
				leafSet.push_back(i);
			}
		}
		while (leafSet.size() > 2 || (leafSet.size() == 2 && *hashTable[leafSet[0]].begin() != leafSet[1])) {
			vector<int> newLeafSet;
			for (int i = 0; i < leafSet.size(); i++) {
				hashTable[*hashTable[leafSet[i]].begin()].erase(leafSet[i]);
				if (hashTable[*hashTable[leafSet[i]].begin()].size() == 1) {
					newLeafSet.push_back(*hashTable[leafSet[i]].begin());
				}
				hashTable[leafSet[0]].clear();
			}
			leafSet = newLeafSet;
		}
		if (n == 1) {
			leafSet = { 0 };
		}
		return leafSet;
	}
};
#endif
