#include<iostream>
#include<vector>

class Node {
public:
	int val;
	Node* next;

	Node(int _value = 0)
	{
		val = _value;
		next = nullptr;
	}

	Node* GetList(std::vector<int>& vec)
	{
		Node* tmp = new Node(vec[0]);
		Node* head = tmp;
		Node* pre = tmp;
		for (size_t i = 1; i < vec.size(); ++i)
		{
			pre = tmp;
			tmp = tmp->next;
			tmp = new Node(vec[i]);
			pre->next = tmp;
		}
		return head;
	}
};

bool IsPalindrome(Node* head)
{
	if (head == nullptr || head->next == nullptr)
		return true;
	Node* n1 = head;
	Node* n2 = head;
	Node* n3 = nullptr;
	while (n2->next != nullptr && n2->next->next != nullptr)
	{
		n1 = n1->next;
		n2 = n2->next->next;
	}
	n2 = n1->next;
	n1->next = nullptr;
	while (n2 != nullptr)
	{
		n3 = n2->next;
		n2->next = n1;
		n1 = n2;
		n2 = n3;
	}
	n3 = n1;
	n2 = head;
	bool res = true;
	while (n1 != nullptr && n2 != nullptr)
	{
		if (n1->val != n2->val)
		{
			res = false;
			break;
		}
		n1 = n1->next;
		n2 = n2->next;
	}
	n1 = n3->next;
	n3->next = nullptr;
	while (n1 != nullptr)
	{
		n2 = n1->next;
		n1->next = n3;
		n3 = n1;
		n1 = n2;
	}
	return res;
}

#if 0
int main()
{
	Node node;
	std::vector<int> vec{ 1,2,3,4,3,2,1,9 };
	Node* head = node.GetList(vec);
	bool res = IsPalindrome(head);
	std::cout << res << std::endl;
	system("pause");
	return 0;
}
#endif