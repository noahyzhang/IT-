#include<iostream>
#include<list>
#include<vector>

class Node {
public:
	int value;
	Node* next;

	Node(int data = 0)
	{
		this->value = data;
		this->next = nullptr;
	}
	Node* GetList(std::vector<int>& vec)
	{
		Node* tmp = new Node(vec[0]);
		Node* head = tmp;
		Node* pre = nullptr;
		for (int i = 1;i < vec.size();++i)
		{
			pre = tmp;
			tmp = tmp->next;
			tmp = new Node(vec[i]);
			pre->next = tmp;
		}
		tmp->next = head;
		return head;
	}
};

Node* josephsKill(Node* head, int m)
{
	if (head == nullptr || head->next == head || m < 1)
		return head;
	while (head->next != head)
	{
		int count = m-2;
		while (count--)
		{
			head = head->next;
		}
		Node* tmp = head->next;
		head->next = tmp->next;
		delete tmp;
		tmp = nullptr;
	}
	return head;
}
#if 0
int main()
{
	Node node;
	std::vector<int> vec{ 1, 2, 3, 4, 5 };
	Node* head = node.GetList(vec);
	Node* res = josephsKill(head,3);
	std::cout << res->value << std::endl;
	system("pause");
	return 0;
}
#endif