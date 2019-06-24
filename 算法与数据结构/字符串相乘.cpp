#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string multiply(string num1, string num2)
{
	string res;
	vector<int> tmp;
	vector<int> total_data;
	if (num1.empty() || num2.empty()) return res;
	if (num1[0] == '0' || num2[0] == '0')
	{
		res.push_back('0');
		return res;
	}
	int mul_data = 0, high_order_data = 0, m = 0, n = 0;
	int add_data = 0, high_order_num = 0;
	int amount = -1;
	for (int i = num2.size() - 1; i >= 0; --i)
	{
		amount++;
		tmp.resize(0);
		high_order_data = 0;
		high_order_num = 0;
		for (int j = num1.size() - 1; j >= 0; --j)
		{
			mul_data = (num2[i]-'0') * (num1[j]-'0') + high_order_data;
			tmp.push_back((mul_data % 10));
			high_order_data = mul_data / 10;
		}
		if (high_order_data != 0)
			tmp.push_back(high_order_data);
		int tmp_amount = amount;
		reverse(tmp.begin(), tmp.end());
		while (tmp_amount--)
			tmp.push_back(0);
		reverse(tmp.begin(), tmp.end());

		for (m = 0, n = 0; m < total_data.size() && n < tmp.size(); m++, n++)
		{
			add_data = total_data[m] + tmp[n] + high_order_num;
			total_data[m] = add_data % 10;
			high_order_num = add_data / 10;
		}
		if (m == total_data.size() && n == tmp.size())
		{
			if (amount == 0)
			{
				for (int i = 0; i < tmp.size(); ++i)
					total_data.push_back(tmp[i]);
			}
			if (high_order_num != 0)
				total_data.push_back(high_order_num);
		}
		else if (m < total_data.size())
		{
			++m;
			add_data = total_data[m] + high_order_num;
			total_data[m] = add_data % 10;
			if (add_data / 10 != 0)
			{
				if (m + 1 < total_data.size())
					total_data[m + 1] = add_data / 10;
				else
					total_data.push_back(add_data / 10);
			}
		}
		else if (n < tmp.size())
		{
			for (int k = n; k < tmp.size(); ++k)
			{
				add_data = tmp[k] + high_order_num;
				total_data.push_back(add_data % 10);
				high_order_num = add_data / 10;
			}
			if (high_order_num != 0)
				total_data.push_back(high_order_num);
		}
	}
	for (int i = total_data.size() - 1; i >= 0; --i)
		res.push_back(total_data[i] + '0');
	return res;
}

#if 0
int main()
{
	string num1 = "123", num2 = "456";
	string res = multiply(num1, num2);
	return 0;
}
#endif