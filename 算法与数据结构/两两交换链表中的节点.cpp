#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

 struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* FakeHeadNode = new ListNode(0);
		FakeHeadNode->next = head;
		ListNode* preNode = FakeHeadNode, *leftNode = preNode->next, *rightNode = leftNode->next, *endNode = rightNode->next;
		while (1)
		{
			rightNode->next = leftNode;
			leftNode->next = endNode;
			preNode->next = rightNode;
			if (endNode == nullptr || endNode->next == nullptr)
				break;
			preNode = leftNode;  //ÖØµã
			leftNode = preNode->next;
			rightNode = leftNode->next;
			endNode = rightNode->next;
		}
		return FakeHeadNode->next;
	}
};
#if 0
int main()
{
	Solution sn;
	ListNode* head = new ListNode(0);
	ListNode* tmp = head;
	std::vector<int> vec{ 1,2,3,4 };
	int i = 0;
	while (i < vec.size())
	{
		tmp->next = new ListNode(vec[i]);
		tmp = tmp->next;
		++i;
	}
	ListNode* res = sn.swapPairs(head->next);
	return 0;
}
#endif