#include<iostream>
#include<vector>

class ListNode {
public:
	int _val;
	ListNode* _next;
	ListNode(int val = 0): _val(val),_next(nullptr)
	{}
};

ListNode* CreateList(std::vector<int>& vec)
{
	ListNode* root = nullptr;
	if (vec.empty())
		return root;
	root = new ListNode(vec[0]);
	ListNode* tmp = root;
	for (int i = 1; i < vec.size(); ++i)
	{
		tmp->_next = new ListNode(vec[i]);
		tmp = tmp->_next;
	}
	return root;
}

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if (pListHead == nullptr || k < 1)
		return nullptr;
	ListNode* pAhead = pListHead;
	ListNode* pBegin = nullptr;

	for (unsigned int i = 0; i < k - 1; ++i)
	{
		if (pAhead->_next != nullptr)
			pAhead = pAhead->_next;
		else
			return nullptr;
	}
	pBegin = pListHead;
	while (pAhead->_next != nullptr)
	{
		pAhead = pAhead->_next;
		pBegin = pBegin->_next;
	}
	return pBegin;
}

#if 0
int main()
{
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	ListNode* root = CreateList(vec);
	ListNode* node = FindKthToTail(root,5);
	std::cout << node->_val << std::endl;
	return 0;
}
#endif