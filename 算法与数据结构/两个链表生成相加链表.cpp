#include<iostream>
#include<vector>

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

Node* ReverseList(Node* head)
{
	if (head == nullptr)
		return head;
	Node* pre = nullptr, *next = nullptr;
	while (head != nullptr)
	{
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	return pre;
}

Node* addList(Node* head1, Node* head2)
{
	if (head1 == nullptr)
		return head2;
	if (head2 == nullptr)
		return head1;
	head1 = ReverseList(head1);
	head2 = ReverseList(head2);
	int carry = 0;
	int count = 0;
	Node* newList = nullptr;
	Node* newTmp = nullptr;
	while (head1 != nullptr && head2 != nullptr)
	{
		count = head1->val + head2->val + carry;
		if (count > 9)
		{
			carry = count / 10;
			count = count % 10;
		}
		if (newList == nullptr)
		{
			newList = new Node(count);
			newTmp = newList;
		}
		else
		{
			newTmp->next = new Node(count);
			newTmp = newTmp->next;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
	while (head1 != nullptr)
	{
		count = head1->val + carry;
		if (count > 9)
		{
			carry = count / 10;
			count = count % 10;
		}
		if (newList == nullptr)
		{
			newList = new Node(count);
			newTmp = newList;
		}
		else
		{
			newTmp->next = new Node(count);
			newTmp = newTmp->next;
		}
		head1 = head1->next;
	}
	while (head2 != nullptr )
	{
		count = head2->val + carry;
		if (count > 9)
		{
			carry = count / 10;
			count = count % 10;
		}
		if (newList == nullptr)
		{
			newList = new Node(count);
			newTmp = newList;
		}
		else
		{
			newTmp->next = new Node(count);
			newTmp = newTmp->next;
		}
		head2 = head2->next;
	}
	if (carry != 0)
	{
		newTmp->next = new Node(carry);
	}
	newList = ReverseList(newList);
	return newList;
}

Node* addList2(Node* head1, Node* head2)
{
	head1 = ReverseList(head1);
	head2 = ReverseList(head2);
	int ca = 0;
	int n1 = 0, n2 = 0, n = 0;
	Node* c1 = head1, *c2 = head2, *node = nullptr, *pre = nullptr;
	while (c1 != nullptr || c2 != nullptr)
	{
		n1 = c1 != nullptr ? c1->val : 0;
		n2 = c2 != nullptr ? c2->val : 0;
		n = n1 + n2 + ca;
		pre = node;
		node = new Node(n % 10);
		node->next = pre;
		ca = n / 10;
		c1 = c1 != nullptr ? c1->next : nullptr;
		c2 = c2 != nullptr ? c2->next : nullptr;
	}
	if (ca != 0)
	{
		pre = node;
		node = new Node(ca);
		node->next = pre;
	}
	return node;
}

#if 0
int main()
{
	std::vector<int> vec1{ 9,3,7 };
	std::vector<int> vec2{ 6,3 };
	Node node;
	Node* head1 = node.GetList(vec1);
	Node* head2 = node.GetList(vec2);
	//Node* newList = addList(head1, head2);
	Node* newList = addList2(head1, head2);

	while (newList != nullptr)
	{
		std::cout << newList->val << " ";
		newList = newList->next;
	}
	system("pause");
	return 0;
}
#endif

