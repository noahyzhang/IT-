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

void RemoveRep(Node*& head)
{
	std::set<Node*> st;
	while (head != nullptr)
	{
		st.insert(head);
		head = head->next;
	}
	for (auto it = st.begin(); it != st.end(); ++it)
	{
		(*it)->next = *(++it);
	}
		
}
