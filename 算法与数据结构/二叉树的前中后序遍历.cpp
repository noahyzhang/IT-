#include<iostream>
#include<vector>
#include<stack>

class Node {
public:
	int val;
	Node* pLeft;
	Node* pRight;

public:
	Node(int _val = 0) : val(_val)
	{
		pLeft = nullptr;
		pRight = nullptr;
	}

	Node* GetBinTree(std::vector<int>& vec) // 前序方法,用0来表示空
	{
		Node* root = new Node(vec[0]);
		Node* rootTmp = root;
		int i = 0;
		std::stack<Node*> st;
		st.push(rootTmp);
		while (i < vec.size() - 1) //i=1
		{
			if (vec[i] != 0)
			{
				i++;
				if (vec[i] != 0)
				{
					rootTmp->pLeft = new Node(vec[i]);
					rootTmp = rootTmp->pLeft;
					st.push(rootTmp);
				}
				else
					rootTmp->pLeft = nullptr;
			}
			if (vec[i] == 0 && !st.empty())
			{
				rootTmp = st.top();
				st.pop();
				i++;
				if (vec[i] != 0)
				{
					rootTmp->pRight = new Node(vec[i]);
					rootTmp = rootTmp->pRight;
					st.push(rootTmp);
				}
				else
					rootTmp->pRight = nullptr;
			}
		}
		return root;
	}
};



std::vector<int> preOrder(Node* head)
{
	std::vector<int> vec;
	std::stack<Node*> st;
	if (head == nullptr)
		return vec;
	st.push(head);
	while (!st.empty())
	{
		head = st.top();
		st.pop();
		vec.push_back(head->val);
		if (head->pRight != nullptr)
			st.push(head->pRight);
		if (head->pLeft != nullptr)
			st.push(head->pLeft);
	}
	return vec;
}

std::vector<int> InOrder(Node* head)
{
	std::vector<int> vec;
	std::stack<Node*> st;
	if (head == nullptr)
		return vec;
	while (!st.empty() || head != nullptr)
	{
		if (head != nullptr)
		{
			st.push(head);
			head = head->pLeft;
		}
		else
		{
			head = st.top();
			st.pop();
			vec.push_back(head->val);
			head = head->pRight;
		}
	}
	return vec;
}

std::vector<int> PostOrder(Node* head)
{
	std::vector<int> vec;
	std::stack<Node*> st1, st2;
	if (head == nullptr)
		return vec;
	st1.push(head);
	while (!st1.empty())
	{
		head = st1.top();
		st1.pop();
		st2.push(head);
		if (head->pLeft != nullptr)
			st1.push(head->pLeft);
		if (head->pRight != nullptr)
			st1.push(head->pRight);
	}
	while (!st2.empty())
	{
		vec.push_back(st2.top()->val);
		st2.pop();
	}
	return vec;
}
#if 0
int main()
{
	Node node;
	std::vector<int> vec{ 1,2,4,0,0,5,0,0,3,6,0,0,0};
	Node* head = node.GetBinTree(vec);
	std::vector<int> res;
	
	res = preOrder(head);
	for (auto e : res)
		std::cout << e << " ";
	std::cout << std::endl;

	res = InOrder(head);
	for (auto e : res)
		std::cout << e << " ";
	std::cout << std::endl;

	res = PostOrder(head);
	for (auto e : res)
		std::cout << e << " ";
	std::cout << std::endl;

	system("pause");
	return 0;
}
#endif