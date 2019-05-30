#include<iostream>
#include<stack>
#include<string>
using namespace std;
#if 0
bool Check(std::string& input, std::string& output)
{
	std::stack<char> st;
	int i = 0, j = 0;
	int in_size = input.size(), out_size = output.size();
	while(i < in_size || j < out_size || !st.empty())
	{
		if (i < in_size && j < out_size && (input[i] != output[j] || st.empty() || (!st.empty() && input[i] != st.top())))
		{
			st.push(input[i]);
			++i;
		}
		else if (i < in_size && j < out_size && input[i] == output[j])
		{
			++j;
			++i;
		}
		else if (!st.empty() && output[j] == st.top())
		{
			st.pop();
			++j;
		}
	}
	if (st.empty())
		return true;
	return false;
}

bool Check1(std::string& input, std::string& output)
{
	std::stack<int> st;
	int i = 0, j = 0;
	int in_size = input.size(), out_size = output.size();
	st.push(input[i++]);
	while (i < in_size || !st.empty())
	{
		if (!st.empty() && st.top() == output[j])
		{
			st.pop();
			++j;
		}
		else
		{
			st.push(input[i++]);
		}
	}
	if (st.empty())
		return true;
	return false;
}

bool isPossible(int in[], int out[], int n)
{
	if (n <= 0)
		return false;
	stack<int> s;
	int i, j;
	i = j = 0;
	while (j < n)
	{
		while (s.empty() || s.top() != out[j])
		{
			if (i == n)
				break;
			s.push(in[i++]);
		}
		if (s.empty() || s.top() != out[j])
			break;
		s.pop();
		j++;
	}

	if (s.empty() && j == n)
		return true;
	return false;
}


int main()
{
	int num = 0;
	std::cin >> num;
	getchar();
	std::string input, output;
	for (int i = 0; i < num; ++i)
	{
		getline(std::cin, input);
		getline(std::cin, output);
		if (Check1(input, output))
			std::cout << "Y" << std::endl;
		else
			std::cout << "N" << std::endl;
	}
	return 0;
}

#endif





