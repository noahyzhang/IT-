#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode* List(vector<int>& vec)
	{
		ListNode* head = new ListNode(vec[0]);
		ListNode* tmp = head;
		for (int i = 1; i < vec.size(); ++i)
		{
			tmp->next = new ListNode(vec[i]);
			tmp = tmp->next;
		}
		return head;
	}
};


 
class Solution {

public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<int,vector<int>,greater<int>> pri_qu;
		for (int i = 0; i < lists.size(); ++i)
		{
			ListNode* tmp = lists[i];
			while (tmp != nullptr)
			{
				pri_qu.push(tmp->val);
				tmp = tmp->next;
			}
		}
		ListNode* head = new ListNode(0);
		ListNode* tmp_head = head;
		while (!pri_qu.empty())
		{
			tmp_head->next = new ListNode(pri_qu.top());
			tmp_head = tmp_head->next;
			pri_qu.pop();
		}
		return head->next;
	}
};
#if 0
int main()
{
	ListNode ln(0);
	vector<ListNode*> vec;
	vector<int> tmp{ 1,4,5 };
	ListNode* str = ln.List(tmp);
	vec.push_back(str);
	tmp={ 1,3,4 };
	str = ln.List(tmp);
	vec.push_back(str);
	tmp = { 2,6 };
	str = ln.List(tmp);
	vec.push_back(str);

	Solution sn;
	ListNode* res = sn.mergeKLists(vec);
	while (res != nullptr)
	{
		std::cout << res->val << std::endl;
		res = res->next;
	}

	return 0;
}
#endif