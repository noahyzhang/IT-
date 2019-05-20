#include<iostream>
#include<vector>

class ListNode {
public:
	int _val;
	ListNode* _next;
	ListNode(int val = 0) : _val(val), _next(nullptr)
	{}
};

class List {
public:
	List(std::vector<int>& vec)
	{
		root = new ListNode(vec[0]);
		ListNode* tmp = root;
		for (int i = 1; i < vec.size(); ++i)
		{
			tmp->_next = new ListNode(vec[i]);
			tmp = tmp->_next;
		}
	}
	void DeleteDuplication(ListNode** pHead)
	{
		if (pHead == nullptr || *pHead == nullptr)
			return;
		ListNode* pPreNode = nullptr;
		ListNode* pNode = *pHead;

		while (pNode != nullptr)
		{
			ListNode* pNext = pNode->_next;
			bool needDelete = false;
			if (pNext != nullptr && pNext->_val == pNode->_val)
				needDelete = true;

			if (!needDelete)
			{
				pPreNode = pNode;
				pNode = pNode->_next;
			}
			else
			{
				int val = pNode->_val;
				ListNode* pToBeDel = pNode;
				while (pToBeDel != nullptr && pToBeDel->_val == val)
				{
					pNext = pToBeDel->_next;
					delete pToBeDel;
					pToBeDel = nullptr;
					pToBeDel = pNext;
				}
				if (pPreNode == nullptr)
					*pHead = pNext;
				else
					pPreNode->_next = pNext;
				pNode = pNext;
			}
		}
	}

private:
	ListNode* root;
};

