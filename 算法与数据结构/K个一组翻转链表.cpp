#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == nullptr)  return nullptr;
		std::stack<ListNode*> st;
		int count = k, i = 0;
		ListNode* rootHead = head;
		ListNode* res = new ListNode(0);
		ListNode* resTmp = res;
		while (rootHead != nullptr) 
		{
			count = k;
			for (i = 0; i < count && rootHead != nullptr; ++i)
			{
				st.push(rootHead);
				rootHead = rootHead->next;
			}
			if (i == count)
			{
				while (!st.empty())
				{
					resTmp->next = st.top();
					st.pop();
					resTmp = resTmp->next;
				}
			}
			else if(rootHead == nullptr)
			{
				std::stack<ListNode*> st2;
				while (!st.empty())
				{
					st2.push(st.top());
					st.pop();
				}
				while (!st2.empty())
				{
					resTmp->next = st2.top();
					st2.pop();
					resTmp = resTmp->next;
				}
			}
		}
		resTmp->next = nullptr;
		return res->next;
	}
};

#if 0
int main()
{
	Solution sn;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	ListNode* res = sn.reverseKGroup(head,2);
	return 0;
}
#endif