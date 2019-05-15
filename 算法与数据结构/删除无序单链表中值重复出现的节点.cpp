#include<iostream>
#include<vector>
#include<set>

class Node {
public:
	int val;
	Node* next;

	Node(int _val = 0) : val(_val)
	{
		next = nullptr;
	}

	Node* GetList(std::vector<int>& vec)
	{
		Node* tmp = new Node(vec[0]);
		Node* head = tmp;
		Node* pre = tmp;
		for (int i = 1; i < vec.size(); ++i)
		{
			pre = tmp;
			tmp = tmp->next;
			tmp = new Node(vec[i]);
			pre->next = tmp;
		}
		return head;
	}
};

Node* RemoveRep(Node*& head)
{
	std::set<int> st;
	Node* tmp = head;
	while (tmp != nullptr)
	{
		st.insert(tmp->val);
		tmp = tmp->next;
	}
	tmp = head;
	Node* pre = nullptr;
	for (auto it = st.begin(); it != st.end(); ++it)
	{
		tmp->val = *it;
		pre = tmp;
		tmp = tmp->next;
	}
	pre->next = nullptr;
	return head;
}

#if 0
int main()
{
	std::vector<int> vec{ 1,2,3,3,4,4,2,1,1 };
	Node node;
	Node* head = node.GetList(vec);
	head = RemoveRep(head);
	while (head != nullptr)
	{
		std::cout << head->val << " ";
		head = head->next;
	}
	system("pause");
	return 0;
}
#endif
