#include<stack>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#if 0
class BinaryTreeNode {
public:
	BinaryTreeNode(int val = 0)
		: _val(val)
		, _pLeft(nullptr)
		, _pRight(nullptr)
	{}

	int _val;
	BinaryTreeNode* _pLeft;
	BinaryTreeNode* _pRight;
};

typedef BinaryTreeNode BTNode;

BTNode* CreateBTree(std::vector<int>& vec)
{
	BTNode* root = new BinaryTreeNode(vec[0]);
	std::stack<BTNode*> st;
	st.push(root);
	BTNode* tmp = root;
	int i = 0;
	while ( i < vec.size() - 1)
	{
		if (vec[i] != 0)
		{
			i++;
			if (vec[i] != 0)
			{
				tmp->_pLeft = new BinaryTreeNode(vec[i]);
				tmp = tmp->_pLeft;
				st.push(tmp);
			}
			else
				tmp->_pLeft = nullptr;
		}

		if (vec[i] == 0 && !st.empty())
		{
			tmp = st.top();
			st.pop();
			i++;
			if (vec[i] != 0)
			{
				tmp->_pRight = new BinaryTreeNode(vec[i]);
				tmp = tmp->_pRight;
				st.push(tmp);
			}
			else
				tmp->_pRight = nullptr;
		}
	}
	return root;
}

void PreOrder(BTNode* root)
{
	std::stack<BTNode*> st;
	BTNode* tmp = root;
	st.push(tmp);
	while (!st.empty())
	{
		tmp = st.top();
		st.pop();
		std::cout << tmp->_val << ' ';
		if (tmp->_pRight != nullptr)
			st.push(tmp->_pRight);
		if (tmp->_pLeft != nullptr)
			st.push(tmp->_pLeft);
	}
	std::cout << std::endl;
}

void InOrder(BTNode* root)
{
	std::stack<BTNode*> st;
	while (!st.empty() || root != nullptr)
	{
		if (root != nullptr)
		{
			st.push(root);
			root = root->_pLeft;
		}
		else
		{
			root = st.top();
			st.pop();
			std::cout << root->_val << ' ';
			root = root->_pRight;
		}
	}
	std::cout << std::endl;
}

void PostOrder(BTNode* root)
{
	if (root == nullptr)
		return;
	std::stack<BTNode*> st1, st2;
	st1.push(root);
	while (!st1.empty())
	{
		BTNode* root = st1.top();
		st1.pop();
		st2.push(root);
		if (root->_pLeft != nullptr)
			st1.push(root->_pLeft);
		if (root->_pRight != nullptr)
			st1.push(root->_pRight);
	}
	while (!st2.empty())
	{
		std::cout << st2.top()->_val << ' ';
		st2.pop();
	}
	std::cout << std::endl;
}

void LevelOrder(BTNode* root)
{
	if (root == nullptr)
		return;
	std::queue<BTNode*> qu;
	qu.push(root);
	while (!qu.empty())
	{
		root = qu.front();
		qu.pop();
		std::cout << root->_val << ' ';
		if (root->_pLeft != nullptr)
			qu.push(root->_pLeft);
		if (root->_pRight != nullptr)
			qu.push(root->_pRight);
	}
	std::cout << std::endl;
}

void LevelOrderUpdate(BTNode* root)
{
	if (root == nullptr)
		return;
	int curLevelCount = 1, NextLevelCount = 0;
	std::queue<BTNode*> qu1, qu2;
	qu1.push(root);
	while (!qu1.empty())
	{
		root = qu1.front();
		qu1.pop();
		std::cout << root->_val << ' ';
		curLevelCount--;
		if (root->_pLeft != nullptr)
		{
			qu1.push(root->_pLeft);
			NextLevelCount++;
		}
		if (root->_pRight != nullptr)
		{
			qu1.push(root->_pRight);
			NextLevelCount++;
		}
		if (0 == curLevelCount)
		{
			std::endl(std::cout);
			curLevelCount = NextLevelCount;
			NextLevelCount = 0;
		}
	}
}

int main()
{
	std::vector<int> vec{ 1,2,4,0,0,5,0,0,3,6,0,0,0 };
	BTNode* root = CreateBTree(vec);

	//PreOrder(root);
	//InOrder(root);
	//PostOrder(root);
	//LevelOrder(root);
	LevelOrderUpdate(root);
	system("pause");
	return 0;
}
#endif
class BinTreeNode {
public:
	BinTreeNode* _pLeft;
	BinTreeNode* _pRight;
	int _val;

	BinTreeNode(int val = 0) : _val(val),_pLeft(nullptr),_pRight(nullptr)
	{}

};


class BinaryTree {
public:
	BinaryTree()
	{}

	 BinTreeNode* CreateTree(std::vector<int>& vec)  // 前序创建二叉树 根左右
	{
		std::stack<BinTreeNode*> st;
		root = new BinTreeNode(vec[0]);
		BinTreeNode* tmp = root;
		st.push(root);
		int i = 0;
		while (i < vec.size() - 1)
		{
			if (vec[i] != 0)
			{
				i++;
				if (vec[i] != 0)
				{
					tmp->_pLeft = new BinTreeNode(vec[i]);
					tmp = tmp->_pLeft;
					st.push(tmp);
				}
				else
					tmp->_pLeft = nullptr;
			}
			if (vec[i] == 0 && !st.empty())
			{
				i++;
				tmp = st.top();
				st.pop();
				if (vec[i] != 0)
				{
					tmp->_pRight = new BinTreeNode(vec[i]);
					tmp = tmp->_pRight;
					st.push(tmp);
				}
				else
					tmp->_pRight = nullptr;
			}
		}
		return root;
	 }

	 void PreOrder()
	 {
		 BinTreeNode* tmp = nullptr;
		 std::stack<BinTreeNode*> st;
		 st.push(root);
		 while (!st.empty())
		 {
			 tmp = st.top();
			 st.pop();
			 std::cout << tmp->_val << ' ';
			 if (tmp->_pRight != nullptr)
				 st.push(tmp->_pRight);
			 if (tmp->_pLeft != nullptr)
				 st.push(tmp->_pLeft);
	      } 
		 std::cout << std::endl;
	 }

	 void InOrder()
	 {
		 BinTreeNode* tmp = root;
		 std::stack<BinTreeNode*> st;
		 while (!st.empty() || tmp != nullptr)
		 {
			 if (tmp != nullptr)
			 {
				 st.push(tmp);
				 tmp = tmp->_pLeft;
			 }
			 else
			 {
				 tmp = st.top();
				 st.pop();
				 std::cout << tmp->_val << ' ';
				 tmp = tmp->_pRight;
			 }
		 }
		 std::cout << std::endl;
	 }

	 void PostOrder()
	 {
		 BinTreeNode* tmp = root;
		 std::stack<BinTreeNode*> st1, st2;
		 st1.push(root);
		 while (!st1.empty())
		 {
			 tmp = st1.top();
			 st1.pop();
			 st2.push(tmp);
			 if (tmp->_pLeft != nullptr)
				 st1.push(tmp->_pLeft);
			 if (tmp->_pRight != nullptr)
				 st1.push(tmp->_pRight);
		 }
		 while (!st2.empty())
		 {
			 std::cout << st2.top()->_val << ' ';
			 st2.pop();
		 }
		 std::cout << std::endl;
	 }

	 void LevelOrder()
	 {
		 BinTreeNode* tmp = root;
		 std::queue<BinTreeNode*> qu;
		 int curNum = 1, nextNum = 0;
		 qu.push(root);
		 while (!qu.empty())
		 {
			 tmp = qu.front();
			 qu.pop();
			 std::cout << tmp->_val << ' ';
			 curNum--;
			 if (tmp->_pLeft != nullptr)
			 {
				 qu.push(tmp->_pLeft);
				 nextNum++;
			 }
			 if (tmp->_pRight != nullptr)
			 {
				 qu.push(tmp->_pRight);
				 nextNum++;
			 }
			 if (curNum == 0)
			 {
				 std::cout << std::endl;
				 curNum = nextNum;
				 nextNum = 0;
			 }
		 }
		 std::cout << std::endl;
	 }

private:
	BinTreeNode* root;
};

#if 0
int main()
{
	std::vector<int> vec{ 10,6,4,0,0,8,0,0,14,12,0,0,16,0,0 };
	BinaryTree bt;
	BinTreeNode* root = bt.CreateTree(vec);
	bt.PreOrder();
	bt.InOrder();
	bt.PostOrder();

	bt.LevelOrder();
	return 0;
}
#endif