#include<iostream>
#include<string>

void ReplaceBlank(std::string& str)
{
	int blank = 0;
	for (int i = 0; i < str.length(); ++i)
		if (str[i] == ' ')
			blank++;
	int p1 = str.length();
	int p2 = str.length() + blank * 2 - 1;
	str.resize(p2 + 1);
	int j = p2;
	str[p2] = '\0';
	for (int i = p1 - 1; i >= 0; --i)
	{
		if (str[i] != ' ')
		{
			str[j--] = str[i];
		}
		else
		{
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
		}
	}
}
#if 0
int main()
{
	std::string str("we are happy. ");
	ReplaceBlank(str);
	std::cout << str << std::endl;
	system("pause");
	return 0;
}
#endif