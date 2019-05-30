//#include<vector>
//#include<string>
//#include<iostream>
//
//std::string comm = "0123456789abcdefghijklmn";
//
//long long int Reverse(std::string& str)
//{
//	long long int res = 0;
//	long long count = 1;
//	for (int i = str.size() - 1; i >= 0; --i)
//	{
//		if (str[i] >= '0' && str[i] <= '9')
//			res += (str[i] - '0')*count;
//		else
//			res += ((str[i] - 'a') + 10)*count;
//		count *= 24;
//	}
//	return res;
//}
//
//int main()
//{
//	int t;
//	std::cin >> t;
//	getchar();
//	std::string str;
//	for (int i = 0; i < t; ++i)
//	{
//		getline(std::cin, str);
//		long long int res = Reverse(str);
//		std::cout << res << std::endl;
//	}
//	return 0;
//}