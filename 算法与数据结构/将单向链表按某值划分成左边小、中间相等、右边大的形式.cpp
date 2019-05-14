#include<iostream>
#include<vector>

class Node {
public:
	int val;
	Node* next;

	Node(int _val = 0) : val(_val)
	{}

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

Node* listPartition1(Node* head, int pivot)
{
	if (head == nullptr)
		return head;
	std::vector<Node*> vec;
	Node* tmp = head;
	while (tmp != nullptr)
	{
		vec.push_back(tmp);
		tmp = tmp->next;
	}
	std::vector<Node*> res;
	res.resize(vec.size());
	int begin = 0, end = vec.size() - 1;
	for (int i = 0; i < vec.size(); ++i)
	{
		if (vec[i]->val <= pivot)
		{
			res[begin] = vec[i];
			begin++;
		}
		else
		{
			res[end] = vec[i];
			end--;
		}
	}
	for (int i = 0; i < res.size()-1; ++i)
	{
		res[i]->next = res[i + 1];
	}
	res[res.size() - 1]->next = nullptr;
	return res[0];
}

Node* listPartition2(Node* head, int pivot)
{
	if (head == nullptr)
		return head;
	Node* small = nullptr, *smallTmp = nullptr;
	Node* equal = nullptr, *equalTmp = nullptr;
	Node* big = nullptr, *bigTmp = nullptr;
	while (head != nullptr)
	{	
		if (head->val < pivot)
		{
			if (small == nullptr)
			{
				small = head;
				smallTmp = head;
			}
			else
			{
				smallTmp->next = head;
				smallTmp = smallTmp->next;
			}
		}
		else if (head->val == pivot)
		{
			if (equal == nullptr)
			{
				equal = head;
				equalTmp = head;
			}
			else
			{
				equalTmp->next = head;
				equalTmp = equalTmp->next;
			}
		}
		else
		{
			if (big == nullptr)
			{
				big = head;
				bigTmp = head;
			}
			else
			{
				bigTmp->next = head;
				bigTmp = bigTmp->next;
			}
		}
		head = head->next;
	}
	
	smallTmp->next = equal;
	if (equalTmp != nullptr)
		equalTmp->next = big;
	else
		smallTmp->next = big;
	bigTmp->next = nullptr;
	return small;
}

#if 0
int main()
{
	std::vector<int> vec{ 9,0,4,5,1 };
	Node node;
	Node* head = node.GetList(vec);
	//Node* res = listPartition1(head, 3);
	Node* res = listPartition2(head, 3);
	while (res != nullptr)
	{
		std::cout << res->val << " ";
		res = res->next;
	}
	system("pause");
	return 0;
}
#endif